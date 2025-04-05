#include <iostream>
using namespace std;

class InventoryManager;

class Car{
    private:
    string model;
    double price;
    public:
    Car(string m, double p): model(m), price(p){}
    friend class InventoryManager;
    friend Car comparePrice(const Car& c1, const Car& c2);
};

Car comparePrice(const Car& c1, const Car& c2){
    if(c1.price < c2.price){
        cout <<c1.model<<" is cheaper." << endl;
    } else if(c1.price > c2.price){
        cout << c2.model <<" is cheaper." << endl;
    } else {
        cout << "Both cars have the same price." << endl;
    }
}

class InventoryManager{
    public:
    void update(Car& c, double newprice){
        c.price=newprice;
    }
    void display(Car& c){
        cout<<"Car model: "<<c.model<<"\nCar Price: Rs"<<c.price<<endl;
    }
};

int main(){
    Car c1("Kaala DAALA", 3000);
    Car c2("Toyota Carolla", 5000);

    InventoryManager i;
    
    cout << "--Car details: --" << endl;
    i.display(c1);
    i.display(c2);

    i.update(c1, 3500);
    
    cout << "\nUpdated car details: " << endl;
    i.display(c1);

    cout<<"Comparing both cars:"<<endl;
    comparePrice(c1, c2);

    return 0;
}
