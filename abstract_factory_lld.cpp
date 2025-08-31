#include <bits/stdc++.h>
using namespace std;

class Button {
public:
    virtual void print() = 0;
};

class CheckBox {
public:
    virtual void print() = 0;
};

class WindowsButton : public Button {
public:
    void print() {
        cout<<"Hi i m windows button\n";
    }
};

class WindowsCheckBox : public CheckBox {
public:
    void print() {
        cout<<"Hi i m windows checkbox\n";
    }
};

class MacButton : public Button {
public:
    void print() {
        cout<<"Hi i m mac button\n";
    }
};

class MacCheckBox : public CheckBox {
public:
    void print() {
        cout<<"Hi i m mac checkbox\n";
    }
};

class UI {
public:
    Button* button;
    CheckBox* checkbox;
};


class UIFactory {
public:
    UI* resultUI;
    virtual UI* renderUI() = 0;
};

class WindowsUI : public UIFactory {
public:
    UI* renderUI() {
        resultUI = new UI();
        resultUI->button = new WindowsButton();
        resultUI->checkbox = new WindowsCheckBox();
        return resultUI;
    }
};

class MacUI : public UIFactory {
public:
    UI* renderUI() {
        resultUI = new UI();
        resultUI->button = new MacButton();
        resultUI->checkbox = new MacCheckBox();
        return resultUI;
    }
};


int main() 
{
    UIFactory* uifact = new MacUI();
    UI* ui = uifact->renderUI();
    ui->button->print();
    ui->checkbox->print();
    return 0;
}