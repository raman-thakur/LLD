#include <bits/stdc++.h>
using namespace std;

#include "transport_vehicle.h"
#include "sport_vehicle.h"
#include "offroad_vehicle.h"
#include "vehicle.h"
#include "normal_drive.h"
#include "power_drive.h"

int main()
{
    cout<<"hello world3rqqf!";
    Normal_Drive temp;
    temp.drive_method();
    Vehicle *car= new Transport_Vehicle(new Normal_Drive());
    Vehicle *thar =  new Offroad_Vehicle(new Power_Drive());
    car->drive();
    thar->drive();
    return 0;
} 