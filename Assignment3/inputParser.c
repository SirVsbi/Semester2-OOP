#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include "botController.h"

#define NUMBER_OF_ARGUMENTS_ADD_UPDATE 4
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
    char* commandCopy;
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

int NumberParser(char* token){
    if(token == NULL){
        return -1;
    }

    errno = 0;

    int parsedNumber = strtol(token, NULL, 10);
    if(errno == ERANGE || errno != 0){
        return -1;
    }

    return parsedNumber;

}


Bot* botArgumentParser(char* command){
    int serialNumber;
    char state[100];
    char specialization[100];
    int energyCapacity;

    int argumentParsingIndex;

    char* commandCopy;
    strcpy(commandCopy, command);
    char* tokens = strtok(commandCopy, delimiter);
    tokens = strtok(NULL, delimiter);

    //parse the serial number
    serialNumber = NumberParser(tokens);
    if(serialNumber == -1){
        return NULL;
    }

    //parse the state
    tokens = strtok(NULL, delimiter);
    if(tokens == NULL){
        return NULL;
    }
    strcpy(state, tokens);

    //parse the specialization
    tokens = strtok(NULL, delimiter);
    if(tokens == NULL){
        return NULL;
    }
    strcpy(specialization, tokens);

    //parse the energy capacity
    tokens = strtok(NULL, delimiter);
    if(tokens == NULL){
        return NULL;
    }
    energyCapacity = NumberParser(tokens);
    if(energyCapacity == -1){
        return NULL;
    }

    Bot* tempBot = (Bot*)malloc(sizeof(Bot));
    setSerialNumber(tempBot, serialNumber);
    setState(tempBot, state);
    setSpecialization(tempBot, specialization);
    setEnergyCapacity(tempBot, energyCapacity);

    return tempBot;

    

    




}


