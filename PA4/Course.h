#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include "Student.h"
using namespace std;

namespace PA4{
    class Student;
    class Course{
        private:
            string Name;
            int Code = 0;
            Student *Student_ref = nullptr;
        public:
            Course();
            Course(string name , int code);
            //~Course();
            string getName();
            int getCode();
            void setName(string name);
            void setCode(int code);
    };
}




#endif