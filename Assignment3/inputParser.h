#pragma once
#ifndef INPUTPARSER_H
#define INPUTPARSER_H


/*
    Parses the command and returns the code of the command: 
    0 - invalid command 
    1 - add
    2 - update 
    3 - delete 
    4 - list 
    5 - exit 
*/
int commandParser(char* );


/*
    Parses the arguments of the add command
    Returns 1 if the add was successful, 0 otherwise (in case of duplicate)


*/ 
int addParser(char* , BotRepo);


/*
    Parses the specialization given to the list command 
    If no specialization is given, returns NULL 
*/
char* listParser(char* );


/*
    Parses the serialNumber argument of the delete command 
    Returns -1 if the serial number is not found in the botController repository
    Returns -2 if the there was an error parsing the Serial number

*/ 
int deleteParser(char* );




#endif 