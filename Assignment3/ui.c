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
    int addResult = 0;
    int updateResult = 0;
    Bot* tempBot;
    tempBot = (Bot*)malloc(sizeof(Bot));


    while(exitCode != 1){
        fflush(stdin);
        fgets(buffer, sizeof buffer, stdin);
        commandValue = commandParser(buffer);
        switch (commandValue){
        case 0:
            printf("Bad command, bad user \n");
            break;
        case 1: 
            addResult = 0;
            tempBot = botArgumentParser(buffer);
            if(tempBot == NULL){
                printf("Invalid type of input\n");
                break;
            }
            else{
                addResult = addNewBot(&bots, *tempBot);
                if(addResult == 0){
                    printf("No!\n");
                    break;
                }
                else{
                    printf("New bot successfuly added\n");
                    break;
                }
            }
            break;
        case 2: 
            updateResult = 0;
            tempBot = botArgumentParser(buffer);
            if(tempBot == NULL){
                printf("Invalid type of input\n");
            }
            else{
                updateResult = updateBot(&bots, *tempBot);
                if(updateResult == 0){
                    printf("A bot with this serial number doesn't exists\n");
                    break;
                }
                else{
                    printf("Bot updated successfuly\n");
                    break;
                }
            }
            break;
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
                printf("No!\n");
                break;
            }
            deleteResult = deleteBotByIndex(&bots, botIndex);
            if(deleteResult == 0){
                printf("No!");
                break;
            }
            else{
                printf("Bot with serial number: %d, deleted!\n", deleteArgument);
            }
            break;
        case 4: 
            botRepoLength = bots.length;
            specialization = listParser(buffer);
            if(specialization == NULL){
                for(botIndex = 1; botIndex < botRepoLength; botIndex++){
                    printBotRepository(bots, botIndex);
                }
            }
            else{
                specificationCounter = 0;
                for(botIndex = 1; botIndex < botRepoLength; botIndex++){
                    if(strcmp(bots.bots[botIndex].specialization, specialization) == 0){
                        printBotRepositorySpecification(bots, botIndex, specificationCounter);
                        specificationCounter++;
                    }
                }
                if(specificationCounter == 0){
                    printf("There are no bots with this specification \n");
                }
            }
            break;
        case 5:
            // fflush(stdin);
            exitCode = 1;
            free(tempBot);
            exit(0);
            break;
        default:
            printf("Bad command, bad user \n");
        }
    }
    return 0;
}



void printBotRepository(BotRepo bots, int index){
    Bot currentBot = bots.bots[index];
    printf("Serial number: %d \n", getSerialNumber(currentBot));
    printf("State: %s \n", currentBot.state);
    printf("Specialization: %s\n", currentBot.specialization);
    printf("Energy capacity: %d\n", getEnergyCapacity(currentBot));
    
} 


void printBotRepositorySpecification(BotRepo bots, int repoIndex, int counterIndex){
    Bot currentBot = bots.bots[repoIndex];
    printf("Serial number: %d \n", getSerialNumber(currentBot));
    printf("State: %s \n", currentBot.state);
    printf("Specialization: %s\n", currentBot.specialization);
    printf("Energy capacity: %d\n", getEnergyCapacity(currentBot));

} 