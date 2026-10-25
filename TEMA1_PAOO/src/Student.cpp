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

Student::Student(const Student& other)
    : name(other.name),
      numberOfGrades(other.numberOfGrades),
      grades(new int[other.numberOfGrades])
{
    for (int i = 0; i < numberOfGrades; i++)
    {
        grades[i] = other.grades[i];
    }

    cout << "Copy constructor called" << endl;
}

Student::Student(Student&& other) noexcept
    : name(other.name),
      numberOfGrades(other.numberOfGrades),
      grades(other.grades)
{
    other.numberOfGrades = 0;
    other.grades = nullptr;

    cout << "Move constructor called" << endl;
}

Student::~Student()
{
    delete[] grades;
    cout << "Destructor called" << endl;
}