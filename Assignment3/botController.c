#include "bot.h"
#include "botController.h"

int getBotsLength(BotRepo bots){
    return bots.length;
}

Bot getBotByIndex(BotRepo bots,int index){
    return bots.bots[index];
}

int findBotBySerialNumber(BotRepo bots, int serialNumber){
    int i;
    for(i = 0;i < bots.length; i++){
        if(bots.bots[i].serialNumber == serialNumber){
            return i;
        }
    }
    return -1;
}


/*
    Deletes a bot from static memory by overwriting it 

*/
int deleteBotByIndex(BotRepo* bots, int index){;
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