
#include "../inc/Client.hpp"

// Constructor Client
Client::Client(string n) {
    name = n;
}

// Getter pentru nume
string Client::getName() const {
    return name;
}

// Constructor PremiumClient
PremiumClient::PremiumClient(string n, int p) : Client(n) {
    points = p;
}

// Item 12 - copiem toate atributele
PremiumClient& PremiumClient::operator=(const PremiumClient& other) {

    // Copiem partea mostenita (numele)
    Client::operator=(other);

    // Copiem atributul propriu (punctele)
    points = other.points;

    return *this;
}

// Getter pentru puncte
int PremiumClient::getPoints() const {
    return points;
}
