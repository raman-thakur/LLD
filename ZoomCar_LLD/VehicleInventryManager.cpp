#include "VehicleInventryManager.h"

Car::Car()
{
    this->status=unreserved;
    this->type=car;
    this->id=1;
}

Bike::Bike()
{
    this->status=unreserved;
    this->id=2;
    this->type=bike;
}

VehicleInventryManager::VehicleInventryManager(vector<Vehicle> lov)
{
    this->listofvehicle=lov;
}

void VehicleInventryManager::print_vehicle_detail(int ind)
{
    if(ind<(this->listofvehicle.size()))
    {
        cout<<this->listofvehicle[ind].type;
    }
}