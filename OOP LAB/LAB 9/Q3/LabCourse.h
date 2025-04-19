#ifndef LABECOURSE
#define LABCOURSE

#include "Course.h"

class LabCourse: public Course{
    public:
    LabCourse(std::string cc, int c);
    void displayInfo();
    void calculateGrade();
};

#endif
