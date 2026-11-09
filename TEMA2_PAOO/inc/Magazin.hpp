
#ifndef MAGAZIN_HPP
#define MAGAZIN_HPP

#include <string>
using namespace std;

class Magazin {
private:
    string nume;

public:
    Magazin();
    void afisare() const;
};

Magazin& getMagazin();

#endif
