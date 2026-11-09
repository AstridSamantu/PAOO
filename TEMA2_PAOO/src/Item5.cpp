
#include <iostream>
#include "Item5.hpp"

using namespace std;

Item5::Item5(int c) : cod(c) {
}

void Item5::afisare() const {
    cout << "Cod: " << cod << "\n";
}
