//Author:                 Taha Twakkal
//Date:                   2023/01/18 -- 2023/01/30
//Description:            initializes the sorting Visualizer program

#include "mainHeader.h"
int main() {
    //declaring and initializing local variables
        int dataArraySize = 0;
        DOUBLY_LIST* dataList = createDLL();

    //getting user input
        //printf("\nPlease enter the size of the data set you would like to sort: ");
        //dataArraySize = inputInteger();

        printf("\nSelect which data type you would like to sort\n(\"C\" for characters, \"I\" integers, and \"A\" for asterisk bars): ");
        generate(algorithmDataType(), dataList);

    //Sorting based on user's choice
        sort();
        printf("\nhello world\n");

    //terminating program
        freeDLL(dataList);
        free(dataList);
        system("pause");
    return 0;
}

