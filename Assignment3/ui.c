#include "ui.h"
#include "inputParser.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "bot.h"
#include <string.h>

int ui(BotRepo bots){

    char buffer[200];
    int commandValue = 0;
    int botIndex;
    int botRepoLength;
    int deleteArgument;
    int exitCode = 0;
    int deleteResult = 0;
    int specificationCounter = 0;
    char* specialization;
    while(exitCode != 1){
        fflush(stdin);
        fgets(buffer, sizeof buffer, stdin);
        commandValue = commandParser(buffer);
        
        switch (commandValue){
        case 0:
            printf("Bad command, bad user \n");
            break;
        case 1: 
            break;

        /*
            To print all the bots: 
                1.) get the length of the bot repo
                2.) iterate though the bot repo 
        */ 


        case 3: 
            deleteArgument = deleteParser(buffer);
            //handle bad/non-existent argument
            if(deleteArgument == -1){
                printf("There was no serial number given\n");
                break;
            }
            if(deleteArgument == -2){
                printf("There was a problem parsing the input\n");
                break;
            }
            //successful argument parsing 
            botIndex = findBotBySerialNumber(bots, deleteArgument);
            if(botIndex == -1){
                printf("This bot doesn't exist\n");
                break;
            }
            deleteResult = deleteBotByIndex(&bots, botIndex);
            if(deleteResult == 0){
                printf("Something went wrong with the delete \n");
                break;
            }
            else{
                printf("Bot with serial number: %d, deleted!\n", deleteArgument);
            }
            break;
        case 4: 
            specialization = listParser(buffer);
            if(specialization == NULL){
                botRepoLength = bots.length;
                for(botIndex = 0; botIndex < botRepoLength; botIndex++){
                    printBot(bots, botIndex);
                }
            }
            else{
                specificationCounter = 0;
                for(botIndex = 0; botIndex < botRepoLength; botIndex++){
                    if(strcmp(bots.bots[botIndex].specialization, specialization) == 0){
                        printBotSpecification(bots, botIndex, specificationCounter);
                        specificationCounter++;
                    }
                }
                if(specificationCounter == 0){
                    printf("There are no bots with this specification \n");
                }
            }
            break;
        case 5:
            fflush(stdin);
            exitCode = 1;
            break;
        default:
            printf("Bad command, bad user \n");
        }
    }

    return 0;


}



void printBot(BotRepo bots, int index){
    Bot currentBot = bots.bots[index];
    printf("Current bot index: %d \n", index);
    printf("Serial number: %d \n", getSerialNumber(currentBot));
    printf("State: %s \n", currentBot.state);
    printf("Specialization: %s\n", getSpecialization(currentBot));
    printf("Energy capacity: %d\n", getEnergyCapacity(currentBot));
    


} 


void printBotSpecification(BotRepo bots, int repoIndex, int counterIndex){
    Bot currentBot = bots.bots[repoIndex];
    printf("Current bot index: %d \n", counterIndex);
    printf("Serial number: %d \n", getSerialNumber(currentBot));
    printf("State: %s \n", currentBot.state);
    printf("Specialization: %s\n", getSpecialization(currentBot));
    printf("Energy capacity: %d\n", getEnergyCapacity(currentBot));
    


} 