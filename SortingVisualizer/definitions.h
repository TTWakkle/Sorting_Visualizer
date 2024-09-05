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
        char inputCharacter(char**);
        int generate(char dataType, DOUBLY_LIST* dataList);       // "C" for characters, "I" integers, and "A" for asterisk bars
        void generateItems(char dataType, int dataSetSize, DOUBLY_LIST* dataList);
        int insertItems(char dataType, DOUBLY_LIST* dataList);
        void printData(char dataType);          // "C" for characters, "I" integers, and "A" for asterisk bars

    //Various utilitarian function prototypes, more can be added here
        int algorithmSelection(void);
        char algorithmDataType(void);
        int sort();
        void printItems();


    //sorting algorithm function prototypes
        int bubbleSort();
        int coctailSort();
        int selectionSort();
        int insertSort();

    //Doubly linked list function prototypes
        DOUBLY_LIST* createDLL(void);
        int insertNode(DOUBLY_LIST* dLL, void* itmPtr);
        int removeNode(DOUBLY_LIST* dLL, void* itemPtr);
        int find(DOUBLY_LIST* dLL, DATA_NODE** nodePtr, char* data);
        int printDLL(DOUBLY_LIST* dLL);
        void freeDLL(DOUBLY_LIST* dLL);
#endif