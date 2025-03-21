//overriding -> should have inheritance
//runtime polymorphism
//late binding
#include "iostream"
using namespace std;

class Base{
    public:
    virtual void display(){
        cout << "Hello from Base class"<< endl;
    }
};

class Derived : public Base{
    public:
    void display(){
        cout << "Hello from Derived class"<<endl;
    }
};

int main() {
    Base *ptr, b1;
    //ptr->display();//gives no result as it is trying to find overridden in derived
    Derived d1;
    ptr = &d1;
    ptr->display(); // Calls Base::display() override nahi hwa.  islye base k sath virtual likho
    //virtual likhne k bad Calls Derived::display()
    //ptr=&b1;
    //ptr->display();
    
    return 0;
}
