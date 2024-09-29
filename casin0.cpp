#include<iostream>
#include <stdlib.h> 
#define ll long long

using namespace std;

ll amount_money;

int randnumb()
{
    return rand()%10 +1;
}


int main()
{
    cout<<"\n Enter amount of money to play the game : ";
    cin>>amount_money;


    while(true)
    {
        ll betting_amount;
        if(amount_money == 0)
        {
            cout<<"You lost your money, your balance is 0.!!!!!RECHARGE";
            cout<<endl<<endl;
            
            return 0;
        }

        cout<<"enter bitting amount"<<endl;
        cin>>betting_amount;
        if(betting_amount>amount_money)
        {
            cout<<"you don t have enough money"<<endl;
            continue;
        }

        cout<<"guess one number between 1-10 :- ";
        int n;
        cin>>n;
        if(n>10 || n<=0){
            cout<<"wrong number"<<endl;
            continue;
        } else{
            int r=randnumb();
            if(r==n)
            {
                amount_money+=(betting_amount*100);
                cout<<"You won. \n your ballance is "<<amount_money<<endl;
                
            }else{
                amount_money-=betting_amount;
                cout<<"You lost haha, try again. \n your ballance is "<<amount_money<<endl;
            }

        }

    }
}
