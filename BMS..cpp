#include<iostream>
#include<iomanip>
#include<fstream>
#include<cctype>

using namespace std;

class Bank_Account{
    int account_number;
    char name[50];
    char type;
    int Money_Deposit;

    public:
        void report() const;
        int retacno() const{
            return account_number;
        }
        void create_account();
        void Display_Account();
};
void Bank_Account::report() const{
    cout << account_number << setw(10) <<" "<<name<<setw(10)<<type<<setw(6)<<Money_Deposit<<endl;
}

void write_account(); // function to write record inn binary file
void display_details(int); // function to display account details given by user
void delete_account(int);   //  function to delete record of the  file


void display_all();     // function to display all account details
void Bank_Account::create_account()

{
    system("cls");
    cout <<"\t Enter the account number";
    cin >> account_number;
    cout <<  "\t Enter the name  of the account holder:";
    cin.ignore();
    cin.getline(name,50);
    cout<<"\t Enter the type of  the  account(C/S):";
    cin >> type;
    type = toupper(type);
    cout <<"\t Enter the  initial amount(>=500 for Saving and >=1000 for current):";
    cin >> Money_Deposit;
    cout <<"\t Account Created.....";
    cout << endl;
}
void Bank_Account::Display_Account()
{
    cout <<"\t Bank acoount Number:" << account_number << endl;
    cout<<"\t Account Holder name:" << name <<  endl;
    cout <<"\t Type of Account:" <<type<<endl;
    cout <<"\t Balanve Amount :" << Money_Deposit << endl;
}


int main()
{
    char ch;
    int num;

    do{
    cout <<"\t\t ------------------------------------"<< endl;
    cout <<"\t\t |Welcome to Bank Management System |" << endl;
    cout << "\t\t------------------------------------" << endl;

    cout << endl;
    cout<<"\t---Main Menu ---" << endl;
    cout <<"\t 1. Create Account"<<endl;  //created
    cout <<"\t 2. Deposite Money" << endl;
    cout <<"\t 3. Withdraw Money" << endl;
    cout <<"\t 4. Balance Enquiry" << endl; //created
    cout <<"\t 5. All Account Holder List" << endl; //created
    cout <<"\t 6. Close an account" << endl;    //created
    cout <<"\t 7. Modify an account" << endl;
    cout <<"\t 8. Exit" << endl;    //created
    cout << endl;

    cout <<"\t Enter your choice(1-8):";
    cin >> ch;

    switch (ch) {
        case '1':
            write_account();
            break;
        case '2':
            system("cls");
            cout <<"\t Enter the account number:";
            cin >> num;
                //deposite function
            break; 

        case '3':
            system("cls");
            cout <<"\t Enter the account number:";
            cin >> num;
                //withdraw function
            break;    

        case '4':
            system("cls");
            cout <<"\t Enter the account number:";
            cin >> num;
            display_details(num);    //balance enquiry function
            break;    

        case '5':
            // display_all();   // display all function
            break;    

        case '6':
            system("cls");
            cout <<"\t Enter the  account number:";
            cin >> num;
            delete_account(num);    //close account function
                break;

        case '7':
            cout <<"\t Enter the account Number:";
            cin >> num;
                //modify account funcction
            break;

        case '8':
            cout <<"\t thank for using the Bank Management system " << endl;
            break;
    } 
    cin.ignore();
    cin.get();

 } while(ch != '8');
    return 0;
    Bank_Account B;
    B.create_account();
    cout << endl;
    B.Display_Account();
    return 0;
}


void write_account() //function to write record in binary file
{
    Bank_Account ac;
    ofstream outFile;
    outFile.open("account.dat",ios::binary|ios::app);
    ac.create_account();
    outFile.write(reinterpret_cast<char *>(&ac), sizeof(Bank_Account));
    outFile.close();
}

void delete_account(int n)
{
    Bank_Account ac;
    ifstream inFile;    //input file stream
    ofstream outFile;   //output file stream
    inFile.open("accoun.dat",ios::binary);
    if(!inFile)
    {
        cout <<"File could not  be open || Press any key...";
        return;
    }
    outFile.open("temp.dat",ios::binary);
    inFile.seekg(0,ios::beg);

    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account))){
        if(ac.retacno()!=n){
            outFile.write(reinterpret_cast<char *> (&ac),sizeof(Bank_Account));
        }
    }

    inFile.close();
    outFile.close();
    remove("Bank_Account.dat");
    cout << "\t Record Deleted..." << endl;

}

void display_details(int n)
{
    Bank_Account ac;
    bool flag = false;
    ifstream inFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile)
    {
        cout << "File could not be open || Press any key ....";
        return;
    }
    cout << "\t Bank Account Details" << endl;
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account))){
        if(ac.retacno() == n)
        {
            ac.Display_Account();
            flag = true;
        }
    }
    inFile.close();
    if(flag == false){
        cout <<"\t Account number does not exit" << endl;
    }
}

void  display_all()    //function to display all account details
{
    system("cls");
    Bank_Account ac;
    ifstream inFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile)
    {
        cout << "File could not be open || Press any key...";
        return;
    }
    cout <<"\t Bank account Holder List" << endl;
    cout <<"================================================"<< endl;
    cout <<"A/c nom.               NAME                TYPE                       BALANCE" << endl;
    cout <<"================================================"<< endl;
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account)))
    {
        ac.report();
    }
    inFile.close();

} 