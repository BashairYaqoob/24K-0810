#include <iostream>
using namespace std;

class MatrixHelper;

class Matrix2x2{
    private:
    int m[2][2];
    public:
    Matrix2x2(int a, int b, int c, int d){
        m[0][0]=a; m[0][1]=b; m[1][0]=c; m[1][1]=d;
    }
    Matrix2x2 operator + (const Matrix2x2& obj){
        return Matrix2x2(
            m[0][0] + obj.m[0][0],
            m[0][1] + obj.m[0][1],
            m[1][0] + obj.m[1][0],
            m[1][1] + obj.m[1][1]
        );
    }
    Matrix2x2 operator-(const Matrix2x2& obj){
        return Matrix2x2(
            m[0][0] - obj.m[0][0],
            m[0][1] - obj.m[0][1],
            m[1][0] - obj.m[1][0],
            m[1][1] - obj.m[1][1]
        );
    }

    Matrix2x2 operator*(const Matrix2x2& obj){
        return Matrix2x2(
            m[0][0] * obj.m[0][0] + m[0][1] * obj.m[1][0],
            m[0][0] * obj.m[0][1] + m[0][1] * obj.m[1][1],
            m[1][0] * obj.m[0][0] + m[1][1] * obj.m[1][0],
            m[1][0] * obj.m[0][1] + m[1][1] * obj.m[1][1]
        );
    }
    friend ostream& operator<<(ostream& out, const Matrix2x2& obj){
        out << obj.m[0][0] << " " << obj.m[0][1] << endl;
        out << obj.m[1][0] << " " << obj.m[1][1] << endl;
        return out;
    }
    friend float determinant(const Matrix2x2& obj);
    friend class MatrixHelper;
};

float determinant(const Matrix2x2& obj){
    return (obj.m[0][0]*obj.m[1][1]-obj.m[0][1]*obj.m[1][0]);
}

class MatrixHelper{
    public:
    void updateElement(Matrix2x2& m1, int r, int c, int newV){
        if(r >= 0 && r < 2 && c >= 0 && c < 2){
            m1.m[r][c] = newV;
        }
    }
};

int main(){
    Matrix2x2 m1(1,2,3,4);
    Matrix2x2 m2(5,1,1,5);

    cout << "Matrix 1:\n" << m1 << endl;
    cout << "Matrix 2:\n" << m2 << endl;

    cout << "Sum: \n" << m1+m2 << endl;
    cout << "Difference: \n" << m1-m2<< endl;
    cout << "Product: \n" << m1*m2 << endl;
    cout << "Determinant of matrix 1: " << determinant(m1) << endl;
    cout << "Determinant of matrix 2: " << determinant(m2) << endl;

    MatrixHelper h;
    h.updateElement(m1, 1, 0, 5);
    cout << "Updated matrix 1: \n" << m1 << endl;

    return 0;
}
