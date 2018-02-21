#include "elev.h"
#include "elevator_ctrl.h"


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

void elevatorInitiate(){

}


