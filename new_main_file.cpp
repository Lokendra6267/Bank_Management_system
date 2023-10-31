#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
class Bank{
    char name[100],add[100],y;
    int balance;
    public:
        void open_account();
        void diposite_money();
        void withdraw_money();
        void display_account();
        

}; 

void Bank :: open_account()
{
    cout << "Enter your full name :: ";
    cin.ignore();
    cin.getline(name,100);
    cout << "Enter your address :: ";
    cin.ignore();
    cin.getline(add,100);
    cout << "What types of account you wanr to open saving(s) or current(c) :: ";
    cin >> y;
    cout << "Enter amount for diposite ::";
    cin >> balance;
    cout << "Your account is created \n";
}
void  Bank :: diposite_money()
{
    int a;
    cout << "Enter how much you deposite money :: ";
    cin >> a;

    balance += a;
    cout << "Total amount you deposite :: \t" << balance;
}
void Bank :: display_account()
{
    cout << "Your full name :: \t" << name << endl;
    cout << "Your address :: \t" << add << endl;
    cout << "Type of account that you open ::\t" << y << endl;
    cout << "Amount you deposite :: \t" <<balance << endl;
}
void Bank :: withdraw_money()
{
    float amount;
    cout << "Withdraw :: ";
    cout << "Enter amount to withdraw :: ";
    cin >> amount;
    balance -= amount;
    cout << "Now Total balance is ::\t " << balance;
}


int main()
{
    int ch,x;
    Bank obj;
    do
    {

    cout << " ********************Welcome to Our bank***********************************\n";    
    cout << "1) Open account  \n";
    cout << "2) deposite money  \n";
    cout << "3) withdraw  money  \n";
    cout << "4) Display account  \n";
    cout << "5) Exit   \n";
    cout << " ********************Select the option from above*************************** \n";
    cin >> ch;

    switch(ch)
    {
        case 1: 
            cout << "1) open account \n";
            obj.open_account();
            break;
        case 2:
            cout << "2) Deposite money \n";
            obj.diposite_money();
            break;
        case 3:
            cout << "3) withdraw money \n";
            obj.withdraw_money();    
            break;
        case 4:
            cout << "4) Display account \n";
            obj.display_account();
            break;        
        case 5:
            if(ch == 5)
                exit(1);

        default:
            cout << "This is exist Try again \n";            

    }
    cout << "\n Do you want to select next options then press :: y or Y \n";
    cout << "If you want to exit then press  :: n or N \n";

    x = getch();
    if(x == 'n' || x == 'N')
    {
        cout << "Thank For existing 👍";
        exit(0);
    }    

    }
    while(x == 'y' || x == 'Y');
    getch();
    return 0;
}