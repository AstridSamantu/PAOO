#pragma once

#include <string>

class Student {
private:
    std::string name;
    int numberOfGrades;
    int* grades;

public:
    Student(std::string name, int numberOfGrades);
    ~Student();
};
