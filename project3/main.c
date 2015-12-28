/**
 *  CSC-1600 Operating Systems
 *  Project 3
 *  main.c
 *  Shan Shi
 */
#include "CrossProductPJM.h"
#define NUMTHREADS 744 // also the number of lines to read

// takes numbers at locations 3-8 in a PJM data file and computes the cross product using threads
int main(void){
	PJMData pjm;
	FILE *fp = fopen("data", "r"); // open the file called data
	FILE *fp2 = fopen("dataout", "w+"); // open the file called dataout for writing
	pjm.fp = fp; // save the file to the shared struct
	pjm.fp2 = fp2; // save the file to the shared struct
	pjm.busy = 0; // initialize busy to false

	pthread_t allThreads[NUMTHREADS]; // declare one thread per line

	for(int i = 0; i < NUMTHREADS; i++){
		// initialize each thread with the getCrossProduct function and pjm as parameter
		pthread_create(&allThreads[i], NULL, (void *) &getCrossProduct, (void *) &pjm);
	}

	for(int i = 0; i < NUMTHREADS; i++){
		// the threads run while main waits to clean up resources
		pthread_join(allThreads[i], NULL);
	}

	// print the 6x6 matrix out in scientific notation
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			printf("%e  ", pjm.XX[i][j]);
		}
		printf("\n");
	}
	printf("Thread count: %d\n", NUMTHREADS);
}
