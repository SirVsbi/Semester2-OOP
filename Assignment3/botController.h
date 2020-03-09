#include "bot.h"
#pragma once
#ifndef BOTCONTROLLER_H


typedef struct{
    Bot bots[100];
    int length;
} BotRepo;


/*
    Returns the length of the bot repo 
*/
int getBotsLength(BotRepo);


/*
    Returns a bot by a given index 
*/
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


/*
    Returns 1 if a given bot can be inserted into the BotRepo
    Returns 0 otherwise
*/
int isBotInsertable(BotRepo*, Bot);

/*
    Inserts a new bot into the BotRepo 
    Returns 1 if the insert was successful 
    Returns 0 otherwise 
*/
int addNewBot(BotRepo*, Bot);

/*
    Updates a bot with a given serial number
    Returns 1 if the update was successful
    Returns 0 if the bot is not in the repo 
*/
int updateBot(BotRepo*, Bot);

/*
    Finds a bot in the BotRepo
    Returns the index of the bot
    Returns -1 if bot is not in the repo 

*/
int isBotInRepo(BotRepo*, int);
#endif

