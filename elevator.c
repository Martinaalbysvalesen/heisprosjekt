#include "elevator.h"
#include "elev.h"

//Heiskontrolleren må først oppdatere direction, for så å aktivere move() som flytter heisen i riktig retning.

/*Variables*/

elev_motor_direction_t dirn;
int current_floor;


//functions
void move_elevator(){ //Flytter heisen i retningen definert med dirn
    elev_set_motor_direction(dirn);
}

void stop_elevator(){ //Stopper heisen
    elev_set_motor_direction(0);
}

int get_current_floor(){
    current_floor = elev_get_floor_sensor_signal();
    return current_floor;
}

void set_direction(elev_motor_direction_t direction){
    dirn = direction;
}

elev_motor_direction_t getDirection(){
    return dirn;
}
