#ifndef LECTURECOURSE
#define LECTURECOURSE

#include "Course.h"

class LectureCourse: public Course{
    public:
    LectureCourse(std::string cc, int c);
    void displayInfo()override;
    void calculateGrade()override;
};

#endif
