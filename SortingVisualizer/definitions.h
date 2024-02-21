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
            data_Type* dataPtr;
            struct node* next;
            struct node* previous;
        }DATA_NODE;
    //doubly list of node structure
        typedef struct {
            DATA_NODE* front;
            DATA_NODE *rear;
            int count;
        }DOUBLY_NODE;
    //function prototypes

        int inputInteger(void);
        char* inputCharacter(void);
        int generate(char dataType);       // "C" for characters, "I" integers, and "A" for asterisk bars
        int generateItems(char dataType, int arraySize);
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
#endif