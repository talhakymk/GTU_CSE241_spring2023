#include "SchoolManagerSystem.h"
#include <iostream>
using namespace std;

namespace PA4 {
    void SchoolManagerSystem::run() {
        while(true) {
            string choice;
            char cho;
            MainMenu();
            cin >> choice;
            cho = choice[0];
            switch(cho) {
                case '0':
                    break;
                case '1':
                    StudentMenu();
                    break;
                case '2':
                    CourseMenu();
                    break;
                case '3':
                    ListAllStudents();
                    break;
                case '4':
                    ListAllCourse();
                    break;
                default:
                    break;
            }
        }
    }

    void SchoolManagerSystem::ListAllStudents() { // lists all students
        for(int i = 1 ; i < student_counter + 1 ; i++) {
            cout << Student_ref[i].getName() << " " << Student_ref[i].getId()  <<endl;
        } 
    }

    void SchoolManagerSystem::ListAllCourse() { // lists all courses
        for(int i = 1 ; i < course_counter + 1 ; i++){
            cout << Course_ref[i].getCode() << " " << Course_ref[i].getName() << endl;
        } 
    }

    SchoolManagerSystem::SchoolManagerSystem() {
        Student_ref = new Student;
        Course_ref = new Course;
    }

    void SchoolManagerSystem::addStudent() { // add student to a school manager system
        string name;
        string id;
        cin >> name;
        cin >> id;
        Student temp(name , id); // creating temp object
        Student * temp_ptr = new Student[student_counter + 2];
        student_counter++; // when we add student we increment student counter
        for(int i = 0 ; i < student_counter ; i++){
            temp_ptr[i] = Student_ref[i];  // we fold temp ptr
        }
        temp_ptr[student_counter] = temp; // we add new student to temp ptr
        Student_ref = temp_ptr; // we equalize student ref and temp ptr
        delete [] temp_ptr;
        temp_ptr = nullptr;
    }

    void SchoolManagerSystem::deleteStudent(string name , string id) {
        Student * temp_ptr = new Student[student_counter];
        int j = 1;
        temp_ptr[0] = Student_ref[0]; // first indexes are null and we equalize them
        for(int i = 1 ; i < student_counter + 1 ; i++) {
            if(Student_ref[i].getName() == name && Student_ref[i].getId() == id) { // controlling if there is a student which has given name and id 
                continue;
            }
            else {
                temp_ptr[j] = Student_ref[i]; // we fold temp ptr with all student ref except the one we wanted to delete
                j++;
            }
        }
        Student_ref = temp_ptr; // equalize both pointer
        student_counter--;
        delete [] temp_ptr;
        temp_ptr = nullptr;
    }

    void SchoolManagerSystem::addStudentToACourse(string name , string id) {
        int choice;
        cout << "0 up\n";
        for(int i = 1 ; i < course_counter + 1 ; i++) { // printing all courses
             cout << Course_ref[i].getCode() << " " << Course_ref[i].getName() << endl;
        }
        cin >> choice;
        if(choice == 0) {
            return;
        }
        int t = 0;
        for(int k = 1 ; k < course_counter+1 ; k++) { // in this loop  we find course which we want
            if(Course_ref[k].getCode() == choice) {
                t = k;
            }
        }
        for(int j = 1 ; j < student_counter+1 ; j++) {
            if(Student_ref[j].getName() == name && Student_ref[j].getId() == id) {
                Student_ref[j].setCourse_ref(Course_ref[t]); // we set selected course to selected student
            }
        }
    }
    void SchoolManagerSystem::printplease(string name , string id) { // prints all courses student have
         for(int i = 1 ; i < student_counter + 1 ; i++) {
            if(Student_ref[i].getName() == name && Student_ref[i].getId() == id) {
               cout << Student_ref[i].getCourse_ref()[1].getName();
               cout << Student_ref[i].getCourse_ref()[2].getName();
               cout << Student_ref[i].getCourse_ref()[3].getName();
            }
        }
    }

    void SchoolManagerSystem::print(string name , string id) {
        int choice;
        cout << "0 up\n";
        for(int i = 1 ; i < course_counter + 1 ; i++) { // prints all courses
             cout << Course_ref[i].getCode() << " " << Course_ref[i].getName() << endl;
        }
        cin >> choice;
        if(choice == 0) {
            return;
        }
        int t = 0;
        for(int k = 1 ; k < course_counter+1 ; k++) { // find course index which we want to delete
            if(Course_ref[k].getCode() == choice) {
                t = k;
            }
        }
        for(int j = 1 ; j < student_counter+1 ; j++) {
            if(Student_ref[j].getName() == name && Student_ref[j].getId() == id) {
                Student_ref[j].deleteCourseFromStudent(Course_ref[t]); // we  delete selected course from 
            }
        }
    }

    void SchoolManagerSystem::selectStudent() {
        bool control = false;
        string choice;
        string name , id;
        cin >> name >> id;
        for(int i = 1 ; i < student_counter + 1 ; i++) {
            if(Student_ref[i].getName() == name && Student_ref[i].getId() == id) {
                control = true;
            }
        }
        if(!control) {
            return;
        }
        char cho;
        bool loop = true;
        while(loop) {
            cout << "0 up\n"
                 << "1 delete_student\n"
                 << "3 add_selected_student_to_a_course\n"
                 << "4 drop_selected_student_from_a_course\n"
                 << "5 print\n";
            cin >> choice;
            cho = choice[0];
            switch(cho) {
                case '0':
                    loop = false;
                    break;
                case '1':
                    deleteStudent(name , id);
                    loop = false;
                    break;
                case '3':
                    addStudentToACourse(name , id);
                    break;
                case '4':
                    print(name , id);
                    break;
                case '5':
                    printplease(name , id);

            }
        }
    }

    void SchoolManagerSystem::deleteCourse(string name) {
        setDeletedCourseCounter(1);
        Course * temp_ptr = new Course[course_counter];
        int j = 1;
        temp_ptr[0] = Course_ref[0];
        for(int i = 1 ; i < course_counter + 1 ; i++) {
            if(Course_ref[i].getName() == name) { // finding course which we want to delete
                continue;
            }
            else {
                temp_ptr[j] = Course_ref[i]; // we add all courses except we want  to delete
                j++;
            }
        }
        Course_ref = temp_ptr;
        course_counter--;
        delete [] temp_ptr;
        temp_ptr = nullptr;
    }

    void SchoolManagerSystem::selectCourse() {
        bool control;
        string choice;
        string name;
        cin >> name;
        for(int i = 1 ; i < course_counter + 1 ; i++) {
            if(Course_ref[i].getName() == name) {
                control = true;
            }
        }
        if(!control) {
            return;
        }
        char cho;
        bool loop = true;
        while(loop) {
            cout << "0 up\n"
                 << "1 delete_course\n"
                 << "2 list_all_students_registered_to_the_selected_course\n";
            cin >> choice;
            cho = choice[0];
            switch(cho) {
                case '0':
                    loop = false;
                    break;
                case '1':
                    deleteCourse(name);
                    loop = false;
                    break;
            }
        }
    }

    void SchoolManagerSystem::addCourse() {
        string name;
        cin >> name ;
        Course  temp; // temp object created
        if(getDeletedCourseCounter() > 0) {
            temp.setName(name);
            temp.setCode(course_counter + getDeletedCourseCounter() + 1);
        }
        else {
            temp.setName(name);
            temp.setCode(course_counter+1);
        }
        Course * temp_ptr = new Course[course_counter + 2];
        course_counter++; // when we create new course we increment counter
        for(int i = 0 ; i < course_counter ; i++) {
            temp_ptr[i] = Course_ref[i];  // equalizing all courses to temp
        }
        temp_ptr[course_counter] = temp; // adding new course to temp
        Course_ref = temp_ptr; // equalizing both pointers
        delete [] temp_ptr;
        temp_ptr = nullptr;
    }

    int SchoolManagerSystem::getDeletedCourseCounter() {
        return this->deletedCourseCounter;
    }

    void SchoolManagerSystem::setDeletedCourseCounter(int num) {
        this->deletedCourseCounter += num;
    }

    void SchoolManagerSystem::SubStudentMenu() {
        cout << "0 up\n"
             << "1 delete_student\n"
             << "3 add_selected_student_to_a_course\n";
    }

    void SchoolManagerSystem::MainMenu() {
        cout << "0 exit\n" 
             << "1 student\n" 
             << "2 course\n" 
             << "3 list_all_students\n" 
             << "4 list_all_course\n";
    }

    void SchoolManagerSystem::StudentMenu() {
        string choice;
        char cho;
        bool loop = true;
        while(loop){
            cout << "0 up\n"
                 << "1 add_student\n"
                 << "2 select_student\n";
            cin >> choice;
            cho = choice[0];
            switch(cho){
                case '0':
                    loop = false;
                    break;
                case '1':
                    addStudent();
                    break;
                case '2':
                    selectStudent();
                    break;
                default:
                    break;
            }
        }
    }

    void SchoolManagerSystem::CourseMenu() {
        string choice;
        char cho;
        bool loop = true;
        while(loop) {
            cout << "0 up\n"
             << "1 add_course\n"
             << "2 select_course\n";
            cin >> choice;
            cho = choice[0];
            switch(cho) {
                case '0':
                    loop = false;
                    break;
                case '1':
                    addCourse();
                    break;
                case '2':
                    selectCourse();
                    break;
                default:
                    break;
            }
        } 
    }
    
    SchoolManagerSystem::~SchoolManagerSystem() {
        delete [] Student_ref;
    }
}

