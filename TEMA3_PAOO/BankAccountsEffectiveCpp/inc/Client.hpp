
#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
using namespace std;

class Client {
private:
    string name;

public:
    Client(string n);

    string getName() const;
};

class PremiumClient : public Client {
private:
    int points;

public:
    PremiumClient(string n, int p);

    // Item 12
    PremiumClient& operator=(const PremiumClient& other);

    int getPoints() const;
};

#endif
