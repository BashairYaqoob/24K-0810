#ifndef COURSE
#define COURSE
#include <iostream>
#include <string>
using namespace std;

class Course{
    protected:
    string courseCode;
    int credits;
    public:
    Course() : courseCode(""), credits(0) {}
    Course(string cc, int c) : courseCode(cc), credits(c) {}
    virtual void displayInfo()=0;
    virtual void calculateGrade()=0;
};
#endif
