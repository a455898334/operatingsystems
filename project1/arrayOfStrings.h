/**
 *  CSC-1600 Operating Systems
 *  Project 1
 *  arrayOfStrings.h
 *  Shan Shi
 */

#ifndef arrayOfStrings_h
#define arrayOfStrings_h

#include <stdio.h>
#include <stdlib.h>

void InitializeArray(char *array[], int n);
void InsertStringAt(char *array[], char *s, int pos);
void RemoveStringAt(char *array[], int pos);
void RemoveAll(char *array[], int n);

void Print(char *array[], int pos);
void PrintAll(char *array[], int n);

#endif