#include "ui.h"
#include "botController.h"
#include "bot.h"
#include <string.h>
#include <stdlib.h>

#include <stdio.h>

int main(int argc, char** argv){
   BotRepo bots;
   /* Bot testBot;
    testBot.serialNumber = 123;
    testBot.energyCapacity = 360;
    setSpecialization(&testBot, "Van");
    strcpy(testBot.state, "asd");
    bots.bots[1] = testBot;
    bots.length = 2;
    Bot testBot2;
    testBot2.serialNumber = 126;
    addNewBot(&bots, testBot2);
    */
   bots.length = 1;
    ui(bots);
    exit(0);


}