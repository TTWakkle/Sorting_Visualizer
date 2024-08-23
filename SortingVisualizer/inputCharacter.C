//Author:                 Taha Twakkal
//Date:                   2024/01/16 -- 2023/xx/xx
//Description:            requests a string of characters from the user,
//but will only accept a charcter set that does not include any numbers or 
//symbols, with the exception of spacebars. it allocates memory for the given
//user input in the heap, and returns an address of its location whenever this
//function is called.
//-------------------------------------------------------------------------------
/*IT MUST BE FREED AFTER EVERY CALL OF inputCharacter() TO PREVENT MEMORY LEAKS*/
//-------------------------------------------------------------------------------

#include "mainHeader.h"


/**Requests, Stores, and validates a user's input
 **IT MUST BE FREED AFTER EVERY CALL OF inputCharacter() TO PREVENT MEMORY LEAKS* */
char inputCharacter(char** mainUserIn) {
    //Declaring and initializing variables
        _Bool validInput = 0;
    
    do {
        //Declaring and initializing local variables and pointers
            int userInIndex = 0, currentUserInSize = 1;                              //currentUserInSize & userInIndex trail each other, such that memory allocation is precise to exact bytes needed
            int endOfLine = EOF;                                                     //EOF is similar to when the user presses "Enter", useful for program rigitity
            char *userIn = (char*)malloc(sizeof(char));                              //userIn initialized with size of 1, increased by 1 every time the user inputs in a new character

        //Getting user input, while dynamically allocating more memory if needed
            while ((endOfLine = getchar()) != '\n' && (char)endOfLine != EOF){
                *(userIn + userInIndex) = (char)endOfLine;
                currentUserInSize++;
                userInIndex++;
                userIn = (char*)realloc(userIn, currentUserInSize);
            }

        //closing the userIn array and transferring it to a static variable
            *(userIn + userInIndex) = '\0';
            *mainUserIn = (char*)malloc(sizeof(userIn));

        //Validating if staticUserIn is an acceptable set of characters only 
            for(int i = 0; i < strlen(userIn); i++){
                if( ( (((int)*(userIn+i)) > 64) && (((int)*(userIn+i)) < 91) ) || ( (((int)*(userIn+i)) > 96) && (((int)*(userIn+i)) < 123) ) || ( ((int)*(userIn+i)) == 32 ) || ( ((int)*(userIn+i)) == 59 ) || ( ((int)*(userIn+i)) == 42 )){                //ASCII 65 is A, 90 is Z, 97 is a, 122 is z, 32 is a space, 59 is ;, 42 is *
                    validInput = 1;
                }
                else {
                    printf("\n%s is not a valid set of characters!Please try again: ", userIn);
                    validInput = 0;
                    break;
                }
            }

            if(validInput){
                //transferring the user's input to a pointer from where this function was called
                    strcpy(*mainUserIn, userIn);
                    free(userIn);
                    userIn = NULL;
            }

    }while(!validInput);
      
}