//Author:                 Taha Twakkal
//Date:                   2024/01/16 -- 2025/04/09
//Description:            This file is what stores all the sorting algorithms this program uses,
//it also allows the user to choose which algorithm they would like to see be used to sort the
//generated data. At the moment, only bubble(1), cocktail(2), selection(3), and insert(4) sort
//are currently implemented, more to be added later. 
#include "mainHeader.h"

//Prompts the user to select which sorting algorithm they would like to use to sort their data
    int algorithmSelection(){
        int sortAlg = 0;
        do{
            printf(
                EC_TXT_CYN
                EC_UND
                EC_BLD
                "\nPlease select which sorting algorithm you would like to use:"
                EC_DEF
                EC_TXT_CYN
                "\nBubble Sort\t\t(1)"
                "\nCocktail Sort\t\t(2)"
                "\nSelection Sort\t\t(3)"
                "\nInsert Sort\t\t(4)"
                EC_TXT_RED
                "\nTerminate program\t(\";\")\n"
                EC_DEF
                EC_TXT_WHT
            );
            sortAlg = inputInteger();
            if(sortAlg == -1){
                return sortAlg;
            }
            else if (sortAlg >=1 && sortAlg <=4) {
                return sortAlg;
            }
            else{
                printf(
                    EC_TXT_YEL
                    "\n%d is not a valid selection, please try again!"
                    EC_DEF,
                    sortAlg
                );
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
                printf(EC_TXT_WHT);
                userIn = inputCharacter();
            //checking if the input is acceptable
                if(strlen(userIn) > strlen("T\0")){
                    printf(
                        EC_BLD
                        EC_TXT_RED
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
                    switch (returnCharacter) {
                    case 'C':
                        printf(
                            EC_TXT_GRN
                            "\nYou have chosen to demonstrate the sorting algorithms using %s%schar (C)%s data types.",
                            EC_TXT_BLU,
                            EC_UND,
                            EC_DEF
                        );
                        validInput = 1;
                        break;
                    case 'I':
                        printf(
                            EC_TXT_GRN
                            "\nYou have chosen to demonstrate the sorting algorithms using %s%sInteger (I)%s data types.",
                            EC_TXT_BLU,
                            EC_UND,
                            EC_DEF
                        );
                        validInput = 1;
                        break;
                    case 'A':
                        printf(
                            EC_TXT_GRN
                            "\nYou have chosen to demonstrate the sorting algorithms using %s%sAsterisk (*)%s bars as data types.",
                            EC_TXT_BLU,
                            EC_UND,
                            EC_DEF
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
        }while(!validInput);

        return returnCharacter;
    }

//Switch block to determine which function call occurs, there is no computation/sorting occuring here. 
    int sort(DOUBLY_LIST* dLL){
        switch (algorithmSelection()){
            case 1: bubbleSort(dLL); break;
            case 2: cocktailSort(dLL); break;
            case 3: selectionSort(dLL); break;
            case 4: insertSort(dLL); break;
            case -1: return 1;
            default: 
                printf(
                    EC_TXT_YEL
                    "\nThat is not a valid selection, please try again!\n"
                    EC_DEF
                ); 
            break;
        }
        return 1;
    }
//This function is a simple comparetor that returns wheter dataPtr_A is greater than nodeB. its sole purpose is to reduce code repetition
    bool cmpGT(void* dataPtr_A, void* dataPtr_B, char dataType){
        switch (dataType){     //ensures the right comparision is being done
            case 'I':
                if( *(int*)dataPtr_A  > *(int*)dataPtr_B )
                    return true;
                else 
                    return false;
            case 'C':
                if( (int)(*(char*)dataPtr_A)  > (int)(*(char*)dataPtr_B) )
                    return true;
                else
                    return false;
            case 'A':
                if(strlen((char*)dataPtr_A) > strlen((char*)dataPtr_B))
                    return true;
                else
                    return false;
            default:
                return false;
        }
    }

//this function operates the exact same way as cmpGT(), except it compares wheter dataPtr_A is less than nodeB
    bool cmpLT(void* dataPtr_A, void* dataPtr_B, char dataType){
        switch (dataType){     //ensures the right comparision is being done
            case 'I':
                if( *(int*)dataPtr_A  < *(int*)dataPtr_B )
                    return true;
                else
                    return false;
            case 'C':
                if( (int)(*(char*)dataPtr_A)  < (int)(*(char*)dataPtr_B) )
                    return true;
                else
                    return false;
            case 'A':
                if(strlen((char*)dataPtr_A) < strlen((char*)dataPtr_B))
                    return true;
                else
                    return false;
            default:
                return false;
        }
    }

//this fucntion simply checks wheter the data in two different nodes are equal or not
    bool cmpEQ(void* dataPtr_A, void* dataPtr_B, char dataType){
        switch (dataType){     //ensures the right comparision is being done
            case 'I':
                if( *(int*)dataPtr_A == *(int*)dataPtr_B )
                    return true;
                else
                    return false;
            case 'C':
                if( *(char*)dataPtr_A  == *(char*)dataPtr_B )
                    return true;
                else
                    return false;
            case 'A':
                if(strlen((char*)(dataPtr_A)) == strlen((char*)(dataPtr_B)))
                    return true;
                else
                    return false;
            default:
                return false;
        }
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
        printf(
            EC_CLS
            EC_BLD
            EC_UND
            EC_TXT_BG_GRN
            EC_TXT_WHT
            "\nBUBBLE SORT!!!!\n"
            EC_DEF
        );
        printDLL(dLL);
        Sleep(500);
        while(swap){
            swap = false;
            DATA_NODE* curr = dLL->front;
            
            while(curr->next != NULL){
                if(cmpGT(curr->dataPtr, curr->next->dataPtr, dLL->dataType)){
                    swapNodes(dLL, curr, curr->next);
                    swap = true;

                    printf(
                        EC_CLS
                        EC_BLD
                        EC_UND
                        EC_TXT_BG_GRN
                        EC_TXT_WHT
                        "\nBUBBLE SORT!!!!\n"
                        EC_DEF
                    );
                    printDLL(dLL);
                    Sleep(500);

                    if(curr->previous){         //prevents jumping two nodes over, since curr was moved
                        curr = curr->previous;
                    }
                }
                else{
                    curr = curr->next;    
                }
            }
        }

    //returning control back on successful sorting
        return 1;
}

int cocktailSort(DOUBLY_LIST* dLL){
    //DAILV
        bool swap = true;
        
    //checking if there are items to sort
        if(dLL->count <= 1){
            return 0;
        }

    //initializing the algorithm
        printf(
            EC_CLS
            EC_BLD
            EC_UND
            EC_TXT_BG_GRN
            EC_TXT_WHT
            "\nCOCKTAIL SORT!!!!\n"
            EC_DEF
        );
        printDLL(dLL);
        Sleep(500);
        while(swap){
            swap = false;
            DATA_NODE* curr = dLL->front;

            //traversing the dLL front -> rear, same pattern as bubbleSort  
                while(curr->next != NULL){
                    if(cmpGT(curr->dataPtr, curr->next->dataPtr, dLL->dataType)){
                        swapNodes(dLL, curr, curr->next);
                        swap = true;

                        printf(
                            EC_CLS
                            EC_BLD
                            EC_UND
                            EC_TXT_BG_GRN
                            EC_TXT_WHT
                            "\nCOCKTAIL SORT!!!!\n"
                            EC_DEF
                        );
                        printDLL(dLL);
                        Sleep(500);

                        if(curr->previous){         //prevents jumping two nodes over, since curr was moved
                            curr = curr->previous;
                        }
                    }
                    else{
                        curr = curr->next;
                    }
                }
            //checking whether no data manipulation occured
                if(!swap)
                    break;
                swap = false;
                curr = dLL->rear;
                
            //traversing the dLL rear -> front
                while(curr->previous != NULL){
                    if(cmpLT(curr->dataPtr, curr->previous->dataPtr, dLL->dataType)){
                        swapNodes(dLL, curr->previous, curr);
                        swap = true;

                        printf(
                            EC_CLS
                            EC_BLD
                            EC_UND
                            EC_TXT_BG_GRN
                            EC_TXT_WHT
                            "\nCOCKTAIL SORT\n"
                            EC_DEF
                        );
                        printDLL(dLL);
                        Sleep(500);
                        
                        if(curr->next){         //prevents jumping two nodes over, since curr was moved
                            curr = curr->next;
                        }
                    }
                    else{
                        curr = curr->previous;
                    }
                }
        }
    //returning control back on successful sorting
        return 1;
}

int selectionSort(DOUBLY_LIST* dLL){
    //DAILV
        DATA_NODE* curr = dLL->front;

    //Initializing the algorithm, and traversing the dLL from front -> rear
        printf(
            EC_CLS
            EC_BLD
            EC_UND
            EC_TXT_BG_GRN
            EC_TXT_WHT
            "\nSELECTION SORT!!!!\n"
            EC_DEF
        );
        printDLL(dLL);
        Sleep(500);
        while(curr != NULL){
            DATA_NODE* minNode = curr;
            DATA_NODE* nextNode = curr->next;

            while(nextNode != NULL){
                if(cmpLT(nextNode->dataPtr, minNode->dataPtr, dLL->dataType))
                    minNode = nextNode;
                nextNode = nextNode->next;
            }

            if(!cmpEQ(minNode->dataPtr, curr->dataPtr, dLL->dataType)){
                swapNodes(dLL, minNode, curr);

                printf(
                    EC_CLS
                    EC_BLD
                    EC_UND
                    EC_TXT_BG_GRN
                    EC_TXT_WHT
                    "\nSELECTION SORT!!!!\n"
                    EC_DEF
                );
                printDLL(dLL);
                Sleep(500);

                if(curr->previous){         //prevents jumping two nodes over, since curr was moved
                    curr = curr->previous;
                }
            }
            else{
                curr = curr->next;
            }
        }   
    return 1;
}

int insertSort(DOUBLY_LIST* dLL){
    //DAILV
        DATA_NODE* curr = dLL->front->next;

    //Initializing the algorithm
        printf(
            EC_CLS
            EC_BLD
            EC_UND
            EC_TXT_BG_GRN
            EC_TXT_WHT
            "\nINSERT SORT!!!\n"
            EC_DEF
        );
        printDLL(dLL);
        Sleep(500);
        while(curr != NULL){
            DATA_NODE* nodeK = curr;
            DATA_NODE* prev = curr->previous;

            while(prev != NULL && cmpGT(prev->dataPtr, nodeK->dataPtr, dLL->dataType)){
                swapNodes(dLL, prev, nodeK);
                prev = nodeK->previous;

                printf(
                    EC_CLS
                    EC_BLD
                    EC_UND
                    EC_TXT_BG_GRN
                    EC_TXT_WHT
                    "\nINSERT SORT!!!\n"
                    EC_DEF
                );
                printDLL(dLL);
                Sleep(500);
            }

            curr = curr->next;
        }

    return 1;
}