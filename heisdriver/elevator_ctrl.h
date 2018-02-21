

typedef enum {
    MOVING_UP, 
    MOVING_DOWN, 
    WAIT, 
    EMERGENCY_STOP
} State_t;

#define direction_t elev_motor_direction_t
#define UP DIRN_UP
#define DOWN DIRN_DOWN
#define STOP DIRN_STOP



#define NUMBER_OF_FLOORS 4
#define TOP_FLOOR 3
#define BOTTOM_FLOOR 0


int getCurrentFloor();
void setCurrentFloor(int floor);

State_t getState();
void setState(State_t s);

direction_t getDirection();
void setDirection(direction_t dir);

int motorIsRunning();
int doorIsOpen();

void elevatorInitiate();