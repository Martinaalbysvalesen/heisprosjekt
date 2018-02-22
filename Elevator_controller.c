//
//  Elevator_controller.c
//  Heisprosjekt_v2
//
//  Created by Martin Aalby Svalesen on 19.02.2018.
//  Copyright © 2018 Martin Aalby Svalesen. All rights reserved.
//

#include "Elevator_controller.h"
#include "button.h"
#include "door.h"
#include "timer.h"
#include "queue.h"
#include "elevator.h"
#include <stdlib.h>

void stop_function(){
    stop_elevator();
    clear_all();
    illuminate_stop_button();
    timer_reset();
    if(get_current_floor!=-1){
        open_door();
    }
}



void elevator_controller(){
    static int previousFloor = -1;
    static int currentFloor;
    static int nextFloor;
    static elev_motor_direction_t dirn = 0; //rotete å ha denne to steder?
    
    while(1){
        //iterere og sjekke igjennom alle knapper, dersom knapp trykket på, aktivér lyset på denne
        //oppdatere buttonarray
        for(int floor = 0; floor < N_FLOORS; floor++){
            for(int button=-1;button<N_BUTTONS;button++){
                if(get_button_signal(floor,button)){
                    illuminate_button(floor,button);    //Må antageligvis endres //lyser opp bestillingsknapper
                    set_order(floor,button);            //setter inn bestilling i set order
                }
            }
        }
        
        //sjekke stoppknapp, aktivere stoppfunksjon hvis trykket
        if(check_stop_button()){
            stop_function();
        }
        
        //sjekker om heisen har kommet til ny etasje
        currentFloor = get_current_floor(); //mulig disse må settes utenfor funksjon som static
        if((currentFloor != previousFloor)&&(currentFloor != -1)){
            illuminate_floor_indicator(currentFloor);
            
            //sjekke om etasje er bestilt
            if(floor_orders[currentFloor][dirn] == 1 || floor_orders[currentFloor][INSIDE_CALL] == 1){
                timer_reset();
                open_door();
                remove_order(currentFloor, dirn);
                cancel_illuminate_button(dirn, currentFloor); //må antageligvis endres
            }
            
            //logikk for å sette retning i forhold til neste etasje
            nextFloor = getNext(currentFloor, dirn);
            if (nextFloor == -1){
                set_direction(DIRN_STOP);
            }
            else if (nextFloor > currentFloor){
                set_direction(DIRN_UP);
            }
            else if(nextFloor < currentFloor){
                set_direction(DIRN_DOWN);
            }
            else{
                printf("Error");
            }
        }
        
        //oppdaterer etasje for å kunne sjekke opp mot neste iterasjon
        previousFloor = currentFloor;
        
        
        //når timer er ferdig
        if(timed_out() && nextFloor != 0){ //skal det være -1?
            close_door();
            move_elevator();
            cancel_illuminate_stop_button();
        }
        
            
    }
}
