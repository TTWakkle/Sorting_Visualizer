//Author:                 Taha Twakkal
//Date:                   2023/11/11 -- 2025/04/09
//Description:            The purpose of this function is to input, store, and validate
//a user's input. It can dynamically allocate memory for the user's input, preventing any
//overflow, prior to validating whether it is an acceptable number or not. It does this
//by storing the user's input in a char array of a set size, 1, which is then increased 
//by 1 every time the user's input of chars reaches the current size of the userIn pointer 

#include "mainHeader.h"

//Requests, Stores, and validates a user's input
int inputInteger() {
    //Declaring and initializing variables
        _Bool validInput = 0;
        int returnValue = 0;
        char* staticUserIn;
    
    do{
        //Declaring and initializing local variables and pointers
            int userInIndex = 0, currentUserInSize = 1;                              //currentUserInSize & userInIndex trail each other, such that memory allocation is precise to exact bytes needed
            int endOfLine = EOF;                                                     //EOF is similar to when the user presses "Enter", useful for program rigitity
            char *userIn = malloc(sizeof(char));                                     //userIn initialized with size of 1, increased by 1 every time the user inputs in a new character

        //Getting user input, while dynamically allocating more memory if needed
            while ((endOfLine = getchar()) != '\n' && (char)endOfLine != EOF){
                *(userIn + userInIndex) = (char)endOfLine;
                currentUserInSize++;
                userInIndex++;
                userIn = realloc(userIn, currentUserInSize);
            }

        //closing the userIn array and transferring it to a static variable
        //#8: Remove this entire section, since it's practically redundant and inefficient
            *(userIn + userInIndex) = '\0';
            staticUserIn = (char*)malloc(sizeof(userIn));
            strcpy(staticUserIn, userIn);
            free(userIn);
            userIn = NULL;

        //Validating if staticUserIn is an acceptable number
            if(strlen(staticUserIn) == strlen("T\0"))
                if((int)staticUserIn[0] == 59)
                    return -1;

            for(int i = 0; i < strlen(staticUserIn); i++){
                if( ( (int)staticUserIn[i]>47 ) && ( (int)staticUserIn[i]<58 ) ){                //ASCII 48 is 0, 57 is 9
                    validInput = 1;
                }
                else {
                    validInput = 0;
                    break;
                }
            }

            if(!validInput){
                printf(
                    EC_TXT_YEL
                    "%s is not a valid whole number greater than 0 (try again):"
                    EC_TXT_WHT,
                    staticUserIn
                );
            }
            else if(atoi(staticUserIn) > 0){
                validInput = 1;
                returnValue = atoi(staticUserIn);
            }
            else{
                printf(
                    EC_TXT_YEL
                    "%s is not a valid whole number greater than 0 (try again):"
                    EC_TXT_WHT,
                    staticUserIn
                );
                validInput = 0;
            }
    }while(!validInput);

    //returning the user's input to main
        free(staticUserIn);
        return returnValue;
}