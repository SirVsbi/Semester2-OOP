#include "bot.h"
#include "botController.h"

int getBotsLength(BotRepo bots){
    return bots.length;
}

Bot getBotByIndex(BotRepo bots,int index){
    return bots.bots[index];
}

int findBotBySerialNumber(BotRepo bots, int serialNumber){
    int botIndex;
    for(botIndex = 0;botIndex < bots.length; botIndex++){
        if(bots.bots[botIndex].serialNumber == serialNumber){
            return botIndex;
        }
    }
    return -1;
}


/*
    Deletes a bot from static memory by overwriting it 

*/
int deleteBotByIndex(BotRepo* bots, int index){
    if(index > (*bots).length){
        return 0;
    }
    int deleteIndex;
    for(deleteIndex = index; deleteIndex < (*bots).length - 1; deleteIndex++){
        (*bots).bots[deleteIndex] = (*bots).bots[deleteIndex + 1];
    }
    (*bots).length--;
    return 1;


}


int isBotInsertable(BotRepo* bots, Bot newBot){
    int botIndex;
    for(botIndex = 0; botIndex < (*bots).length; botIndex++){
        if((*bots).bots[botIndex].serialNumber == newBot.serialNumber){
            return 0;
        }
    }
    return 1;

}

int addNewBot(BotRepo* bots, Bot newBot){
    
    if(isBotInsertable(bots, newBot) == 0)
        return 0;
    (*bots).bots[(*bots).length] = newBot;
    (*bots).length++;
    return 1;
}


int isBotInRepo(BotRepo* bots, int serialNumber){
    int botIndex;
    for(botIndex = 0; botIndex < (*bots).length; botIndex++){
        if((*bots).bots[botIndex].serialNumber == serialNumber){
            return botIndex;
        }
    }
    return -1;

}

int updateBot(BotRepo* bots, Bot updateBot){
    int botPosition = isBotInRepo(bots, updateBot.serialNumber);
    if(botPosition== -1){
        return 0;
    }
    (*bots).bots[botPosition] = updateBot;
    return 1;
}