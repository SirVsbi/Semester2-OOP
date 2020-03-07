#include "bot.h"
#include <string.h>

int getSerialNumber(Bot currentBot){
    return currentBot.serialNumber;
}

char* getState(Bot currentBot){
    char* returnState;
    returnState = currentBot.state;
    return returnState;
}

char* getSpecialization(Bot currentBot){
    char* returnString;
    returnString = currentBot.specialization;
    return returnString;
}

int getEnergyCapacity(Bot currentBot){
    return currentBot.energyCapacity;
}

void setSerialNumber(Bot currentBot, int newSerialNumber){
    currentBot.serialNumber = newSerialNumber;

}

void setState(Bot currentBot, char* newState){
    strcpy(currentBot.state, newState);

}

void setSpecialization(Bot currentBot, char* newSpecialization){
    strcpy(currentBot.specialization, newSpecialization);
}

void setEnergyCapacity(Bot currentBot, int newEnergyCapacity){
    currentBot.energyCapacity = newEnergyCapacity;
}
