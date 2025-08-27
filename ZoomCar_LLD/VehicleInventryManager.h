#pragma once
#include "Vehicle.h"
#include<vector>
#include<iostream>
using namespace std;
class Car:public Vehicle{
public:
    Car();
};

class Bike:public Vehicle{
public:
    Bike();
};

class VehicleInventryManager{
public:
    std::vector<Vehicle> listofvehicle;

    VehicleInventryManager(std::vector<Vehicle>);
    void print_vehicle_detail(int);
};