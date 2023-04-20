#include <stdio.h>
#include <string.h>
#include <time.h>
 
void delay(int mili_seconds){

    clock_t start_time = clock();
    while (clock() < start_time + 1000 * mili_seconds)
        ;
}