#include "LabCourse.h"
#include "Course.h"
#include <iostream>
using namespace std;

LabCourse::LabCourse(std::string cc, int c) : Course(cc, c) {}
void LabCourse::displayInfo()
{
    cout << "Lab Course code:" << courseCode << "\nCredits:" << credits << endl;
}
void LabCourse::calculateGrade()
{
    cout << "Calculating Grade for Lab course...\n";
}
