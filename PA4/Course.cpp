#include "Course.h"
#include <iostream>
using namespace std;

namespace PA4 {
    Course::Course() {}
    Course::Course(string name , int code) {
        setName(name);
        setCode(code);
    }

    void Course::setName(string name) {
        this->Name = name;
    }

    void Course::setCode(int code) {
        this->Code = code;
    }

    string Course::getName() {
        return this->Name;
    }

    int Course::getCode() {
        return this->Code;
    }
}
