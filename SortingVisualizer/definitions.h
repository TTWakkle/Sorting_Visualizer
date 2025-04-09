#ifndef DEFINITIONS_H_INCLUDED
#define DEFINITIONS_H_INCLUDED
    
    #define printf __mingw_printf
    //data node structure
        typedef struct node{
            void* dataPtr;
            int nodeIndex;
            struct node* next;
            struct node* previous;
        }DATA_NODE;
    //doubly list of node structure
        typedef struct {
            DATA_NODE* front;
            DATA_NODE* rear;
            char dataType;
            int count;
        }DOUBLY_LIST;
    //function prototypes

        int inputInteger(void);
        char* inputCharacter(void);
        int generate(char dataType, DOUBLY_LIST* dataList);       // "C" for characters, "I" integers, and "A" for asterisk bars
        void generateItems(char dataType, int dataSetSize, DOUBLY_LIST* dataList);
        int insertItems(char dataType, DOUBLY_LIST* dataList);

    //Various utilitarian function prototypes, more can be added here
        int algorithmSelection(void);
        char algorithmDataType(void);
        void printFormatted(DOUBLY_LIST* dLL);
        int sort(DOUBLY_LIST* dLL);


    //sorting algorithm function prototypes
        int bubbleSort(DOUBLY_LIST* dLL);
        int cocktailSort(DOUBLY_LIST* dLL);
        int selectionSort(DOUBLY_LIST* dLL);
        int insertSort(DOUBLY_LIST* dLL);

    //Doubly linked list function prototypes
        DOUBLY_LIST* createDLL(void);
        int insertNode(DOUBLY_LIST* dLL, void* itmPtr);
        int removeNode(DOUBLY_LIST* dLL, void* itemPtr);
        int find(DOUBLY_LIST* dLL, DATA_NODE** nodePtr, char* data);
        int swapNodes(DOUBLY_LIST* dLL, DATA_NODE* nodeA, DATA_NODE* nodeB);
        int printDLL(DOUBLY_LIST* dLL);
        void freeDLL(DOUBLY_LIST* dLL);
#endif