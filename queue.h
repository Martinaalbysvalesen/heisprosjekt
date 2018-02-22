//
//  queue.h
//  Heisprosjekt
//
//  Created by Thomas Hellum on 15/02/18.
//  Copyright © 2018 Thomas Hellum. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>
#include "elev.h"

#define N_FLOORS 4
#define N_BUTTONS 3


/*typedef enum tag_elev_motor_direction {
    DIRN_DOWN = -1,
    DIRN_STOP = 0,
    DIRN_UP = 1
} elev_motor_direction_t;*/


typedef enum {
    OUT_OF_REACH = -1,
    FIRST = 1,
    SECOND = 2,
    THIRD = 3,
    FOURTH = 4
} floor_nr;


typedef enum {
    UNKNOWN = -1,
    OUTSIDE_UP = 0,
    OUTSIDE_DOWN = 1,
    INSIDE_CALL = 2,
} order_type;






//Alle bestillinger (4 etasjer, 3 type knapper for hver etasje)
//Se floor_nr og order_type for oppsett
//Alle knapper settes til 1 for bestilling og 0 om fullført
static int floor_orders[N_FLOORS][N_BUTTONS];

void set_order(floor_nr floor, order_type button);
int get_order(floor_nr floor, order_type button);
int get_next(floor_nr current_floor, elev_motor_direction_t dirn);



//Fjerne bestillinger
void remove_order(floor_nr floor, elev_motor_direction_t dirn);
void clear_all();






#endif /* queue_h */
