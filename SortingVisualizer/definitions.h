#ifndef DEFINITIONS_H_INCLUDED
#define DEFINITIONS_H_INCLUDED
    
    #define printf __mingw_printf
    
    //function prototypes
        int inputInteger(void);
        int generateItems(char dataType);       // "C" for characters, "I" integers, and "A" for asterisk bars
        void printData(char dataType);          // "C" for characters, "I" integers, and "A" for asterisk bars

    //sorting Function prototypes, more can be added here
        int algorithmSelection(void);
        int sort(int algorithmSelection(void));
        int bubbleSort();
        int coctailSort();
        int selectionSort();
        int insertSort();
#endif