//Author:                 Taha Twakkal
//Date:                   2023/01/18 -- 2023/09/05
//Description:            initializes the sorting Visualizer program

#include "mainHeader.h"
int main() {
    //declaring and initializing local variables
        DOUBLY_LIST* dataList = createDLL();

    //getting user input
        printf("\nSelect which data type you would like to sort\n(\"C\" for characters, \"I\" integers, and \"A\" for asterisk bars): ");
        generate(algorithmDataType(), dataList);

    //Sorting based on user's choice
        printf("\ncurrent items stored in the data list: %d\n", dataList->count);
        printf("\ncurrent data in DataList:\n");

        printDLL(dataList);
        system("pause");

        sort(dataList);
    //terminating program
        freeDLL(dataList);
        printf("\ndLL cleared\n");
        system("pause");
        free(dataList);
        printf("\npointer to data list cleared\n");
        system("pause");
    return 0;
}

