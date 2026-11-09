#ifndef BOXA_HPP
#define BOXA_HPP

#include <string>
using namespace std;

class Boxa {
private:
    string model;
    int putere = 0;
    double pret = 0.0;

public:
    void afisare() const;
};

#endif