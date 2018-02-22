#include "button.h"
#include "queue.h"


//variables


int illuminated_buttons[N_FLOORS][N_BUTTONS];   //inneholder en oversikt over hvilke knapper som er trykket inn og
                                                //ikke, 0 = nedlys
                                                //1 = etasjebestilling 2 = opp

//functions
void illuminate_button(int floor, int button){ //sjekke om denne funker
    elev_set_button_lamp(button+1,floor,1);
    illuminated_buttons[floor][button+1]=1;
}

void cancel_illuminate_button(int floor, int button){ //sjekke om den funker
    elev_set_button_lamp(button, floor,0);
    illuminated_buttons[floor][button+1] = 0;
}

void illuminate_floor_indicator(int floor){ //etasjeindikator, et lys av gangen er på, skrur man på det ene så skrur man av et annet
    elev_set_floor_indicator(floor);
}

int get_button_signal(int button, int floor){ //sjekker om en knapp er trykket inn
    return elev_get_button_signal(button,floor);
}


int check_stop_button(){
    return elev_get_stop_signal();
}

void illuminate_stop_button(){
    elev_set_stop_lamp(1);
}

void cancel_illuminate_stop_button(){
    elev_set_stop_lamp(0); 
}


