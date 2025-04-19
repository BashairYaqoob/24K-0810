#include <iostream>
using namespace std;

class Patient{
    protected:
    string name;
    string id;
    public:
    Patient(string n, string ID) : name(n), id(ID){}
    virtual void displayTreatment() =0;
    virtual void calculateCost() =0;
};

class Inpatient:public Patient{
    public:
    Inpatient(string n, string ID): Patient(n, ID){}
    void calculateCost(){
        cout<<"Calculating cost for inpatient!\n";
    }
    void displayTreatment(){
        cout<<"InPatient name: "<<name<<" ID: "<<id<<" is underging treatment\n";
    }
};

class Outpatient:public Patient{
    public:
    Outpatient(string n, string ID): Patient(n, ID){}
    void calculateCost(){
        cout<<"Calculating cost for outpatient!\n";
    }
    void displayTreatment(){
        cout<<"OutPatient name: "<<name<<" ID: "<<id<<" is underging treatment\n";
    }
};

int main(){
    Inpatient p1("Mehak", "500ct");
    Outpatient p2("Saad", "804I");
    p1.calculateCost();
    p1.displayTreatment();
    p2.calculateCost();
    p2.displayTreatment();
    return 0;
}
