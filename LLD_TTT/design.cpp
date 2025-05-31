#include<bits/stdc++.h>
using namespace std;
enum PiceTpe{
    x,
    o,
};


class PlayingPice
{
public:
    PiceTpe pice_type;
    PlayingPice(PiceTpe t)
    {
        pice_type=t;
    }
};


class PiceX:public PlayingPice
{
public:
    PiceX():PlayingPice(x)
    {

    }
};

class PiceO:public PlayingPice
{
public:
    PiceO():PlayingPice(o)
    {

    }

};


class Player
{
public:
    int id;
    string player_name;
    PlayingPice *choosen_pice;
    Player(int x,string name,PlayingPice *p)
    {
        id=x;
        player_name=name;
        choosen_pice=p;
    }

};



int main()
{
    Player *a=new Player(0,"raman",new PiceX());
    Player *b=new Player(1,"raman",new PiceO());

    cout<<a->choosen_pice->pice_type<<" "<<b->choosen_pice->pice_type;
    return 0;
}
