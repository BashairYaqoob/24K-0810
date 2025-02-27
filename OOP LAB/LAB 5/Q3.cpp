#include "iostream"
#include <string>
using namespace std;

class Employees{
    public:
    string name;
    string Designation;
    Employees( string n, string d): name(n), Designation(d){}
};
class projects{
    public:
    string title;
    string deadline;
    Employees *e[10];
    int ec=0;
    projects (string t, string d): title(t), deadline(d){}
    void addemployee(Employees *emp){
        if(ec<10){
            e[ec++]=emp;
        }
    }
    void display(){
        cout<<"Project title: "<<title<<"Deadline: "<<deadline<<endl;
        for (int i = 0; i < ec; i++)
        {
            cout<<"Employee name: "<<e[i]->name<<"Employee Designation: "<<e[i]->Designation;
        }
        
    }
};
int main(){
    projects p1("webhunt", "2 week");
    Employees e1("Shahira", "HOD");
    p1.addemployee(&e1);
    p1.display();
}
