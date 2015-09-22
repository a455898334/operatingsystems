/**
 *  CSC-1600 Operating Systems
 *  Project 2
 *  myshell.c
 *  Shan Shi
 */

#include "arrayOfStrings.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD 1000
#define MAX_PATHS 1000

int main(){

    const char delim[1] = " ";  // delimeter

    /* As shown in class */
    char * searchpaths[MAX_PATHS];
    int numpaths = 0; // number of directories in path
    char cmd[MAX_CMD];

    SaveSearchPaths(searchpaths, MAX_PATHS, (int *) &numpaths);
    /* End of code from classes */

    while(1){
        printf("myshell > ");
        fflush(stdout);
        fgets(cmd, MAX_CMD, stdin); // get user command
        fflush(stdout);
        char * token;

        /* count the number of arguments (incl the command itself) */
        int num_args = 0;
        token = strtok(cmd, delim); // tokenize the input with spaces
        while(token != NULL){
            token = strtok(NULL, delim); // gets the next token in the tokenized string
            num_args += 1;
        }

        /* tokenize the entry with spaces */
        token = strtok(cmd, delim);
        if(strncmp(cmd, "quit", 5) == 0 || strncmp(cmd, "exit", 5) == 0){ // using 5 so commands like "pathogen" won't validate as path
            if(num_args == 1){  // if the entry was just "quit" or "exit" with nothing following it
                exit(0);
            }else{
                printf("%s doesn't take arguments.\n", cmd);
            }
        }else if(strncmp(cmd, "help", 5) == 0){ // using else if so the program doesn't have to run through all checks every time
            if(num_args == 1){
                printf("No help is available\n");
            }else{
                printf("%s doesn't take arguments.\n", cmd);
            }
        }else if(strncmp(cmd, "path", 5) == 0){
            if(num_args == 1){
                PrintAll(searchpaths, numpaths);
            }else{
                printf("%s doesn't take arguments.\n", cmd);
            }
        }else{
            printf("That's not the command you're looking for.\n");
        }
    }
    return 0;
}