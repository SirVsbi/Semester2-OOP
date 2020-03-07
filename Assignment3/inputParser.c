#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include "botController.h"


#define COMMAND_NUMBER 5
const char* commands[COMMAND_NUMBER] = {"add", "update", "delete", "list", "exit"};
const char* delimiter = " ,\n\r";

int commandParser(char* command){
    if(strlen(command) < 3){
        return 0;
    }
    char* commandCopy;
    strcpy(commandCopy, command);

    char* token = strtok(commandCopy, delimiter);
    int index;
    for(index = 0; index < COMMAND_NUMBER; index++){
        if(strcmp(token, commands[index]) == 0){
            return index + 1;
        } 
    }
    return 0;
}


int addParser(char* command, BotRepo bots){




}


char* listParser(char* command){
    char* commandCopy; 
    strcpy(commandCopy, command);
    char* token = strtok(commandCopy, delimiter);
    token = strtok(NULL, delimiter);
    if(token == NULL){
        return NULL;
    }
    else{
        return token;
    }

}


int deleteParser(char* command){
    int parsedInput; 
    char* commandCopy, endpointer;
    strcpy(commandCopy, command);
    char* token = strtok(commandCopy, delimiter);
    token = strtok(NULL, delimiter);

    if(token == NULL){
        return -1;
    }

    errno = 0;
    parsedInput = strtol(token, NULL, 10);
    if(errno == ERANGE || errno != 0){
        return -2;
    }

    return parsedInput;

    
}