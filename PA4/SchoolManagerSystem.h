#ifndef SCHOOL_MANAGER_SYSTEM_H
#define SCHOOL_MANAGER_SYSTEM_H

#include <iostream>
#include "Student.h"
#include "Course.h"
using namespace std;

namespace PA4{
    class SchoolManagerSystem{
        private:
            Course *Course_ref = nullptr;
            Student *Student_ref = nullptr;
            int student_counter = 0;
            int course_counter = 0;
            int deletedCourseCounter = 0;
        public:
            SchoolManagerSystem();
            int getDeletedCourseCounter();
            void setDeletedCourseCounter(int num);
            void run();
            void MainMenu();
            void StudentMenu();
            void CourseMenu();
            void SubStudentMenu();
            void SubCourseMenu();
            void addStudent();
            void selectStudent();
            void deleteStudent(string name , string id);
            void addCourse();
            void selectCourse();
            void deleteCourse(string name);
            void ListAllStudents();
            void ListAllCourse();
            void printplease(string name ,string id);
            void print(string name , string id);
            void addStudentToACourse(string name , string id);
            ~SchoolManagerSystem();
            
            

    };

}


#endif