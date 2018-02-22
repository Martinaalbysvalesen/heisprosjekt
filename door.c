#include "door.h"
#include "elev.h"
#include <stdbool.h>

//Variable
bool doorOpen; //om døren er åpen eller ikke

//Funksjoner

void open_door(){
    doorOpen = true;
    elev_set_door_open_lamp(1);
}

void close_door(){
    doorOpen = false;
    elev_set_door_open_lamp(0);
}

int check_door_status(){
    return doorOpen;
}
