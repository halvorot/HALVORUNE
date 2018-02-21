
#include "elevator_ctrl.h"
#include "elevator_io.h"


#define direction_t elev_motor_direction_t
#define UP DIRN_UP
#define DOWN DIRN_DOWN
#define STOP DIRN_STOP


direction_t direction = UP;
int currentFloor = -1;
State_t state = MOVING_UP;
int motorRunning = 1;
int doorOpen = 0;


int getCurrentFloor() {
    return currentFloor;
}
void setCurrentFloor(int floor){
    currentFloor = floor;
}

State_t getState() {
    return state;
}
void setState(State_t s){
    state = s;
    switch (state) {
        case MOVING_UP:
            direction = UP;
            startMotor();
            break;
        case MOVING_DOWN:
            direction = DOWN;
            startMotor();
            break;
        case WAIT:
            direction = STOP;
            stopMotor();
            break;
        case EMERGENCY_STOP: //not in use yet
            break;
    }
}

direction_t getDirection() {
    return direction;
}
void setDirection(direction_t dir){
    direction = dir;
}

int motorIsRunning(){
    return motorRunning;
}

int doorIsOpen(){
    return doorOpen;
}

int getFloorSensor(){
    return elev_get_floor_sensor_signal();
}

void elevatorInitiate(){
    int floor = getFloorSensor();
    if(floor != -1){
        setCurrentFloor(floor);
    }
    else{
        setState(MOVING_UP);
        while(getFloorSensor() == -1){ /*intentionally empty, waits until it reaches floor*/ }
        setState(WAIT);
    }

}


