#include "elev.h"

const int NUMBER_OF_BUTTONS = NUMBER_OF_FLOORS*3-2; //Dette blir riktig

typedef enum {
    MOVING_UP, 
    MOVING_DOWN, 
    WAIT, 
    EMERGENCY_STOP
} State_t;

int queue[NUMBER_OF_BUTTONS][2] = {{-1}};
//{ {0,0} {0,0} {0,0} {0,0} ...}
//{ {floor(0..3, empty=-1), typeOfButton(OPP=0,NED=1,BESTILLING=2)}, {..,..} ...}

#define direction_t elev_motor_direction_t
#define UP DIRN_UP
#define DOWN DIRN_DOWN
#define STOP DIRN_STOP

#define button_t elev_button_type_t



#define NUMBER_OF_FLOORS 4
#define TOP_FLOOR NUMBER_OF_FLOORS-1
#define BOTTOM_FLOOR 0

int getCurrentFloor();
void setCurrentFloor(int floor);

State_t getState();
void setState(State_t s);

direction_t getDirection();
void setDirection(direction_t dir);

int motorIsRunning();
int doorIsOpen();
int elevatorIsInFloor();

void elevatorInitiate();

void update();

///////////////////////////////////////////////////////////////
//Endre fra int dirnumber til button_t og fiks funk
void updateQueue();
void addToQueue(int floornumber, int dirnumber);

void moveQueueForward();

void deleteFromQueue(int floornumber, int dirnumber);