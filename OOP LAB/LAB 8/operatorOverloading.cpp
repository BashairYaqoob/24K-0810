#include "iostream"
using namespace std;

class Rupee{
    private:
    int data;
    public:
    Rupee(int d=0): data(d){}
    Rupee operator-(){
        return Rupee(-data);
    }
    Rupee operator+(const Rupee& r){
        return Rupee(data + r.data);
    }

    Rupee& operator-=(const Rupee& r){
        data -= r.data;
        return *this;
    }
    Rupee& operator+=(const Rupee& r){
        data += r.data;
        return *this;
    }
    friend ostream& operator<<(ostream& os, const Rupee& r){ //to access data that is private
        os<< r.data << endl;
        return os;
    }
};

int main(){
    Rupee w1, w2, w3;
    w1 = 50;
    w2 = 100;
    w3 = w1 + w2;
    cout<<w3<<endl;
    Rupee wholesale(100), retail, addedprice(50), discount(20);
    retail = wholesale;
    cout<<"Wholesale:"<<wholesale<<endl;
    retail=wholesale+addedprice;
    cout<<"Added price:"<<retail<<endl;
    retail-=discount;
    cout<<"Discounted price:"<<retail<<endl;
    retail= wholesale+10;
    cout<<"New retail:"<<retail<<endl;
    retail = -retail;
    cout<<"Negative retail:"<<retail<<endl;
    return 0;
}
