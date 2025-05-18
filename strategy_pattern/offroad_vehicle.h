#pragma once
#include "vehicle.h"

class Offroad_Vehicle:public Vehicle{
    public:
    Offroad_Vehicle(Drive_Strategy *par);
};