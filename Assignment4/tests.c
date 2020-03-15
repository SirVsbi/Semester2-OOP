#include <string.h>
#include <assert.h>
#include "ui.h"
#include "botController.h"
#include "bot.h"

#include "test.h"


void test_botModel_setSerialNumber(Bot bot){
    setSerialNumber(&bot, 11);
    assert(bot.serialNumber == 11);
}

void test_botModel_setState(Bot bot){
    setState(&bot, "fasz");
    assert(strcmp(bot.state, "fasz") == 0);
}

void test_botModel_setSpecialization(Bot bot){
    setSpecialization(&bot, "fasz");
    assert(strcmp(bot.specialization, "fasz") == 0);

}

void test_botModel_setEnergyCapacity(Bot bot){
    setEnergyCapacity(&bot, 11);
    assert(bot.energyCapacity == 11);

}


void test_botModel_getSerialNumber(Bot bot){
    int serialNumber = getSerialNumber(bot);
    assert(serialNumber == 123);
}

void test_botModel_getState(Bot bot){
    char* state = getState(bot);
    assert(strcmp(state, "asd") == 0);
}

void test_botModel_getSpecialization(Bot bot){
    char* specialization = getSpecialization(bot);
    assert(strcmp(specialization, "Van") == 0);

}

void test_botModel_getEnergyCapacity(Bot bot){
    int energyCapacity = getEnergyCapacity(bot);
    assert(bot.energyCapacity == 360);

}

void test_BotRepo_getBotsLength(BotRepo botRepo){
    assert(getBotsLength(botRepo) == 1);

}

void test_BotRepo_getBotByIndex(BotRepo botRepo){
    Bot temp = getBotByIndex(botRepo, 0);
    assert(temp.serialNumber == 123);

}

void test_BotRepo_findBotBySerialNumber_Valid(BotRepo botRepo, int serialNumber){
    assert(findBotBySerialNumber(botRepo, serialNumber) == 0);
}

void test_BotRepo_findBotBySerialNumber_Invalid(BotRepo botRepo, int serialNumber){
    assert(findBotBySerialNumber(botRepo, serialNumber) == -1);
}

void test_BotRepo_isBotInsertable_Valid(BotRepo botRepo, Bot bot){
    assert(isBotInsertable(&botRepo, bot) == 1);
}

void test_BotRepo_isBotInsertable_Invalid(BotRepo botRepo, Bot bot){
    assert(isBotInsertable(&botRepo, bot) == 0);
}

void test_BotRepo_addNewBot_valid(BotRepo botRepo, Bot bot){
    addNewBot(&botRepo, bot);
    assert(getBotsLength(botRepo) == 2);
}

void test_BotRepo_addNewBot_invalid(BotRepo botRepo, Bot bot){
    addNewBot(&botRepo, bot);
    assert(getBotsLength(botRepo) == 1);
}

void test_BotRepo_updateBot_valid(BotRepo botRepo, Bot bot){
    assert(updateBot(&botRepo, bot) == 1);
}

void test_BotRepo_updateBot_invalid(BotRepo botRepo, Bot bot){
    assert(updateBot(&botRepo, bot) == 0);
}

void test_BotRepo_deleteBot_valid(BotRepo botRepo, Bot bot){
    int botIndex = findBotBySerialNumber(botRepo, bot.serialNumber);
    deleteBotByIndex(&botRepo, botIndex);
    assert(getBotsLength(botRepo) == 0);
}

void test_BotRepo_deleteBot_invalid(BotRepo botRepo, Bot bot){
    int botIndex = findBotBySerialNumber(botRepo, bot.serialNumber);
    deleteBotByIndex(&botRepo, botIndex);
    assert(getBotsLength(botRepo) == 1);
    
}


void testMain(){
    BotRepo bots;
    Bot testBot;
    test_botModel_setSerialNumber(testBot);
    test_botModel_setState(testBot);
    test_botModel_setSpecialization(testBot);
    test_botModel_setEnergyCapacity(testBot);
    testBot.serialNumber = 123;
    testBot.energyCapacity = 360;
    setSpecialization(&testBot, "Van");
    strcpy(testBot.state, "asd");
    test_botModel_setSerialNumber(testBot);
    test_botModel_getState(testBot);
    test_botModel_getSpecialization(testBot);
    test_botModel_getEnergyCapacity(testBot);

    BotRepo botRepo;

    addNewBot(&botRepo, testBot);
    test_BotRepo_getBotByIndex(botRepo);
    test_BotRepo_getBotByIndex(botRepo);
    test_BotRepo_findBotBySerialNumber_Valid(botRepo, 123);
    test_BotRepo_findBotBySerialNumber_Invalid(botRepo, 1);

    test_BotRepo_isBotInsertable_Invalid(botRepo, testBot);
    testBot.serialNumber = 12;
    test_BotRepo_isBotInsertable_Valid(botRepo, testBot);
    test_BotRepo_addNewBot_valid(botRepo, testBot);

    testBot.serialNumber = 123;
    testBot.energyCapacity = 555;
    test_BotRepo_addNewBot_invalid(botRepo, testBot);


    test_BotRepo_updateBot_valid(botRepo, testBot);
    testBot.serialNumber = 11;
    test_BotRepo_updateBot_invalid(botRepo, testBot);
}


