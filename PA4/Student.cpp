#include <iostream>
#include "Student.h"
using namespace std;

namespace PA4 {
    Student::Student() {
        Course_ref = new Course;
    }
    Student::Student(string name , string id) {
        setName(name);
        setId(id);
        Course_ref = new Course;
    }
    void Student::setName(string name) {
        this->Name = name;
    }
    void Student::setId(string id) {
        this->Id = id;
    }
    string Student::getName() {
        return this->Name;
    }
    string Student::getId() {
        return this->Id;
    }
    Course* Student::getCourse_ref() {
        return this->Course_ref;
    }
    void Student::setCourse_ref(Course & course_ref) { // we set students courses here
        Course * temp_ptr = new Course[getAddedCourseNumber() + 2]; // temp ptr initi
        setAddedCourseNumber(1);
        for(int i = 0 ; i < getAddedCourseNumber() ; i++){
            temp_ptr[i] = Course_ref[i]; 
        }
        temp_ptr[getAddedCourseNumber()] = course_ref;
        this->Course_ref = temp_ptr;
        delete [] temp_ptr;
        temp_ptr = nullptr;
        
    }
    void Student::deleteCourseFromStudent(Course & course_ref) {
        Course * temp_ptr = new Course[AddedCourseNumber];
        int j = 1;
        temp_ptr[0] = Course_ref[0];
        for(int i = 1 ; i < AddedCourseNumber + 1 ; i++) {
            if(Course_ref[i].getName() == course_ref.getName()) {
                continue;
            }
            else {
                temp_ptr[j] = Course_ref[i];
                j++;
            }
        }
        Course_ref = temp_ptr;
        AddedCourseNumber--;
        delete [] temp_ptr;
        temp_ptr = nullptr;
    }
    void Student::setAddedCourseNumber(int i) {
        this->AddedCourseNumber += i;
    }
    int Student::getAddedCourseNumber() {
        return this->AddedCourseNumber;
    }
    Student::~Student() {
        
    }
}
