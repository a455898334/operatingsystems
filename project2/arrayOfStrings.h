/**
 *  CSC-1600 Operating Systems
 *  Project 1, reused in project 2
 *  arrayOfStrings.h
 *  Shan Shi
 */

#ifndef arrayOfStrings_h
#define arrayOfStrings_h

#include <stdio.h>
#include <stdlib.h>

void SaveSearchPaths(char * search_paths[], int max_paths, int * num_paths);
void mySystem(char * command[], int num_args, char *searchpaths[], int numpaths);

void InitializeArray(char *array[], int n);
void InsertStringAt(char *array[], char *s, int pos);
void RemoveStringAt(char *array[], int pos);
void RemoveAll(char *array[], int n);

void Print(char *array[], int pos);
void PrintAll(char *array[], int n);

#endif