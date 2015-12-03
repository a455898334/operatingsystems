/**
 *  CSC-1600 Operating Systems
 *  Project 3
 *  getCrossProduct.c
 *  Shan Shi
 */

#include "CrossProductPJM.h"

// ptr is type PJM, which contains a pointer to the file and the 6x6 matrix
// takes the next line from the file, calculates the cross product, and stores it into XX
void getCrossProduct(void *ptr){
	// turn the ptr back into PJMData
	PJMData *pd;
	pd = (PJMData *) ptr;
	long l1, l2, l3, l4;

	// get the next line from the file and store it into line[]
	char line[200];
	fgets(line, 200, pd->fp);

	// parse the six numbers from the next line in the file (%*s means a string whose value we don't care about)
	float X[6];
	sscanf(
		line,
		"%*s   %*s   %f   %f   %f   %f   %f   %f   %*i   %*f   %*f   %*f   %*f   %*f",
		&X[0], &X[1], &X[2], &X[3], &X[4], &X[5]
	);

	// loop through, calculate the cross product, and add it to the 6x6 matrix passed in with ptr
	l1 = (long) &pd/4096; // page number for the current program
	l2 = (long) &XX[0][0]/4096; // page number for XX
	
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			while(pd->busy); // busy wait while another thread is writing to memory
			pd->busy = 1;
			pd->XX[i][j] += X[i] * X[j];
			l3 = (long) &X[i]/4096; // page number of X[i]
			l4 = (long) &X[j]/4096; // page number of X[j]
			fprint(fp2,"%d", l1); // prints l1 to fp2 file
			fprint(fp2,"%d", l2); // prints l2 to fp2 file
			fprint(fp2,"%d", l3); // prints l3 to fp2 file
			fprint(fp2,"%d", l4); // prints l4 to fp2 file
			pd->busy = 0;
		}
	}

	// exit the thread
	pthread_exit(0);
}
