#include "elev.h"
#include <stdio.h>

typedef enum {MOVE_UP, MOVE_DOWN, STOP_ELEVATOR} states;

typedef enum {FLOOR_0, FLOOR_1, FLOOR_2, FLOOR_3} floor_states;

void illuminate_floor_lights();

void update();

void go_to_floor(int floor);

void check_elevator_panel_buttons();