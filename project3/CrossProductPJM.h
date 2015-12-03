/**
 *  CSC-1600 Operating Systems
 *  Project 3
 *  CrossProductPJM.h
 *  Shan Shi
 */

#include <stdio.h>
#include <pthread.h>

#ifndef CrossProductJPM_H
#define CrossProductJPM_H

typedef struct PJMData{
	FILE *fp; // pointer to file
	FILE *fp2; // pointer to outfile
	double XX[6][6]; // 6x6 matrix to contain the end cross product
	int busy; // mutex
} PJMData;

void getCrossProduct(void *ptr);

#endif
