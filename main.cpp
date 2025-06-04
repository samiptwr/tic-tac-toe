#include<iostream>
using namespace std;

//global variables
string board[3][3] = {
        {"1","2","3"},
        {"4","5","6"},
        {"7","8","9"}
};
string user;
int x, o;
string num;
string turn, turnAsk;
bool run = true;
int emptySpacesCount = 9;

void createBoard();
void win(string turn);

int main(){
    cout<<"         Welcome to our Local Tic Tac Toe"<<endl;
    cout<<"Press 'p' to play. Please choose in small letters!!"<<endl;
    cout<<endl;
    cout<<"If you like to Resign the Game Just Press 'r' Whilst your Turn. Also in small letters!!"<<endl;
    cin>>user;

    if(user == "p"){
        cout<<"Choose 'X' or 'O'. Please choose in capital letters!!"<<endl;
        cin>>turnAsk;

        if(turnAsk == "X" || turnAsk == "O"){
            turn = turnAsk;
        } else {
            cout<<"Invalid Input!!"<<endl;
        }

        createBoard();
        while(run){
            cout<<"Turn: "<<turn<<endl;
            cin>>num;
            if(num == "0" || num == "1" || num == "2" || num == "3" || num == "4" || num == "5" || num == "6"|| num == "7" || num == "8"|| num == "9"){
                for(int i = 0; i <= 2; i++){
                    for(int j = 0; j <= 2; j++){
                        if(board[i][j] == num){
                            board[i][j] = turn;
                            emptySpacesCount -= 1;
                            if(emptySpacesCount == 0){
                                run = false;
                                cout<<"     DRAW!!"<<endl;
                            }
                            win(turn);
                            if(turn == "X"){
                                turn = "O";
                            } else if(turn == "O"){
                                turn = "X";
                            }
                            createBoard();
                        }
                    }
                }
            } else if (num == "r"){
                run = false;
                if(turn == "O"){
                    cout<<"     'X' WON!!!"<<endl;
                    cout<<"   By Resignation"<<endl;
                } else if (turn == "X"){
                    cout<<"     'O' WON!!!"<<endl;
                    cout<<"   By Resignation"<<endl;
                }
            } else {
                cout<<"Invalid Input!!"<<endl;
            }
            
        }
    } else {
        cout<<"Invalid Input!!"<<endl;
    }    
    
    return 0;
}


void createBoard(){
    cout<<"  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  "<<endl;
    cout<<"-----------------"<<endl;
    cout<<"  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  "<<endl;
    cout<<"-----------------"<<endl;
    cout<<"  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  "<<endl;
}

void win(string turn){
    if(board[0][0] == board[1][0] && board[1][0] == board[2][0]){
        run = false;
        cout<<"     '"<<turn<<"' Won!!";
    } else if (board[0][1] == board[1][1] && board[1][1] == board[2][1]){
        run = false;
        cout<<"     '"<<turn<<"' WON!!";
    } else if (board[0][2] == board[1][2] && board[1][2] == board[2][2]){
        run = false;
        cout<<"     '"<<turn<<"' WON!!";
    } else if (board[0][0] == board[0][1] && board[0][1] == board[0][2]){
        run = false;
        cout<<"     '"<<turn<<"' WON!!";
    } else if (board[1][0] == board[1][1] && board[1][1] == board[1][2]){
        run = false;
        cout<<"     '"<<turn<<"' WON!!"<<endl;
    } else if (board[2][0] == board[2][1] && board[2][1] == board[2][2]){
        run = false;
        cout<<"     '"<<turn<<"' WON!!"<<endl;
    } else if (board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        run = false;
        cout<<"     '"<<turn<<"' WON!!";
    } else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        run = false;
        cout<<"     '"<<turn<<"' WON!!";
    } else {
        run = true;
    }
}

//from Samip Tiwari
