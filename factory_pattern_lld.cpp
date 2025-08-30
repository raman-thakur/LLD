#include <bits/stdc++.h>
using namespace std;
class Notify {
public:
    virtual void notify() = 0;
};

class EmailNotify : public Notify {
public:
    void notify(){
        cout<<"notified on email\n";
    }
};

class WatsAppNotify : public Notify {
public:
    void notify(){
        cout<<"notified on watsapp\n";
    }
};

class SMSNotify : public Notify {
public:
    void notify(){
        cout<<"notified on sms\n";
    }
};

class SlakNotify : public Notify {
public:
    void notify(){
        cout<<"notified on slack\n";
    }
};

class NotificationFactory{
public:
     Notify* notifyObj;
     Notify* createNotification(string type) {
        if(type == "email")
            notifyObj = new EmailNotify();
        else if(type == "watsapp")
            notifyObj = new WatsAppNotify();
        else if(type == "sms")
            notifyObj = new SMSNotify();
        else if(type == "slak")
            notifyObj = new SlakNotify();

        return notifyObj;
    }
    
};




int main()
{
    NotificationFactory* notfact = new NotificationFactory();
    notfact->createNotification("watsapp")->notify();
    return 0;
}