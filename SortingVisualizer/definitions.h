#ifndef DEFINITIONS_H_INCLUDED
#define DEFINITIONS_H_INCLUDED
    
    #define printf __mingw_printf
    //data union structure, may be obselete, idk we'll see
        typedef union data {
            char* asterisks;
            char letters;
            int numbers;
        }data_Type;
        
    //data node structure
        typedef struct {
            void* dataPtr;
            int nodeIndex;
            struct DATA_NODE* next;
            struct DATA_NODE* previous;
        }DATA_NODE;
    //doubly list of node structure
        typedef struct {
            DATA_NODE* front;
            DATA_NODE* rear;
            int count;
        }DOUBLY_LIST;
    //function prototypes

        int inputInteger(void);
        char inputCharacter(char**);
        int generate(char dataType, DOUBLY_LIST* dataList);       // "C" for characters, "I" integers, and "A" for asterisk bars
        void generateItems(char dataType, int dataSetSize, int arraySize);
        int insertItems(char dataType, int arraySize);
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
        int insert(DOUBLY_LIST* dLL, void* itmPtr);
        int remove(DOUBLY_LIST* dLL, void* itemPtr);
        int find(DOUBLY_LIST* dLL, DATA_NODE** nodePtr, char* data);
        int printDLL(DOUBLY_LIST* dLL);
        void freeDLL(DOUBLY_LIST* dLL);
#endif