/**
 *  CSC-1600 Operating Systems
 *  Project 2
 *  mySystem.c
 *  Shan Shi
 */

#include "arrayOfStrings.h"

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

/* Take an unknown shell command from myshell and try to run that command in the system */
void mySystem(char * command[], int num_args, char *searchpaths[], int numpaths){
	const char delim[1] = " "; // delimeter is a space, null, or newline
	char * token;
	int curr_pos = 0;

	int pID = fork();
	if(pID == 0){
		for(int i = 0; i < numpaths; i++){
			char * fullcmd = malloc(strlen(searchpaths[i] + strlen(command[0]) + 2));
			sprintf(fullcmd, "%s/%s", searchpaths[i], command[0]);
			execv(fullcmd, command);
			free(fullcmd);
		}
		printf("Unknown command.\n");
		exit(0);
	}
	wait(NULL);
}