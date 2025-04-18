#include <iostream>
using namespace std;

class MenuItem{
    protected:
    string dishName;
    double price;
    public:
    MenuItem(string n, double p) : dishName(n), price(p) {}
    virtual void showDetails() =0;
    virtual void prepare() =0;
};

class Appertizer: public MenuItem{
    public:
    Appertizer(string n, double p): MenuItem(n, p){}
    void showDetails(){
        cout<<"Appetizer name:"<<dishName<<"\nPrice: Rs "<<price<<endl;
    }
    void prepare() {
        cout<<"Appetizer "<<dishName<<" ban raha hai.."<<endl;
    }
};

class MainCourse: public MenuItem{
    public:
    MainCourse(string n, double p): MenuItem(n, p){}
    void showDetails(){
        cout<<"MainCourse name:"<<dishName<<"\nPrice: Rs "<<price<<endl;
    }
    void prepare() {
        cout<<"MainCourse "<<dishName<<" ban raha hai.."<<endl;
    }
};

int main(){
    Appertizer a("Garlic bread", 250);
    Appertizer a2("Chicken Wings", 450);
    MainCourse m("Fajita Pizza", 1400);
    a.prepare(); a2.prepare(); m.prepare();
    a.showDetails(); a2.showDetails(); m.showDetails();
    return 0;
}
