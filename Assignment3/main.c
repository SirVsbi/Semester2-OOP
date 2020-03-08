#include "ui.h"
#include "botController.h"
#include "bot.h"
#include <string.h>
#include <stdlib.h>

#include <stdio.h>

int main(int argc, char** argv){
    BotRepo bots;
    Bot testBot;
    testBot.serialNumber = 123;
    testBot.energyCapacity = 360;
    strcpy(testBot.specialization, "rombolo");
    strcpy(testBot.state, "asd");
    bots.bots[0] = testBot;

    Bot testBot2;
    addNewBot(&bots, testBot2);
    ui(bots);
    exit(0);


}