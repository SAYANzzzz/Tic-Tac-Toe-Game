#include <cstdlib>
#include <iostream>
using namespace std;


void Board(char Places[]);
void PlayerMove(char Player,char Places[]);
bool checkWinner(char x,char Places[]);
void ComputerMove(char Computer,char Places[]);
bool checkTie(char Places[]);

int main(){
    char Places[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char Place1[9] = {'1','2','3','4','5','6','7','8','9'};
    cout << "This is each spot number :D \n";
    Board(Place1);
    bool playing = true;
    char Player;
    char Computer;
    do{
        cout << "Choose a char 'X' or 'O' to play with !\n";
        cin >> Player;
    }while(Player != 'X' && Player != 'O');
    if(Player == 'X')
        Computer = 'O';
    else
        Computer = 'X';
    while(playing){
        cout << "You to Move !!! \n";
        PlayerMove(Player,Places);
        Board(Places);
        cout << '\n';
        if(checkWinner(Player,Places)){
            cout << "You WON  !!";
            playing = false;
            break;
        }
        if(checkTie(Places)){
            cout << "IT'S A TIE !!";
            playing = false;
            break;
        }
        cout << "Computer to Move !!! \n";
        ComputerMove(Computer,Places);
        Board(Places);
        if(checkWinner(Computer,Places)){
            cout << "You LOST  :(";
            playing = false;
            break;
        }
        if(checkTie(Places)){
            cout << "IT'S A TIE !!";
            playing = false;
            break;
        }

    }
    return 0;

}

void Board(char Places[]){
    cout << " " << Places[0] << "  | " << Places[1] << " | " << Places[2] << endl;
    cout << " ---|---|---" << endl;
    cout << " " << Places[3] << "  | " << Places[4] << " | " << Places[5] << endl;
    cout << " ---|---|---" << endl;
    cout << " " << Places[6] << "  | " << Places[7] << " | " << Places[8] << endl;
}
void PlayerMove(char Player,char Places[]){
    int x;
    do{
        cout << "Choose a number between 1 and 9 \n";
        cin >> x;
    }while(x < 1 || x > 9);
    if(Places[x-1] ==' ')
        Places[x-1] = Player;
    else{
        do{
        cout << "Spot occupied ! Choose a number between 1 and 9 \n";
        cin >> x;
        }while(x < 1 || x > 9 || Places[x-1] !=' ');
        Places[x-1] = Player;
    }


}
bool checkWinner(char x,char Places[]){
    if(x == Places[0] && x == Places[1] && x == Places[2])
        return true;
    else if(x == Places[3] && x == Places[4] && x == Places[5])
        return true;
    else if(x == Places[6] && x == Places[7] && x == Places[8])
        return true;
    else if(x == Places[0] && x == Places[3] && x == Places[6])
        return true;
    else if(x == Places[1] && x == Places[4] && x == Places[7])
        return true;
    else if(x == Places[2] && x == Places[5] && x == Places[8])
        return true;
    else if(x == Places[0] && x == Places[4] && x == Places[8])
        return true;
    else if(x == Places[2] && x == Places[4] && x == Places[6])
        return true;
    else
        return false;
}
void ComputerMove(char Computer,char Places[]){
    int random;
    do{
        random = rand() % 9;
    }while(Places[random] !=' ');
    Places[random] = Computer;
}
bool checkTie(char Places[]){
    for(int i = 0 ; i < 9 ; i ++){
        if(Places[i] == ' ')
            return false;
    }
    return true;
}
