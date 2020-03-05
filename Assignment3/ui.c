#include "ui.h"
#include "inputParser.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void ui(){

    char buffer[200];
    int commandValue = 0;
    while(1){
        fflush(stdin);
        fgets(buffer, sizeof buffer, stdin);
        commandValue = commandParser(buffer);
        printf("%d %s\n", commandValue, buffer);


        

    }


}