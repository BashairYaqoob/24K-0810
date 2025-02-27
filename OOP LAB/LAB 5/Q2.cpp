#include <iostream>
using namespace std;

class Student
{
private:
    int ID;
    string name;
    int* scores;
    int cntscores;
public:
    Student(int id, string n, int* inputscores, int cnt): ID(id), name(n), cntscores(cnt){
        scores=new int[cntscores];
        for (int i = 0; i < cntscores; i++)
        {
            scores[i]=inputscores[i];
        }
    }
    Student(Student &obj): ID(obj.ID), name(obj.name), cntscores(obj.cntscores){
        scores=new int[cntscores];
        for (int i = 0; i < cntscores; i++)
        {
            scores[i]=obj.scores[i];
        }
    }
    void display(){
        cout<<"ID:"<<ID<<" , Name:"<<name<<" , Scores:";
        for (int i = 0; i < cntscores; i++)
        {
            cout<<scores[i]<<" ";
        }
        cout << endl;
    }
    ~Student(){
        delete[] scores;
    }
};

int main(){
    int arr[]={93, 96, 87, 79, 68};
    Student s1(101, "Batish", arr, 5);
    Student s2(s1);
    s1.display();
    s2.display();
    return 0;
}
