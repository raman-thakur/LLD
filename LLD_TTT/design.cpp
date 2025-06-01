#include<bits/stdc++.h>
using namespace std;
enum PiceTpe{
    x,
    o,
    e,
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

class PiceE:public PlayingPice
{
public:
    PiceE():PlayingPice(e)
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

class Board
{
public:
    int size;
    vector<vector<PlayingPice*>> board;
    Board(int n)
    {
        size=n;
        board.resize(n,vector<PlayingPice*>(n,NULL));
    }
};

class Game
{
public:
    deque<Player*> players;
    Board *board;
    bool is_winner;
    Game()
    {
        board=new Board(3);
        is_winner=false;
        players.push_back(new Player(1,"raman",new PiceX()));
        players.push_back(new Player(2,"suman",new PiceO()));
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                board->board[i][j]=new PiceE();
            }
        }
    }
    bool check_winner()
    {
        for(int i=0;i<3;i++)
        {
            PiceTpe t=board->board[i][0]->pice_type;
            for(int j=0;j>3;j++)
            {
                if(board->board[i][j]->pice_type!=t || board->board[i][j]->pice_type==2)
                break;
                if(j==3)
                return true;
            }
        }
        for(int i=0;i<3;i++)
        {
            PiceTpe t=board->board[0][i]->pice_type;
            for(int j=0;j>3;j++)
            {
                if(board->board[j][i]->pice_type!=t || board->board[j][i]->pice_type==2)
                break;
                if(j==3)
                return true;
            }
        }
        PiceTpe t=board->board[0][0]->pice_type;
        int i=0,j=0;
        while(i<3 && j<3)
        {
            if(board->board[j][i]->pice_type!=t || board->board[j][i]->pice_type==2)
                break;
            
            i++;j++;
            if(j==3)
            return true;
        }

        t=board->board[2][2]->pice_type;
        i=2;j-2;
        while(i>=0 && j>=0)
        {
            if(board->board[j][i]->pice_type!=t || board->board[j][i]->pice_type==2)
                break;
            
            i--;j--;
            if(j==-1)
            return true;
        }
        return false;
    }

    vector<pair<int,int>> get_all_free_spots()
    {
        vector<pair<int,int>> vp;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board->board[j][i]->pice_type==2)
                {
                    vp.push_back({i,j});
                }
            }
        }
        return vp;
    }

    void print_all_free_spots(vector<pair<int,int>> &arr)
    {
        cout<<"bellow are the free spots option, choose any option\n";
        for(int i=0;i<arr.size();i++)
        {
            cout<<i<<"->"<<arr[i].first<<","<<arr[i].second<<"\n";
        }
        return;
    }

    void start_game()
    {
        while(is_winner==false)
        {
            vector<pair<int,int>> free_spots=get_all_free_spots();
            print_all_free_spots(free_spots);
            int choosen;
            cin>>choosen;
            Player *turn_player=players.front();
            players.pop_front();
            board->board[free_spots[choosen].first][free_spots[choosen].second]=turn_player->choosen_pice;
            is_winner=check_winner();
            if(is_winner==true)
            {
                cout<<"winner is "<<turn_player->player_name;
                return;
            }
            players.push_back(turn_player); 
        }
    }

};



int main()
{
    Game *game=new Game();
    game->start_game();
    return 0;
}
