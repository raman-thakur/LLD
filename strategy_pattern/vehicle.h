#pragma once
#include "drive_strategy.h"

class Vehicle{
    public:
        Drive_Strategy *obj;
        void display();
        Vehicle();
        void drive();
};