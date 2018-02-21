#include "illumination.h"
#include "elev.h"
#include "elevator_io.h"
#include "elevator_ctrl.h"


void setFloorLight() {
    if (getFloorSensor() != -1) {
         setCurrentFloor(getFloorSensor());
    }

    elev_set_floor_indicator(getCurrentFloor());
}


