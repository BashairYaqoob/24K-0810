#include "LectureCourse.h"
#include "Course.h"
#include <iostream>
using namespace std;

LectureCourse::LectureCourse(string cc, int c) : Course(cc, c) {}
void LectureCourse::displayInfo()
{
    cout << "Lecture Course code:" << courseCode << "\nCredits:" << credits << endl;
}
void LectureCourse::calculateGrade()
{
    cout << "Calculating Grade for Lecture course...\n";
}
