
#include <iostream>
#include "Instrument.hpp"

using namespace std;

void Instrument::afisare() const {
    cout << "Instrument: " << nume << "\n";
    cout << "Pret: " << pret << " lei\n";
    cout << "Stoc: " << stoc << " bucati\n";
}
