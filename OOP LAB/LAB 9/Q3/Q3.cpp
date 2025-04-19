#include <iostream>
#include "Course.h"
#include "LectureCourse.h"
#include "LabCourse.h"
using namespace std;

int main(){
    Course* c[5];
    c[0] = new LectureCourse("PF101", 3);
    c[1] = new LabCourse("OOP102", 1);
    c[2] = new LectureCourse("MVC204", 3);
    c[3] = new LabCourse("EW420", 2);
    c[4] = new LectureCourse("AP432", 1);
    for (int i = 0; i < 5; i++) {
        c[i]->displayInfo();
        c[i]->calculateGrade();
        cout << "--------------------------" <<endl;
    }
    return 0;
}
