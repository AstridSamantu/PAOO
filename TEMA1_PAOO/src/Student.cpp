#include "Student.hpp"
#include <iostream>

using namespace std;

Student::Student(string name, int numberOfGrades)
    : name(name),
      numberOfGrades(numberOfGrades),
      grades(new int[numberOfGrades])
{
    cout << "Constructor called" << endl;
}

Student::~Student()
{
    delete[] grades;
    cout << "Destructor called" << endl;
}