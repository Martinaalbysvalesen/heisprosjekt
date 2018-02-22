//
//  timer.c
//  Heisprosjekt
//
//  Created by Thomas Hellum on 15/02/18.
//  Copyright © 2018 Thomas Hellum. All rights reserved.
//

#include "timer.h"
#include "time.h" //bibliotek for tid



static clock_t timeout_time;

void timer_init( void ) {
    timeout_time = 0;
}

void timer_reset( void ) {
    timeout_time = clock() + TIMEOUT_PERIOD_SECONDS * CLOCKS_PER_SEC;
}

bool timed_out( void ) {
    return (clock() >= timeout_time);
}







/*Busy wait... ikke ønsket*/
/*
void countdown(int sec) { //setter ønsket nedtellingstid
    int msec_start = 0;
    sec = sec * 1000;
    clock_t before = clock();
    
    do {
        clock_t difference = clock() - before;
        msec_start = difference * 1000 / CLOCKS_PER_SEC;
    } while ( msec_start < sec );
    
    // kun med til test
    printf("Time taken %d seconds %d milliseconds\n",
           msec_start/1000, msec_start%1000);
    
}




void countdown_stop(int dirn){
    int it; //skal fjernes
    int msec_start = 0;
    clock_t before = clock();
    
    
    while(dirn == DIRN_STOP) {
        
        clock_t difference = clock() - before;
        msec_start = difference * 1000 / CLOCKS_PER_SEC;
        
        //alt mellom skal endres
        
        it++;
        if(it == 10000){
            dirn = 1;
            countdown(3+(msec_start));
        }
        
        //alt mellom skal endres
    }
}
*/





