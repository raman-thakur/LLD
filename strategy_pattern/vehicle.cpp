#include <iostream>
#include "vehicle.h"
using namespace std;

void Vehicle::display(){
    cout<<"parent class vehicle display\n";
};

void Vehicle::drive(){
    obj->drive_method();
};

Vehicle::Vehicle()
{
    
}