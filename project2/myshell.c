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
        char * token;
        int num_args = 0;
        char * command_array[MAX_CMD];

        printf("myshell > ");
        fgets(cmd, MAX_CMD, stdin); // get user command

        if(strcmp(cmd,"\n")){

            token = strtok(cmd, delim); // tokenize the input with spaces

            InitializeArray(command_array, MAX_CMD); // the command gets tokenized into an array outside and is pased in
            while(token != NULL){
                InsertStringAt(command_array, token, num_args);
                token = strtok(NULL, delim); // gets the next token in the tokenized string
                num_args += 1;
            }

            if(strncmp(command_array[0], "quit", 5) == 0 || strncmp(command_array[0], "exit", 5) == 0){ // using 5 so commands like "pathogen" won't validate as path
                if(num_args == 1){  // if the entry was just "quit" or "exit" with nothing following it
                    exit(0);
                }else{
                    printf("%s doesn't take arguments.\n", command_array[0]);
                }
            }else if(strncmp(command_array[0], "path", 5) == 0){ // print all the paths
                if(num_args == 1){
                    PrintAll(searchpaths, numpaths);
                }else{
                    printf("%s doesn't take arguments.\n", command_array[0]);
                }
            }else{
                mySystem(command_array, num_args, searchpaths, numpaths); // goes through the system paths and tries to run the command in all of them
            }
        }
    }
    return 0;
}