//Author:                 Taha Twakkal
//Date:                   2024/01/16 -- 2023/xx/xx
//Description:            This file is what stores all the sorting algorithms this program uses,
//it also allows the user to choose which algorithm they would like to see be used to sort the
//generated data. At the moment, only bubble(1), coctail(2), selection(3), and insert(4) sort
//are currently implemented, more to be added later. 
#include "mainHeader.h"

//Prompts the user to select which sorting algorithm they would like to use to sort their data
    int algorithmSelection(){
        int sortAlg = 0;
        do{
            printf("\nPlease select which sorting algorithm you would like to use:");
            printf(
                "\nBubble Sort\t\t(1)"
                "\nCoctail Sort\t\t(2)"
                "\nSelection Sort\t\t(3)"
                "\nInsert Sort\t\t(4)"
                "\nTerminate program\t\t(\";\")\n"
            );
            sortAlg = inputInteger();
            if(sortAlg == -1){
                return sortAlg;
            }
            else if (sortAlg >=1 && sortAlg <=4) {
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
                inputCharacter(&userIn);
            //checking if the input is acceptable
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
                        printf("\nYou have chosen to demonstrate the sorting algorithms using char (C) data types.");
                        validInput = 1;
                        break;
                    case 'I':
                        printf("\nYou have chosen to demonstrate the sorting algorithms using integer (I) data types.");
                        validInput = 1;
                        break;
                    case 'A':
                        printf("\nYou have chosen to demonstrate the sorting algorithms using Asterisk (*) bars as data types.");
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
    int sort(DOUBLY_LIST* dLL){
        switch (algorithmSelection()){
            case 1: bubbleSort(dLL); break;
            case 2: coctailSort(dLL); break;
            case 3: selectionSort(dLL); break;
            case 4: insertSort(dLL); break;
            case -1: return 1;
            default: printf("\nThat is not a valid selection, please try again!\n"); break;
        }
        return 1;
    }

/*This function acts sort of like a wrapper to provide proper formatting and display of the provided
* doubly list, based on the user's selected data type */
void printFormatted(DOUBLY_LIST* dLL){
    switch (dLL->dataType){
        case 'C':
            //printf("\ndo something cool here idk\n");
            printDLL(dLL);
        break;
        case 'I':
            //printf("\ndo something cool here idk\n");
            printDLL(dLL);
        break;
        case 'A':
            //printf("\ndo something cool here idk\n");
            printDLL(dLL);
        break;
        default:
            //printf("\nThis data type is unrecognizeable, or it may not have any proper formatting.\n");
            printDLL(dLL);
        break;
    }
}

int bubbleSort(DOUBLY_LIST* dLL){
    //DAILV
        bool swap = true;

    //checking if there are items to sort
        if(dLL->count <= 1){
            return 0;
        }
    //Initializing the algorithm
        printf("\nBUBBLE SORT!!!!\n");
        while(swap){
            swap = false;
            DATA_NODE* curr = dLL->front;
            
            while(curr->next != NULL){
                bool swapNeeded = false;

                switch (dLL->dataType){     //ensures the right comparision is being done
                    case 'I':
                        if( *((int*)(curr->dataPtr))  > *((int*)(curr->next->dataPtr)) )
                            swapNeeded = true;
                    break;
                    case 'C':
                        if( *((char*)(curr->dataPtr))  > *((char*)(curr->next->dataPtr)) )
                            swapNeeded = true;
                    break;
                    case 'A':
                        if(strlen((char*)(curr->dataPtr)) > strlen((char*)(curr->next->dataPtr)))
                            swapNeeded = true;
                    break;
                }

                if(swapNeeded){
                    void* tmp = curr->dataPtr;
                    curr->dataPtr = curr->next->dataPtr;
                    curr->next->dataPtr = tmp;
                    swap = true;
                }

                curr = curr->next;
            }
        }

    //returning control back on successful sorting
        return 1;
}

int coctailSort(DOUBLY_LIST* dLL){
    //DAILV
        bool swap = true;
        
    //checking if there are items to sort
        if(dLL->count <= 1){
            return 0;
        }

    //initializing the algorithm
        printf("\n COCTAIL SORT!!!!\n");
        while(swap){
            swap = false;
            DATA_NODE* curr = dLL->front;

            //traversing the dLL front -> rear, same pattern as bubbleSort  
                while(curr->next != NULL){
                    bool swapNeeded = false;

                    switch (dLL->dataType){     //ensures the right comparision is being done
                        case 'I':
                            if( *((int*)(curr->dataPtr))  > *((int*)(curr->next->dataPtr)) )
                                swapNeeded = true;
                        break;
                        case 'C':
                            if( *((char*)(curr->dataPtr))  > *((char*)(curr->next->dataPtr)) )
                                swapNeeded = true;
                        break;
                        case 'A':
                            if(strlen((char*)(curr->dataPtr)) > strlen((char*)(curr->next->dataPtr)))
                                swapNeeded = true;
                        break;
                    }

                    if(swapNeeded){
                        void* tmp = curr->dataPtr;
                        curr->dataPtr = curr->next->dataPtr;
                        curr->next->dataPtr = tmp;
                        swap = true;
                    }

                    curr = curr->next;
                }

            //checking whether no data manipulation occured
                if(!swap)
                    break;
                swap = false;
                curr = dLL->rear;
                
            //traversing the dLL rear -> front
                while(curr->previous != NULL){
                    bool swapNeeded = false;

                    switch (dLL->dataType){     //ensures the right comparision is being done
                        case 'I':
                            if( *((int*)(curr->dataPtr))  < *((int*)(curr->previous->dataPtr)) )
                                swapNeeded = true;
                        break;
                        case 'C':
                            if( *((char*)(curr->dataPtr))  < *((char*)(curr->previous->dataPtr)) )
                                swapNeeded = true;
                        break;
                        case 'A':
                            if(strlen((char*)(curr->dataPtr)) < strlen((char*)(curr->previous->dataPtr)))
                                swapNeeded = true;
                        break;
                    }

                    if(swapNeeded){
                        void* tmp = curr->dataPtr;
                        curr->dataPtr = curr->previous->dataPtr;
                        curr->previous->dataPtr = tmp;
                        swap = true;
                    }

                    curr = curr->previous;
                }
        }
    //returning control back on successful sorting
        return 1;
}

int selectionSort(DOUBLY_LIST* dLL){
    printf("\nI do nothing right now!(selection sort funct)");
    return 1;
}

int insertSort(DOUBLY_LIST* dLL){
    printf("\nI do nothing right now!(insert sort funct)");
    return 1;
}