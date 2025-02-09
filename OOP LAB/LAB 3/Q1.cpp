//Wallet class


#include <iostream>
#include <string>
using namespace std;

class Wallet{
    private:
    string ownerName;
    double totalBalance;
    string transactionHistory;
    public:
    void setvalues(string ON, double TB,string TH){
        ownerName=ON;
        totalBalance=TB;
        transactionHistory=TH;
    }
    void addmoney(double amount){
        totalBalance+=amount;
        transactionHistory+="Added: $"+to_string(amount)+"\n";
    }
    void spendMoney(double amount){
        if(amount>0 && amount<=totalBalance){
            totalBalance-=amount;
            transactionHistory+="Spent: $"+to_string(amount)+"\n";
        }
        else{
            cout<<"\nInsufficient Funds!";
        }
    }
    void displayHistory(){
        cout<<"Transacton History for "<<ownerName<<":"<<endl;
        cout<<transactionHistory;
        cout<<"\nCurrent balance: $"<<getBalance();
    }
    double getBalance(){
        return totalBalance;
    }
};

int main(){
    Wallet w;
    w.setvalues("Saad", 10040.5, "");
    w.addmoney(500);
    w.spendMoney(3000);
    w.displayHistory();
    return 0;
}
