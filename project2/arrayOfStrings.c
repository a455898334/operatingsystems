/**
 *  CSC-1600 Operating Systems
 *  Project 1, reused in project 2
 *  arrayOfStrings.c
 *  Shan Shi
 */

#include "arrayOfStrings.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXARRAYSIZE 15

/* Initialize the arrayOfStrings with all NULLs*/
void InitializeArray(char *array[], int n){
    for(int i = 0; i < n; i++){
        array[i] = NULL;
    }
}

/* Insert a string s at position pos in arrayOfStrings array */
void InsertStringAt(char *array[], char *s, int pos){
    if(s != NULL){
        array[pos] = malloc(strlen(s));
        strcpy(array[pos],s);
    }
}

/* Removes the string in arrayOfStrings array at position pos */
void RemoveStringAt(char *array[], int pos){
    if(array[pos]!=NULL){
        free(array[pos]);
        array[pos] = NULL;
    }
}

/* Remove all the strings in arrayOfStrings array, which has length n */
void RemoveAll(char *array[], int n){
    for(int i = 0; i < n; i++){
        RemoveStringAt(array, i);
    }
}

/* Print the string at pos in arrayOfStrings array */
void Print(char *array[], int pos){
    if(array[pos] != NULL){
        printf("%s\n",array[pos]);
    }/*else{
        printf("[%d]", pos); // prints [pos] if the string is empty
    }*/
}

/* Print all the strings in arrayOfStrings array */
void PrintAll(char *array[], int n){
    for(int i = 0; i < n; i++){
        Print(array, i);
    }
}
