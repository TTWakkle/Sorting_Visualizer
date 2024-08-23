//Author:                 Taha Twakkal
//Date:                   2024/01/16 -- 2023/09/20
//Description:            This function allows the user to randomly generate 
//a set of data, or manually input data of a set size, this is stored as an
//array in DM, which the address of is then returned to the user.
#include "mainHeader.h"
#include <stdint.h>

//Switch block that determines how data will be generated, either randomly or manually, and the size of the data set
    int generate(char dataType, int dataSetSize, DOUBLY_LIST* dataList){
        //Declaring and initalizing local variables
            char* userIn;
            int userArrSize;
            char returnCharacter;
            _Bool validInput = 0;
        //determining wheter the data is to be inputted or generated randomly
            do {
                //getting user input
                    printf("\nPlease select wheter you would like to generate a random array(\"R\") of data or input it manually(\"M\")");
                    inputCharacter(&userIn);
                //Checking if the input is acceptable
                    if(strlen(userIn) > strlen("T\0")){
                        printf("\nYou have entered too many characters, please try again!");
                        validInput = 0;
                        free(userIn);
                    }
                    else{
                        returnCharacter = *userIn;
                        free(userIn);
                        userIn = NULL;
                        if((int)returnCharacter > 96 && (int)returnCharacter < 123){                       //ASCII 97 is a, 122 is z
                            returnCharacter = (char)((int)returnCharacter - 32);                           //this simply capitalizes the user's input 
                        }
                        switch (returnCharacter){
                        case 'R':
                            printf("\nYou have chosen to have the program generate a random array of data");
                            validInput = 1;
                            break;
                        case 'M':
                            printf("\nYou have chosen to input an array of data manually.");
                            validInput = 1;
                            break;
                        default:
                            printf("\n%s is not recognized as an option, please try again: ", returnCharacter);
                            validInput = 0;
                            break;
                        }
                    }
            } while (!validInput);

        

        //function calls based on the user's decisions
            switch (returnCharacter) {
            case 'M':
                insertItems(dataType, dataList);
                break;
            case 'R':
                //determining the size of the array of data that is to be sorted
                    printf("\nPlease determine the size of the data set you would like to have sorted: ");
                    userArrSize = inputInteger();

                generateItems(dataType, userArrSize, dataList);
                break;
            default:
                printf("\ncompilation error, please try again\n");
                return -1;
            }
        return 1;
    }

//This function generates data through a randomizer, and stores them in the provided doubly list
    void generateItems(char dataType, int userArrSize, DOUBLY_LIST* dataList){
        //setting the seed of rand() based on compilation time to reduce pseudo-random number generation
            srand((intmax_t)time(NULL));

        //Generating the user-specified number of data items based on the data type, then inserting;
            for (int i = 0; i < userArrSize; i++) {
                switch (dataType){
                    case 'C': 
                        char* newData = (char*)malloc(sizeof(char));
                        *newData = (char)(rand() % (26) + 65);       //26 is derived from the range of upper case ASCII characters: 90 - 65 + 1, from A to Z basically
                        insert(dataList, (void*)newData);
                        free(newData);
                    break;
                    case 'A':
                        char* newData = (char*)calloc(userArrSize, sizeof(char));
                        *newData = (char)(rand() % (26) + 65);
                        insert(dataList, (void*)newData);
                        free(newData);
                    break;
                    case 'I':
                        int* newData = (int*)malloc(sizeof(int));
                        *newData = rand();
                        insert(dataList, (void*)newData);
                        free(newData);
                    break;
                } 
            }
    }

//This function requests data from the user, and stores them in the provided doubly list
    int insertItems(char dataType, DOUBLY_LIST* dataList){
        //declaring and initializing local variables
            char* userIn;
            char c;
        //getting user input, until the user has terminated the function
            printf(
                "\nYou are now manually entering in your data, you may add as many items a you would like."
                "\nOnce you are satisfied, simply input \";\" to terminate the insertion process."
            );
            do {
                printf("\nPlease enter ");
                switch (dataType) {
rePromptC:;          case 'C':
                        printf("a character: ");
                        //getting user input
                            inputCharacter(&userIn);
                        //Checking if the input is acceptable
                            if(strlen(userIn) > strlen("T\0")){
                                printf("\nYou have entered too many characters, please try again!");
                                free(userIn);
                                userIn = NULL;
                                goto rePromptC;
                            }
                            else{           //inserting the character into doubly list
                                c = *userIn;
                                insert(dataList, (void*)userIn);
                                free(userIn);
                                userIn = NULL;
                                if((int)c > 96 && (int)c < 123){                       //ASCII 97 is a, 122 is z
                                    c = (char)((int)c - 32);                           //this simply capitalizes the user's input 
                                }
                            }
                    break;
rePromptA:;         case 'A':
                        printf("a set of asterisks: ");
                        //getting user input
                            inputCharacter(&userIn);
                        //validating that all characters inserted are asterisks
                            for(int i = 0; i < strlen(userIn); i++){
                                if((((int)*(userIn+i)) != 42) && (((int)*(userIn+i)) != 59)){
                                    printf("\n%s is not a valid asterisks bar, it must contain ONLY \"*\". Please try again.");
                                    free(userIn);
                                    userIn = NULL;
                                    goto rePromptA;
                                }
                            }
                        //inserting the asterisk bar into doubly list;
                            c = strlen(userIn) > strlen("T\0") ? ' ' : *userIn; 
                            insert(dataList, (void*)userIn);
                            free(userIn);
                            userIn = NULL;
                    break;
                    case 'I':
                        printf("a positive, whole integer: ");
                        //DIALV
                            int* num = (int*)malloc(sizeof(int));
                        //getting user input
                            *num = inputInteger();
                            c = *num == -1 ? ' ' : ';';         //if the user enters ;, its assigned to c right away
                        //inserting the number into doubly list
                            if(c == ' '){
                                insert(dataList,(void*)num);
                                free(num);
                            }
                    break;
                }
            } while (c != ";");
            
    }