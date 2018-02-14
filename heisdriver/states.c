#include "states.h"

static int CURRENTFLOOR = -1;

static states state;
static floor_states floor_state;


/*void illuminate_floor_lights(void) {
    CURRENTFLOOR = elev_get_floor_sensor_signal();
    if (CURRENTFLOOR!=-1) {
        elev_set_floor_indicator(CURRENTFLOOR);
    }
}*/

//illuminates current floor based on floor_state
void illuminate_floor_lights(void){
        switch(floor_state){
        case FLOOR_0:
        elev_set_floor_indicator(0);
        break;
        case FLOOR_1:
        elev_set_floor_indicator(1);
        break;
        case FLOOR_2:
        elev_set_floor_indicator(2);
        break;
        case FLOOR_3:
        elev_set_floor_indicator(3);
        break;
    }
}

//checks buttons and acts accordingly
void update() {
    //updates current floor and floor state
    if(elev_get_floor_sensor_signal()!=-1){
        CURRENTFLOOR = elev_get_floor_sensor_signal();
        floor_state = CURRENTFLOOR;
    }

    //changes direction when top and bottom floors are reached
    if (elev_get_floor_sensor_signal() == N_FLOORS - 1) {
            elev_set_motor_direction(DIRN_DOWN);
            state = MOVE_DOWN;
    } else if (elev_get_floor_sensor_signal() == 0) {
            elev_set_motor_direction(DIRN_UP);
            state = MOVE_UP;
    }

    //sets motor direction according to state
    switch(state){
        case MOVE_UP:
        elev_set_motor_direction(DIRN_UP);
        break;
        case MOVE_DOWN:
        elev_set_motor_direction(DIRN_DOWN);
        break;
        case STOP_ELEVATOR:
        elev_set_motor_direction(DIRN_STOP);
        break;
    }

    //sets floor indicator light
    illuminate_floor_lights();

    check_elevator_panel_buttons();

}

void go_to_floor(int floor){
  
    if(CURRENTFLOOR > floor && state == MOVE_UP){
        state = MOVE_DOWN;
    }
    else if(CURRENTFLOOR < floor && state == MOVE_DOWN){
        state = MOVE_UP;
    }
}

//DETTE FUNKER IKKE
void check_elevator_panel_buttons() {
    for (int i=0;i<N_FLOORS;i++) {
        if (elev_get_button_signal(BUTTON_COMMAND, i)) {
            go_to_floor(i);
        }
        if (i == elev_get_floor_sensor_signal()) {
            state = STOP_ELEVATOR;
        }
    }
}