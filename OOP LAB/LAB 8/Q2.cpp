#include <iostream>
#include <cmath>
using namespace std;

class Manager;

class Account{
    private:
    int accountnum;
    double balance;
    public:
    Account(int a, double b): accountnum(a), balance(b){}
    friend class Manager;
    friend void transferFunds(Account& a, Account& b,double amount);
};

void transferFunds(Account& a, Account& b,double amount){
    if(amount>0 && amount<=a.balance){
        a.balance-=amount;
        b.balance+=amount;
        cout<<"Transfer successful!"<<endl;
    }
    else{
        cout << "Invalid transfer amount or insufficient funds!" << endl;
    }
}

class Manager{
    public:
    void withdraw(Account& a, double amount){
        if(amount>0 && amount<=a.balance){
            a.balance-=amount;
            cout << "Withdrawal successful. New balance: Rs" << a.balance << endl;
        }
        else{
            cout<<"Insufficient balance.\n";
        }
    }
    void deposit(Account& a, double amount){
        if(amount < 0){
            cout << "Invalid deposit amount!" << endl;
            return;
        }else{
            a.balance += amount;
            cout << "Deposit successful. New balance: Rs" << a.balance << endl;
        }
    }
    void displayDetails(Account& a){
        cout<<"Account number: "<<a.accountnum<<endl;
        cout<<"Balance: Rs "<<a.balance<<endl;
    }
};

int main(){
    Account a1(101, 4500.0);
    Account a2(104, 3600.0);

    Manager m;

    m.displayDetails(a1);
    m.deposit(a1, 500.00);

    m.displayDetails(a2);
    m.withdraw(a2, 200.00);

    transferFunds(a1,a2, 1000);

    m.displayDetails(a1);
    m.displayDetails(a2);

    return 0;
}
