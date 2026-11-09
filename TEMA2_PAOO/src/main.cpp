
#include <iostream>
#include "Instrument.hpp"
#include "Magazin.hpp"
#include "Boxa.hpp"
#include "Item5.hpp"
#include "Item6.hpp"

using namespace std;

int main() {
    cout << "\n========================================\n";
    cout << "     MAGAZIN DE INSTRUMENTE MUZICALE\n";
    cout << "========================================\n";

    cout << "\n=== ITEM 4: INITIALIZAREA OBIECTELOR ===\n";

    // 1. Initializarea manuala a tipurilor built-in
    cout << "\n1. Initializarea tipurilor built-in\n";
    cout << "----------------------------------------\n";

    int nrInstrumente = 15;
    double pretChitara = 1200.0;

    cout << "Numar instrumente: " << nrInstrumente << "\n";
    cout << "Pret chitara: " << pretChitara << " lei\n";

    // 2. Lista de initializare a membrilor
    cout << "\n2. Lista de initializare\n";
    cout << "----------------------------------------\n";

    Instrument chitara("Fender", pretChitara, 5);
    chitara.afisare();

    // 3. Obiecte statice locale
    cout << "\n3. Obiecte statice locale (Meyer's Singleton)\n";
    cout << "----------------------------------------\n";

    getMagazin().afisare();
    getMagazin().afisare();

    cout << "\n=== ITEM 5: FUNCTII GENERATE AUTOMAT ===\n";

    // 1. Constructor implicit
    cout << "\n1. Constructor implicit\n";
    cout << "----------------------------------------\n";

    Boxa b1;
    b1.afisare();

    // 2. Constructor de copiere
    cout << "\n2. Constructor de copiere\n";
    cout << "----------------------------------------\n";

    Boxa b2 = b1;
    b2.afisare();

    // 3. Operator de atribuire
    cout << "\n3. Operator de atribuire\n";
    cout << "----------------------------------------\n";

    Boxa b3;
    b3 = b1;
    b3.afisare();

    // 4. Destructor
    cout << "\n4. Destructor\n";
    cout << "----------------------------------------\n";

    cout << "Obiectele locale vor fi distruse automat la iesirea din main.\n";

    // 5. Membru const
    cout << "\n5. Membru const\n";
    cout << "----------------------------------------\n";

    Item5 a(101);
    Item5 b = a;

    a.afisare();
    b.afisare();

    // b = a; // EROARE: operator= sters implicit
    // deoarece clasa Item5 contine un membru const

    cout << "\n=== ITEM 6: INTERZICEREA COPIERII ===\n";

    // 1. Metoda moderna C++11: = delete
    cout << "\n1. Metoda = delete\n";
    cout << "----------------------------------------\n";

    Item6Modern modern1;
    Item6Modern modern2;

    // Item6Modern modern3 = modern1; // EROARE: copy constructor sters
    // modern2 = modern1;             // EROARE: operator= sters

    cout << "Copierea este interzisa explicit prin = delete.\n";

    // 2. Metoda clasica C++98: private
    cout << "\n2. Metoda private\n";
    cout << "----------------------------------------\n";

    Item6Clasic clasic1;
    Item6Clasic clasic2;

    // Item6Clasic clasic3 = clasic1; // EROARE: copy constructor privat
    // clasic2 = clasic1;             // EROARE: operator= privat

    cout << "Copierea este interzisa prin declaratii private.\n";

    cout << "\n========================================\n";
    cout << "           SFARSITUL PROGRAMULUI\n";
    cout << "========================================\n";

    return 0;
}
