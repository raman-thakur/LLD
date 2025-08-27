#include <bits/stdc++.h>
using namespace std;

class BasePizza {
public:
    virtual double getCost() = 0;
};

class Margerita : public BasePizza {
public:
    double cost;
    Margerita(double val) {
        cost = val;
    };
    double getCost()
    {
        return cost;
    };
};

class VegDelight : public BasePizza {
public:
    double cost;
    VegDelight(double val) {
        cost = val;
    };
    double getCost()
    {
        return cost;
    };
};


class PizzaDecorator : public BasePizza {
 
};

class AddCheese : public PizzaDecorator {
public:
    BasePizza* basePizza;
    AddCheese(BasePizza* base) {
        basePizza = base;
    }
    double getCost() {
        return basePizza->getCost() + 30;
    }
};

class AddMasroom : public PizzaDecorator {
public:
    BasePizza* basePizza;
    AddMasroom(BasePizza* base) {
        basePizza = base;
    }
    double getCost() {
        return basePizza->getCost() + 50.80;
    }
};



int main()
{
    BasePizza* pizza = new AddMasroom(new AddCheese(new Margerita(130.0)));
    cout<<pizza->getCost();
    return 0;
}