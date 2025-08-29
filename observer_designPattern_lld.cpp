#include <bits/stdc++.h>
using namespace std;

class Observer {
public:
    virtual void update(string) = 0;
};

class Observable {
public:
    virtual void add(Observer*) = 0;
    virtual void notify() = 0;
    virtual void setData(int) = 0;
};





class IphoneObservable : public Observable {
public: 
    vector<Observer*> observers;
    int stockCount = 0;
    string message = "iphone is in stock now";
    void add(Observer* obj)
    {
        observers.push_back(obj);
    }

    void notify()
    {
        for(Observer* obj:observers)
        {
            obj->update(message);
        }
    }

    void setData(int count)
    {
        if(stockCount == 0)
        {
            stockCount = count;
            notify();
        }
        else{
            stockCount = count;
        }
    }
};



class MobileObserver : public Observer {
public:
    string mobileNo;
    void update(string msg)
    {
        cout<<mobileNo<<"->"<<msg<<"\n";
    }
    MobileObserver(string mNumber)
    {
        mobileNo = mNumber;
    }
};








int main()
{
    MobileObserver* mobs = new MobileObserver("3498563286");
    IphoneObservable* iphoneobs = new IphoneObservable();
    iphoneobs->add(mobs);
    iphoneobs->setData(2);
    iphoneobs->setData(0);
    iphoneobs->setData(2);
    return 0;
}