#include "elevator_io.h"
#include "elevator_ctrl.h"
#include "elev.h"


void startMotor() {
    direction_t dir = getDirection();
    elev_set_motor_direction(dir);
    if(dir == UP){
        setState(MOVING_UP);
    } 
    else if (dir == DOWN){
        setState(MOVING_DOWN);
    }
}

void stopMotor() {
    elev_set_motor_direction(STOP);
    setState(WAIT);
}

void openDoor(){
    elev_set_door_open_lamp(1);
}

void closeDoor(){
    elev_set_door_open_lamp(0);
}


