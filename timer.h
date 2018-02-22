//
//  timer.h
//  Heisprosjekt
//
//  Created by Thomas Hellum on 15/02/18.
//  Copyright © 2018 Thomas Hellum. All rights reserved.
//

#ifndef timer_h
#define timer_h

#include <stdio.h>
#include <stdbool.h>
//#include <"elev.h"> //skal brukes

#define TIMEOUT_PERIOD_SECONDS 3


void timer_init( void );

void timer_reset( void );

bool timed_out( void );

#endif // #ifndef __TIMER_H__



/* kun for testing. Skal fjernes*/
/*
typedef enum tag_elev_motor_direction {
    DIRN_DOWN = -1,
    DIRN_STOP = 0,
    DIRN_UP = 1
} elev_motor_direction_t;



void countdown(int sec);
void coudown_stop(int dirn);



#endif /* timer_h */
