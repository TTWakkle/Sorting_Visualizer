//Author:                 Taha Twakkal
//Date:                   2023/09/18 -- 2023/09/20
//Description:            This file is what stores all the sorting algorithms this program uses,
//it also allows the user to choose which algorithm they would like to see be used to sort the
//generated data. At the moment, only bubble(1), coctail(2), selection(3), and insert(4) sort
//are currently implemented, more to be added later. 
#include "mainHeader.h"

//Prompts the user to select which sorting algorithm they would like to use to sort their data
    int algorithmSelection(){
        int sortAlg = 0;
        do{
            printf("\nPlease select which sorting algorithm you would like to use:\n");
            printf("\nBubble Sort           (1)\nCoctail Sort          (2)\nSelection Sort        (3)\nInsert Sort           (4)\n");
            sortAlg = inputInteger();
            if (sortAlg >=1 && sortAlg <=4) {
                return sortAlg;
            }
            else{
                printf("/n %d is not a valid selection, please try again!", sortAlg);
            }
        }while (sortAlg <1 || sortAlg >4);

        return 0;
    }

//Prompts the user to choose which data type they would like to store
    char algorithmDataType(){
        //declaring and initializing local variables
            char* userIn;
            char returnCharacter;
            _Bool validInput = 0;

        do{
            //getting user input
                userIn = inputCharacter();
            //checking if their input is acceptable
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
                    switch (returnCharacter) {
                    case 'C':
                        printf("\nYou have chosen to demonstrate the sorting algorithms using char (C) data types");
                        validInput = 1;
                        break;
                    case 'I':
                        printf("\nYou have chosen to demonstrate the sorting algorithms using integer (I) data types");
                        validInput = 1;
                        break;
                    case 'A':
                        printf("\nYou have chosen to demonstrate the sorting algorithms using Asterisk (*) bars as data types");
                        validInput = 1;
                        break;
                    default:
                        printf("\n%c is not recognized as an option, please try again: ", returnCharacter);
                        validInput = 0;
                        break;
                    }
                }
        }while(!validInput);

        return returnCharacter;
    }

//Switch block to determine which function call occurs, there is no computation/sorting occuring here. 
    int sort(){
        
        switch (algorithmSelection()){
            case 1: bubbleSort(); break;
            case 2: coctailSort(); break;
            case 3: selectionSort(); break;
            case 4: insertSort(); break;
            default: printf("\nnone of these were selected lol\n"); break;
        }
        return 1;
    }


int bubbleSort(){
    printf("\nI do nothing right now!(bubble sort funct)");
    return 1;
}

int coctailSort(){
    printf("\nI do nothing right now!(coctail sort funct)");
    return 1;
}

int selectionSort(){
    printf("\nI do nothing right now!(selection sort funct)");
    return 1;
}

int insertSort(){
    printf("\nI do nothing right now!(insert sort funct)");
    return 1;
}