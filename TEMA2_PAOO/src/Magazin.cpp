
#include <iostream>
#include "Magazin.hpp"

using namespace std;

Magazin::Magazin() : nume("Thunder Music Store") {
    cout << "Constructor Magazin apelat!\n";
}

void Magazin::afisare() const {
    cout << "Magazin: " << nume << "\n";
}

Magazin& getMagazin() {
    static Magazin magazin;
    return magazin;
}
