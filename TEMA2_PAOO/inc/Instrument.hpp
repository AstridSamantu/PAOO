
#ifndef INSTRUMENT_HPP
#define INSTRUMENT_HPP

#include <string>
using namespace std;

class Instrument {
private:
    string nume;
    double pret;
    int stoc;

public:
    Instrument(const string& n, double p, int s)
        : nume(n), pret(p), stoc(s) {
    }

    void afisare() const;
};

#endif
