#include<iostream>

using namespace std;


void Board(char board[3][3])
{
    for(int i=0;i<3;i++)
    {
        cout<<"|";
        for(int j=0;j<3;j++)
        {
            cout<<board[i][j]<<"|";
        }
        cout<<"\n-------------\n";
        
    }
    
}


bool checkingWin(char board[3][3],char player)
{
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player)
                    return true;
        if(board[0][i]==player && board[1][i] ==player && board[2][i]==player)
            return  true;

    }

    if(board[0][0]==player && board[1][1]==player && board[2][2]==player)
        return true;
    if(board[0][2]==player && board[1][1]==player && board[2][0]==player)
        return true;
    return false;
}


int main()
{
    char board[3][3]=
    {  
        {' ', ' ', ' ' },
        {' ', ' ', ' ' },
        {' ', ' ', ' ' }

    };

    char player ='X';
    int row,col,turn;

    cout<<"\nLet s play"<<endl;

    for(turn =0;turn<9;turn++)
        {
            Board(board);

            while(true)
            {
                cout<<endl;
                cout<<"Player , choose \n(Note choose a row and a col)";
                cin>>row>>col;

                if(board[row][col]!=' ' || row<0 || row>2 || col<0 || col>2)
                    cout<<"Invalid move, try again";
                else
                    break;
            }

            board[row][col]=player;

            if(checkingWin(board,player))
            {
                Board(board);

                cout<<"Player "<< player <<" wins\n";

                break;
            }

            player= (player=='X')?'O' : 'X';

            Board(board);

            if (turn == 9 && !checkingWin(board, 'X') && !checkingWin(board, 'O')) { 
                     cout << "It's a draw!\n"; 

        }
        }

        return 0;

}