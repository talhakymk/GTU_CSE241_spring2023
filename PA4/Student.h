#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "Course.h"
using namespace std;

namespace PA4{
    class Course;
    class Student{
        private:
            string Name;
            string Id;
            Course *Course_ref = nullptr;
            int AddedCourseNumber = 0;
        public:
            Student();
            Student(string name , string id);
            ~Student();
            string getName();
            string getId();
            void setName(string name);
            void setId(string id);
            Course* getCourse_ref();
            void setCourse_ref(Course &course_ref);
            void deleteCourseFromStudent(Course &course_ref);
            int getAddedCourseNumber();
            void setAddedCourseNumber(int i);

    };
}





#endif 