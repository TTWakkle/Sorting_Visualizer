//Author:                 Taha Twakkal
//Date:                   2023/09/18 -- 2023/09/20
//Description:            This file is what stores all the sorting algorithms this program uses,
//it also allows the user to choose which algorithm they would like to see be used to sort the
//generated data. At the moment, only bubble(1), coctail(2), selection(3), and insert(4) sort
//are currently implemented, more to be added later. 
#include "mainHeader.h"
int algorithmSelection(){
    int sortAlg = 0;

    printf("\nPlease select which sorting algorithm you would like to use:\n");
    printf("\nBubble Sort           (1)\nCoctail Sort          (2)\nSelection Sort        (3)\nInsert Sort           (4)");
    sortAlg = inputInteger();
    return sortAlg;
}

int sort(int algorithmSelection()){
    
    switch (algorithmSelection()){
        case 1: bubbleSort(); break;
        case 2: coctailSort(); break;
        case 3: selectionSort(); break;
        case 4: insertSort(); break;
        default: printf("none of these were selected lol"); break;
    }
    return 1;
}

int bubbleSort(){
    printf("\nI do nothing right now!(bubble sort funct)");
    return 1;
}

int coctailSort(){
    printf("\nI do nothing right now!(coctail sort funct)");
    return 1;
}

int selectionSort(){
    printf("\nI do nothing right now!(selection sort funct)");
    return 1;
}

int insertSort(){
    printf("\nI do nothing right now!(insert sort funct)");
    return 1;
}