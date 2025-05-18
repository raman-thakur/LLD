
#include "transport_vehicle.h"
#include <iostream>
using namespace std;

Transport_Vehicle::Transport_Vehicle(Drive_Strategy *par)
{
    obj=par;
}