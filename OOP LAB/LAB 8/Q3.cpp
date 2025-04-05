#include <iostream>
using namespace std;

class Vector2D{
    private:
    double x, y;
    public:
    Vector2D(double x, double y): x(x), y(y){}
    Vector2D operator + (const Vector2D& obj) const{
        return Vector2D(x + obj.x, y + obj.y);
    }

    Vector2D operator - (const Vector2D& obj) const{
        return Vector2D(x - obj.x, y - obj.y);
    }

    Vector2D operator * (double scalar) const{
        return Vector2D(x * scalar, y * scalar);
    }
    friend double dotProduct(const Vector2D& v1, const Vector2D& v2);
    friend ostream& operator<<(ostream& os,const Vector2D& v);
};

double dotProduct(const Vector2D& v1, const Vector2D& v2){
    return (v1.x*v2.x)+(v1.y*v2.y);
}

ostream& operator << (ostream& os, const Vector2D& v){
    os<<"("<<v.x<<" , "<<v.y<<")";
    return os;
}

int main(){
    Vector2D a(3,4);
    Vector2D b(5, 1);

    cout<<"A=>  "<<a<<endl;
    cout<<"B=>  "<<b<<endl;
    
    cout<<"Sum: "<<a+b<<endl;
    cout<<"Difference: "<<a-b<<endl;
    cout<<"Scalor Multiple: "<<a*3.0<<endl;
    cout<<"Dot product: "<<dotProduct(a,b)<<endl;

    return 0;
}
