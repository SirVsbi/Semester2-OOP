#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int i;
// This swap only works with gcc on GNU/linux
/*
static inline volatile void swap(volatile int firstNumber,volatile int secondNumber){
    asm ("" : "=r" (firstNumber), "=r" (secondNumber) : "0" (secondNumber), "1" (firstNumber) :);
}
*/



void swap(int *firstNumber, int *secondNumber){
    int temp;
    temp = *secondNumber;
    *secondNumber = *firstNumber;
    *firstNumber = temp;

}



int isPrime(int number){

    int divisor = 2;
    if(number < 2){
        return 0;
    }
    for(divisor; divisor < number / 2; ++divisor){
        if(number % divisor == 0){
            return 0;
        }
    }
    return 1;
}


int isDifferencePrime(int firstNumber, int secondNumber){
    if(firstNumber < secondNumber){
        swap(&firstNumber, &secondNumber);
    }

    int number = firstNumber - secondNumber;
    return isPrime(number);
}


void findLongestSequence(int* numbers, int numberofNumbers){

    int longest = 1;
    int actual_longest = 1;
    int startIndex = 0;

    for(i = 1; i < numberofNumbers; i++){
        if(isDifferencePrime(numbers[i], numbers[i - 1]) == 1){
            actual_longest++;
        }
        else{
            if(actual_longest > longest){
                longest = actual_longest;
                startIndex = i - longest;
            }
        }
    }


    
    for(i = 0; i < longest; i++){
        printf("%d ", numbers[i + startIndex]);
    }

}



int main(int argc, char** argv){


    char buffer[100];
    int numberOfNumbers = 0;

    int* numbers;
    numbers = malloc(100 * sizeof(int));
    while(strcmp("exit", buffer) != 0){
        numberOfNumbers = 0;
        
        fgets(buffer, sizeof buffer, stdin);
        char* tokens = strtok(buffer, " \n\r");
        numbers[numberOfNumbers++] = strtol(tokens, NULL, 10);
        while(tokens != NULL){
            numbers[numberOfNumbers++] = strtol(tokens, NULL, 10);
            tokens = strtok(NULL, " \n\r");
        }
        findLongestSequence(numbers, numberOfNumbers);
    }
    return 0;









}