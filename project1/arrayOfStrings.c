/**
 *  CSC-1600 Operating Systems
 *  Project 1
 *  arrayOfStrings.c
 *  Shan Shi
 */

#include "arrayOfStrings.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXARRAYSIZE 15

void InitializeArray(char *array[], int n){
    for(int i = 0; i < n; i++){
        array[i] = NULL;
    }
}

void InsertStringAt(char *array[], char *s, int pos){
    if(s != NULL){
        array[pos] = malloc(strlen(s));
        strcpy(array[pos],s);
    }
}

void RemoveStringAt(char *array[], int pos){
    if(array[pos]!=NULL){
        free(array[pos]);
        array[pos] = NULL;
    }
}

void RemoveAll(char *array[], int n){
    for(int i = 0; i < n; i++){
        RemoveStringAt(array, i);
    }
}

void Print(char *array[], int pos){
    if(array[pos] != NULL){
        printf("%s",array[pos]);
    }else{
        printf("[%d]", pos); // prints [pos] if the string is empty
    }
}

void PrintAll(char *array[], int n){
    for(int i = 0; i < n; i++){
        Print(array, i);
    }
}
