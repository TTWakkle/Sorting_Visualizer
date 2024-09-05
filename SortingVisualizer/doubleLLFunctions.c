//Author:                 Taha Twakkal
//Date:                   2024/05/18 -- 2024/xx/xx
//Description:            This file contains basic functions and operations
//that could be applied to a double linked list data structure. It handles all nodes
//as generic nodes 
#include "mainHeader.h"

//creates and Initializes a double linked list structure
    DOUBLY_LIST* createDLL(void){
        //declaring and allocating enough memory for a DLL Structure
            DOUBLY_LIST* dLL;
            dLL = (DOUBLY_LIST*)malloc(sizeof(DOUBLY_LIST));

        //ensuring that the DLL was created successfully, then initializing its parameters
            if(dLL){
                dLL->front = NULL;
                dLL->rear = NULL;
                dLL->count = 0;
            }

        //returning the address of the newly created DLL
            return dLL;
    } 
//Inserts an item into the end of the DLL
    int insertNode(DOUBLY_LIST* dLL, void* itmPtr){
        //declaring and initializing local variables
            DATA_NODE* newNodePtr;
            if(!(newNodePtr = (DATA_NODE*)malloc(sizeof(DATA_NODE))))
                return 0;

            newNodePtr->dataPtr = itmPtr;
            newNodePtr->next = NULL;
            newNodePtr->previous = NULL;

        //checking whether this is the first item being inserted
            if(dLL->count == 0){
                dLL->front = newNodePtr;
                dLL->rear = newNodePtr;
            }
            else {
                newNodePtr->previous = dLL->rear;
                dLL->rear->next = newNodePtr;
            }

        /*Increasing the number of items stored in the DLL, Dictating where the 
        * new rear of the queue is, providing the new node an index, and 
        * returning 1 for successful insertion */
            newNodePtr->nodeIndex = dLL->count;
            (dLL->count)++;
            dLL->rear = newNodePtr;
            return 1;
    }
//removes an item from the DLL, given data about the item
    int removeNode(DOUBLY_LIST* dLL, void* itemPtr){
        //declaring and initializing local variables
            DATA_NODE* deleteNodePtr;
            int search = find(dLL, &deleteNodePtr, (char*)itemPtr); 

        //ensuring that the passed dLL has items to delete, and deleting if item actually exists
            if(search == 1){
                if(dLL->front == deleteNodePtr){            //node is at the front
                    dLL->front = deleteNodePtr->next;
                }
                else{                                       //node exists elsewhere except the front
                    deleteNodePtr->previous->next = deleteNodePtr->next;
                }

                if(deleteNodePtr->next == NULL){            //node os at the rear
                    dLL->rear = deleteNodePtr->previous;
                }
                else{                                       //node exists elsewhere but the front and the rear
                    deleteNodePtr->next->previous = deleteNodePtr->previous;
                }

                free(deleteNodePtr);
                return search;
            }
            else
                return search;
    }

//find an item in the DLL, this algorithm uses Linear Search since node orders are random
    int find(DOUBLY_LIST* dLL, DATA_NODE** nodePtr, char* data){
        //declaring and initializing local variables
            DATA_NODE* visitedNode = dLL->front;
        //ensuring the DLL has items to begin with
            if(!dLL->count)
                return 0;
        //searching through the dLL to find the node that includes the data we're searching for
            while(visitedNode != NULL && *((char*)(visitedNode->dataPtr)) != *data){
                visitedNode = visitedNode->next;
            }
        //returning the given node's address and terminating function
            if(*((char*)(visitedNode->dataPtr)) == *data){
                *nodePtr = visitedNode;
                return 1;
            }
            else{
                *nodePtr = NULL;
                return -1;
            }
    }

//Prints out the items stored in the DLL, starting from the front
    int printDLL(DOUBLY_LIST* dLL){
        //Declaring and initializing local variables
            DATA_NODE* pNL;

        //checking whether the dLL is empty or not
            if(!dLL->count)
                return 0;

        //Traversing the dLL until the rear has been printed
            for(pNL = dLL->front; pNL != NULL; pNL = pNL->next){
                if(dLL->dataType == 'C' || dLL->dataType == 'A')
                    printf("%s\n", (char*)(pNL->dataPtr));
                else
                    printf("%d\n", *((int*)pNL->dataPtr));
            }

            return 1;
    }

//de-allocates any memory that was used for the DLL structure
    void freeDLL(DOUBLY_LIST* dLL){
        DATA_NODE* pNL = dLL->front;

        while(pNL != NULL){
            DATA_NODE* tmp = pNL;
            pNL = pNL->next;
            free(tmp->dataPtr);
            free(tmp);
        }

        free(dLL);
    }