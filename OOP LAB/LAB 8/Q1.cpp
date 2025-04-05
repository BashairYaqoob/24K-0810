#include <iostream>
#include <cmath>
using namespace std;

class Complex{
    private:
    int real;
    int imag;
    public:
    Complex(int r, int i): real(r), imag(i){}
    friend float magnitude(Complex c);
    Complex operator + (const Complex& obj)const{
        return Complex (real+obj.real , imag+obj.imag);
    }
    Complex operator - (const Complex& obj)const{
        return Complex(real-obj.real, imag-obj.imag);
    }
    Complex operator * (const Complex &obj)const{
        return Complex(real*obj.real-imag*obj.imag, real*obj.imag+imag*obj.real);
    }
    Complex operator / (const Complex& obj)const{
        double d=pow(obj.real,2)+pow(obj.imag,2);
        if(d == 0){
            cout << "Error.. Can't divide by zero" << endl;
            return Complex(0,0);
        }
        else{
            return Complex((real*obj.real+imag*obj.imag)/d,(imag*obj.real-real*obj.imag)/d);
        }
    }
    friend ostream& operator<<(ostream& os, const Complex& c);
};

float magnitude(Complex c){
    float m = pow(((c.real*c.real)+(c.imag*c.imag)), 0.5);
    return m;
}

ostream& operator<<(ostream& os, const Complex& c){
    os << c.real;
    if (c.imag >= 0)
        os << " + " << c.imag << "i";
    else
        os << " - " << -c.imag << "i";
    return os;
}

int main(){
    Complex c1(1,5);
    Complex c2(2,3);

    cout<<"--Performing Arithmatic functions--"<<endl;
    cout << "Addition: " << c1 + c2 << endl;
    cout << "Subtraction: " << c1 - c2 << endl;
    cout << "Multiplication: " << c1 * c2 << endl;
    cout << "Division: " << c1 / c2 << endl;
    cout << "Magnitude of c1: " << magnitude(c1) << endl;

    return 0;
}
