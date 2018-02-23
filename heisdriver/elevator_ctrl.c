#include "illumination.h"
#include "elevator_ctrl.h"
#include "elevator_io.h"

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



void update() {
    setFloorLight();
}


//////////////////////////////////////////////////////////////////////
//HERIFRA OG NED IKKE TESTET - IKKE FERDIG
void updateQueue() {
    
}

void addToQueue(int floornumber, int dirnumber) {
    for (int i = 0; i<NUMBER_OF_BUTTONS; i++) {
        if (queue[i][0] == 0) {
            queue[i][0] = floornumber;
            queue[i][1] = dirnumber;
        }
    }
}

void moveQueueForward() {
    for(int i = 1; i < NUMBER_OF_BUTTONS; i++) {
        if(queue[i-1][0] == 0) {
        queue[i-1][0] = queue[i][0];
        queue[i-1][1] = queue[i][1];
        }
    }
    
    /*
    	int newcounter = 0;
	for (int i = 0; i < NUMBER_OF_BUTTONS; i++) {
		if (queue[i] != 0) {
			queue[newcounter] = queue[i];
			newcounter++;
		}
	}
	for (int i = newcounter; i < NUMBER_OF_BUTTONS; i++)
	{
		queue[i] = 0;
	}
    */
    
}

void deleteFromQueue(int floornumber, int dirnumber) {
    for (int i = 0; i < NUMBER_OF_BUTTONS; i++) {
        if (queue[i][0] = floornumber && queue[i][1] == dirnumber) {
            queue[i][0] = queue[i][1] = -1;
        }
    }
}

