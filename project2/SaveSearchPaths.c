/**
 *  CSC-1600 Operating Systems
 *  Project 2
 *  SaveSearchPaths.c
 *  Shan Shi
 */

#include "arrayOfStrings.h"

#include <stdlib.h>
#include <string.h>

/* Take the path variable, tokenize it with :, and store the tokens in search_paths, also store the length in num_paths */
void SaveSearchPaths(char * search_paths[], int max_paths, int * num_paths){
	const char delim[1] = ":"; // delimeter is :
	char * token;
	int curr_pos = 0;
	token = strtok(getenv("PATH"), delim); // get the PATH and tokenize it with :

	InitializeArray(search_paths, max_paths);

	while(token != NULL){
		InsertStringAt(search_paths, token, curr_pos);
		token = strtok(NULL, delim); // get the next token in the tokenized string
		curr_pos += 1;
	}

	*num_paths = curr_pos; // set the num_paths variable in the scope this was called
}