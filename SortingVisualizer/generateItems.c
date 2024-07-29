//Author:                 Taha Twakkal
//Date:                   2024/01/16 -- 2023/09/20
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
                            printf("\nYou have chosen to input an array of data manually");
                            validInput = 1;
                            break;
                        default:
                            printf("\n%s is not recognized as an option, please try again: ", returnCharacter);
                            validInput = 0;
                            break;
                        }
                    }
            } while (!validInput);

        //determining the size of the array of data that is to be sorted
            printf("\nPlease determine the size of the array you would like to have sorted: ");
            userArrSize = inputInteger();

        //function calls based on the user's decisions
            switch (returnCharacter) {
            case 'M':
                insertItems(dataType, userArrSize, dataList);
                break;
            case 'R':
                generateItems(dataType, userArrSize, dataList);
                break;
            default:
                printf("\ncompilation error, please try again\n");
                return -1;
            }
        return 1;
    }

//This function generates data through a randomizer, and stores them in a doubly list that's been created in main
    int generateItems(char dataType, int userArrSize, DOUBLY_LIST* dataList){

    }

//This function requests data from the user, and stores ...
int insertItems(char dataType, int userArrSize, DOUBLY_LIST* dataList){

}