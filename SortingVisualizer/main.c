//Author:                 Taha Twakkal
//Date:                   2023/01/18 -- 2025/04/09
//Description:            initializes the sorting Visualizer program

#include "mainHeader.h"
int main() {
    //declaring and initializing local variables
        DOUBLY_LIST* dataList = createDLL();

    //getting user input
        printf(
            EC_TXT_CYN
            "\nSelect which data type you would like to sort\n(\"C\" for characters, \"I\" integers, and \"A\" for asterisk bars): "
            EC_TXT_WHT
        );
        generate(algorithmDataType(), dataList);

    //Sorting based on user's choice
        printf(
            EC_TXT_CYN
            "\ncurrent items stored in the data list: %d"
            "\ncurrent data in DataList:\n"
            EC_DEF, 
            (dataList->count)
        );

        printDLL(dataList);

        system("pause");
        sort(dataList);

        printf(
            EC_CLS
            EC_TXT_CYN
            "\ndata after sorting has been completed:\n"
            EC_DEF
        );
        printDLL(dataList);
    //terminating program
        freeDLL(dataList);
        printf(
            EC_BLD
            EC_TXT_BG_WHT
            "\ndLL cleared, terminating program"
            EC_DEF
            "\n"
        );
        system("pause");
    return 0;
}

