#include <iostream>
#include "Boxa.hpp"

using namespace std;

void Boxa::afisare() const {
    cout << "Model: " << model << "\n";
    cout << "Putere: " << putere << " W\n";
    cout << "Pret: " << pret << " lei\n";
}