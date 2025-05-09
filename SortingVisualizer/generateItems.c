//Author:                 Taha Twakkal
//Date:                   2024/01/16 -- 2025/04/09
//Description:            This function allows the user to randomly generate 
//a set of data, or manually input data of a set size, this is stored as an
//array in DM, which the address of is then returned to the user.
#include "mainHeader.h"


//Switch block that determines how data will be generated, either randomly or manually, and the size of the data set
    int generate(char dataType, DOUBLY_LIST* dataList){
        //Declaring and initalizing local variables
            char* userIn;
            int userArrSize;
            char returnCharacter;
            _Bool validInput = 0;
            dataList->dataType = dataType;
        //determining wheter the data is to be inputted or generated randomly
            do {
                //getting user input
                    printf(
                        EC_TXT_CYN
                        "\nPlease select wheter you would like to generate a random array(\"R\") of data or input it manually(\"M\"): "
                        EC_TXT_WHT
                    );
                    userIn = inputCharacter();
                //Checking if the input is acceptable
                    if(strlen(userIn) > strlen("T\0")){
                        printf(
                            EC_TXT_YEL
                            "\nYou have entered too many characters, please try again!"
                            EC_DEF
                        );
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
                            printf(
                                EC_TXT_GRN
                                "\nYou have chosen to have the program generate a %s%srandom%s%s array of data",
                                EC_TXT_BLU, EC_UND, EC_DEF, EC_TXT_GRN
                            );
                            validInput = 1;
                            break;
                        case 'M':
                            printf(
                                EC_TXT_GRN
                                "\nYou have chosen to input an array of data %s%smanually%s%s.",
                                EC_TXT_BLU, EC_UND, EC_DEF, EC_TXT_GRN
                            );
                            validInput = 1;
                            break;
                        default:
                            printf(
                                EC_TXT_YEL
                                "\n%c is not recognized as an option, please try again: "
                                EC_DEF,
                                returnCharacter
                            );
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
                    printf(
                        EC_TXT_CYN
                        "\nPlease determine the size of the data set you would like to have sorted: "
                        EC_TXT_WHT
                    );
                    userArrSize = inputInteger();
                generateItems(dataType, userArrSize, dataList);
                break;
            default:
                printf(
                    EC_TXT_MAG
                    "\ncompilation error, please try again\n"
                    EC_DEF
                );
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
                        char* newChar = (char*)malloc(sizeof(char));
                        *newChar = (char)((rand() % 26) + 65);       //26 is derived from the range of upper case ASCII characters: 90 - 65 + 1, from A to Z basically
                        insertNode(dataList, newChar);
                    break;
                    case 'A':
                        int barLen = ((rand() % userArrSize) + 2);          //smallest possible length of a bar is 2, max being the # of elements + 2 
                        char* newBar = (char*)malloc(sizeof(char) * barLen);
                        for(int i = 0; i < barLen-1; i++){
                            *(newBar +i) = '*';
                        }
                        *(newBar + barLen-1) = '\0';        //closing the string to prevent reading overflow from occuring
                        insertNode(dataList, newBar);
                    break;
                    case 'I':
                        int* newInt = (int*)malloc(sizeof(int));
                        *newInt = rand();
                        insertNode(dataList, newInt);
                    break;              //behave 
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
                EC_CLS
                EC_TXT_CYN
                "\nYou are now manually entering in your data, you may add as many items a you would like."
                "\nOnce you are satisfied, simply input %s%s\";\"%s%s to terminate the insertion process."
                EC_DEF,
                EC_BLD, EC_TXT_RED, EC_DEF, EC_TXT_CYN
            );
            do {
                printf(
                    EC_TXT_CYN
                    "\nPlease enter "
                );
                switch (dataType) {
rePromptC:;          case 'C':
                        printf(
                            "a character: "
                            EC_TXT_WHT
                        );
                        //getting user input
                            userIn = inputCharacter();
                        //Checking if the input is acceptable
                            if(strlen(userIn) > strlen("T\0")){
                                printf(
                                    EC_TXT_YEL
                                    "\nYou have entered too many characters, please try again!"
                                );
                                printf(
                                    EC_TXT_CYN
                                    "\nPlease enter "
                                );
                                free(userIn);
                                goto rePromptC;
                            }
                            else{           //inserting the character into doubly list
                                c = *userIn;
                                if(c == ';'){
                                    free(userIn);
                                    userIn = NULL;
                                    break;
                                }
                                if((int)c > 96 && (int)c < 123){                       //ASCII 97 is a, 122 is z
                                    *userIn = (char)((int)c - 32);                           //this simply capitalizes the user's input 
                                }
                                insertNode(dataList, userIn);
                            }
                    break;
rePromptA:;         case 'A':
                        printf(
                            "a set of asterisks: "
                            EC_TXT_WHT
                        );
                        //getting user input
                            userIn = inputCharacter();
                        //validating that all characters inserted are asterisks
                            c = strlen(userIn) > strlen("T\0") ? ' ' : *userIn;
                            if(c == ';'){
                                free(userIn);
                                break;
                            }
                            for(int i = 0; i < strlen(userIn); i++){
                                if( (int)(*(userIn+i)) != 42 ){
                                    printf(
                                        EC_TXT_YEL
                                        "\n%s is not a valid asterisks bar, it must contain %sonly%s%s%s \"*\"%s%s. Please try again."
                                        EC_DEF,
                                        userIn, EC_ITC, EC_DEF, EC_TXT_WHT, EC_BLD, EC_DEF, EC_TXT_YEL
                                    );
                                    printf(
                                        EC_TXT_CYN
                                        "\nPlease enter "
                                    );
                                    free(userIn);
                                    goto rePromptA;
                                }
                            }
                        //inserting the asterisk bar into doubly list;
                            insertNode(dataList, userIn);
                    break;
                    case 'I':
                        printf(
                            "a positive, whole integer: "
                            EC_TXT_WHT
                        );
                        //DIALV
                            int* num = (int*)malloc(sizeof(int));
                        //getting user input
                            *num = inputInteger();
                            c = *num == -1 ? ';' : ' ';         //if the user enters ;, inputInteger() returns -1
                        //inserting the number into doubly list
                            if(c != ';'){
                                insertNode(dataList, num);
                            }
                    break;
                }
            } while (c != ';');
            
    }