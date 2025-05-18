#pragma once
class Drive_Strategy
{
public:
    virtual void drive_method() = 0; // Pure virtual function
    virtual ~Drive_Strategy() {}     // Virtual destructor (important for polymorphism)
};
