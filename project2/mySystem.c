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
	int pID = fork(); // fork a child so execv can repace the running code of the child
	if(pID == 0){ // if this is the child
		for(int i = 0; i < numpaths; i++){ // try all of the paths
			/* (copied from lab instructions) creates the string [path]/[command]  */
			char * fullcmd = malloc(strlen(searchpaths[i] + strlen(command[0]) + 2));
			sprintf(fullcmd, "%s/%s", searchpaths[i], command[0]);
			// if the command runs, the child process is replaced by the system command, and will die naturally
			execv(fullcmd, command);
			// if the command fails, free the child and loop back again
			free(fullcmd);
			/* end of copied code */
		}
		// if none of the paths have run, the command is not known, tell the user that and kill the chold
		printf("Unknown command.\n");
		exit(0);
	}
	wait(NULL);//the parent will wait for the child to finish before going back
}