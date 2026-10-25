#include <iostream>
#include <utility>
#include "Student.hpp"

using namespace std;

int main()
{
    cout << "--- 1. Constructor ---" << endl;
    Student student1("Astrid", 5);
    student1.print();

    cout << "\n--- 2. Copy constructor ---" << endl;
    Student student2 = student1;
    student2.print();

    cout << "\n--- 3. Move constructor ---" << endl;
    Student student3 = std::move(student1);

    student1.print();
    student3.print();

    cout << "\n--- 4. Sfarsitul programului ---" << endl;

    return 0;
}