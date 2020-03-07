#pragma once
#ifndef BOT_H
#define BOT_H


typedef struct{
    int serialNumber;
    char state[100];
    char specialization[100];
    int energyCapacity;


} Bot;


int getSerialNumber(Bot);
char* getState(Bot);
char* getSpecialization(Bot);
int getEnergyCapacity(Bot);

void setSerialNumber(Bot, int);
void setState(Bot, char*);
void setSpecialization(Bot, char*);
void setEnergyCapacity(Bot, int);




#endif 