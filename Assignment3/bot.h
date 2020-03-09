#pragma once
#ifndef BOT_H
#define BOT_H


typedef struct{
    int serialNumber;
    char state[100];
    char specialization[100];
    int energyCapacity;


} Bot;

/*
    Returns a bot's serial number
*/
int getSerialNumber(Bot);

/*
    Returns a bot's state
*/
char* getState(Bot);

/*
    Returns a bot's specialization
*/
char* getSpecialization(Bot);

/*
    Returns a bot's energy capacity 
*/
int getEnergyCapacity(Bot);


/*
    Sets a bot's serial number tdo a given serial number
*/
void setSerialNumber(Bot*, int);

/*
    Sets a bot's state to a given state
*/
void setState(Bot*, char*);

/*
    Sets a bot's specialization to a given specialization
*/
void setSpecialization(Bot*, char*);

/*
    Sets a bot's energy capacity to a given energy capacity 
*/
void setEnergyCapacity(Bot*, int);





#endif 