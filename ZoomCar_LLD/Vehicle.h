#pragma once

enum Status {
    unreserved,
    reserved,
};

enum Type{
    bike,
    car,
};

class Vehicle{
public:
    int id;
    int number;
    Status status;
    Type type;
    int hourlycost;
    double kmdriven;

    //getter and setters
    void setStatus(Status);
};