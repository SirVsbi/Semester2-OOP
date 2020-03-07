#include "bot.h"
#pragma once
#ifndef BOTCONTROLLER_H


typedef struct{
    Bot bots[100];
    int length;
} BotRepo;


int getBotsLength(BotRepo);
Bot getBotByIndex(BotRepo, int);


/*
    Returns the index of a bot with a given serial number 
    If the bot is not found, returns -1
*/ 
int findBotBySerialNumber(BotRepo, int);

/*
    Delets a bot from the repository given it's index
    Returns 1 if delete was succesful
    Returns 0 otherwise
*/ 
int deleteBotByIndex(BotRepo*, int);

#endif