#include <string.h>



#include <stdio.h>

#define COMMAND_NUMBER 5
const char* commands[COMMAND_NUMBER] = {"add", "update", "delete", "list", "exit"};
const char* delimiter = " ,\n\r";

int commandParser(char* command){
    char* commandCopy;
    strcpy(commandCopy, command);

    char* token = strtok(commandCopy, delimiter);
    int index;
    printf("%s \n", token);
    for(index = 0; index < COMMAND_NUMBER; index++){

        if(strcmp(token, commands[index]) == 0){
            return index + 1;
        } 
    }
    return 0;
}