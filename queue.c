//
//  queue.c
//  Heisprosjekt
//
//  Created by Thomas Hellum on 15/02/18.
//  Copyright © 2018 Thomas Hellum. All rights reserved.
//

#include "queue.h"
#include "elev.h"




//Alle bestillinger (4 etasjer, 3 type knapper for hver etasje)
//Se floor_nr og order_type for oppsett
//Alle knapper settes til 1 for bestilling og 0 om fullført
void set_order(floor_nr floor, order_type button){
    floor_orders[floor][button] = 1;
}


int get_order(floor_nr floor, order_type button){
    return floor_orders[floor][button];
}



static int run_count;   //rekursjonsteller

int get_next(floor_nr current_floor, elev_motor_direction_t dirn){
    int next_floor = current_floor;
    
    if (run_count < 2){     //Sørger for at funksjonen ikke rekurserer mer enn 2 ganger (opp og ned)
        switch (dirn) {
            case DIRN_UP:
                while (next_floor < N_FLOORS + 1){
                    next_floor++;
                    if (floor_orders[next_floor][OUTSIDE_UP] == 1 || floor_orders[next_floor][INSIDE_CALL] == 1){
                        run_count = 0;      //nullstiller rekursjonsteller
                        return next_floor;   //returnerer den første etasje den finner 1=bestilling i samme bevegelsesretning
                    }
                    if (next_floor >= 3){        //Sjekker om kommet til ytterpunkt forutsatt ingen bestilling
                        run_count++;
                        get_next(current_floor, DIRN_DOWN);     //bruker en rekursiv løsning
                    }
                }
                break;
            
            case DIRN_DOWN:
                while (next_floor > 0){
                    next_floor--;
                    if (floor_orders[next_floor][OUTSIDE_DOWN] == 1 || floor_orders[next_floor][INSIDE_CALL] == 1){
                        run_count = 0;      //nullstiller rekursjonsteller
                        return next_floor;   //returnerer den første etasje den finner 1=bestilling i samme bevegelsesretning
                    }
                    if (next_floor <= 0){        //Sjekker om kommet til ytterpunkt forutsatt ingen bestilling
                        run_count++;
                        get_next(current_floor, DIRN_UP);
                    }
                }
                break;
                
            case DIRN_STOP:
                get_next(current_floor, DIRN_UP); //Dersom stoppet, sjekker først retning opp som default
                break;
            default:
                break;
        }
    }
    run_count = 0;
    return -1;
}




//Fjerne etasjer
void remove_order(floor_nr floor, elev_motor_direction_t dirn){
    floor_orders[floor][INSIDE_CALL] = 0;
    if(dirn == DIRN_UP){
        floor_orders[floor][OUTSIDE_UP] = 0;
    }
    if (dirn == DIRN_DOWN){
        floor_orders[floor][OUTSIDE_DOWN] = 0;
    }
}


void clear_all(){
    for(int i; i < N_FLOORS; i++){
        floor_orders[i][OUTSIDE_DOWN] = 0;
        floor_orders[i][OUTSIDE_UP] = 0;
        floor_orders[i][INSIDE_CALL] = 0;
    }
}






