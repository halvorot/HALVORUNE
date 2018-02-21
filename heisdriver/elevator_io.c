#include "elevator_io.h"
#include "elevator_ctrl.h"
#include "elev.h"


void startMotor() {
    elev_set_motor_direction(getDirection());
}

void stopMotor() {
    elev_set_motor_direction(STOP);
}

void openDoor(){
    elev_set_door_open_lamp(1);
}

void closeDoor(){
    elev_set_door_open_lamp(0);
}


