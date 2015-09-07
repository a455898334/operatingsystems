/**
 *  CSC-1600 Operating Systems
 *  Project 1
 *  arrayOfStringsTest.c
 *  Shan Shi
 */

#include "arrayOfStrings.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXARRAYSIZE 15


int main(){
    printf("Test 1: \n");
    char *myarray[MAXARRAYSIZE];
    InitializeArray(myarray, MAXARRAYSIZE);
    PrintAll(myarray, MAXARRAYSIZE);
    // expect [0][1][2][3][4][5][6][7][8][9][10][11][12][13][14]

    printf("\n\nTest 2:\n");
    char s[]="Lincoln";
    InsertStringAt(myarray, s, 0);
    PrintAll(myarray,MAXARRAYSIZE);
    // expect Lincoln[1][2][3][4][5][6][7][8][9][10][11][12][13][14]

    printf("\n\nTest 3:\n");
    InsertStringAt (myarray, "Lincoln", 7);
    PrintAll(myarray, MAXARRAYSIZE); // should list Lincoln only
    // expect Lincoln[1][2][3][4][5][6]Lincoln[8][9][10][11][12][13][14]

    printf("\n\nTest 4:\n");
    RemoveStringAt(myarray, 0);
    RemoveStringAt(myarray, 7);
    PrintAll(myarray, MAXARRAYSIZE); // should list nothing
    // expect [0][1][2][3][4][5][6][7][8][9][10][11][12][13][14]

    printf("\n\nTest 5:\n");
    InsertStringAt (myarray, "Manny", 0);
    InsertStringAt (myarray, "Jack", 1);
    InsertStringAt (myarray, "Moe", 2);
    PrintAll(myarray, MAXARRAYSIZE); // list Manny, Moe, and Jack
    //expect MannyJackMoe[3][4][5][6][7][8][9][10][11][12][13][14]

    printf("\n\nTest 6:\n");
    RemoveStringAt(myarray, 1); // Remove Jack
    PrintAll(myarray, MAXARRAYSIZE); // list Manny and Jack. No Moe
    // expect Manny[1]Moe[3][4][5][6][7][8][9][10][11][12][13][14]

    printf("\n\nTest 7:\n");
    RemoveAll(myarray, MAXARRAYSIZE); // Remove Manny and Jack
    PrintAll(myarray, MAXARRAYSIZE); // list should be empty
    //expect [0][1][2][3][4][5][6][7][8][9][10][11][12][13][14]

    // compiles with warnings
    printf("\n\nTest 8:\n");
    InitializeArray(myarray, NULL);
    InsertStringAt(myarray, NULL, NULL);
    RemoveStringAt(myarray, NULL);
    RemoveAll(myarray, NULL);
    PrintAll(myarray, MAXARRAYSIZE); // list should be empty
    //expect [0][1][2][3][4][5][6][7][8][9][10][11][12][13][14]

    printf("\n"); // so the shell is clean
    return 0;
}