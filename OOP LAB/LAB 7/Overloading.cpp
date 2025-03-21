#include "iostream"
using namespace std;

class Base{
    public:
    void display(int x){
        cout << "Base class display: int x:"<< x << endl;
    }
    void display(double x){
        cout << "Base class display: double x:"<< x << endl;
    }
};

class Derived : public Base{
    public:
    using Base::display; //unhide their existence
    void display(const char* c){ //equivalent to string
        cout << "Derived class display: string c:"<< c << endl;
    }
};

int main() {
    Base b1;
    Derived d1;
    b1.display(5);
    b1.display(5.5);
    d1.display("Hello World");
    //d1.display(5);  ERROR overloaded display function in base without using wali line
    d1.display(8); //1
    d1.Base::display(11.5); //2
    return 0;
}
