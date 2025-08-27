#include <bits/stdtr1c++.h>
#include <VehicleInventryManager.h>
using namespace std;

int main()
{
    vector<Vehicle> vv;
    Bike bike=Bike();
    Car car=Car();
    vv.push_back(car);
    vv.push_back(bike);
    VehicleInventryManager *vim=new VehicleInventryManager(vv);
    vim->print_vehicle_detail(0); vim->print_vehicle_detail(1);
    return 0;
}
