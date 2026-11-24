
#include "../inc/Account.hpp"

// Constructor
Account::Account(int amount) {
    balance = amount;
}

// Item 10 + Item 11
Account& Account::operator=(const Account& other) {
    // Item 11 - verificam autoatribuirea
    if (this != &other) {
        balance = other.balance;
    }

    // Item 10 - returnam referinta
    return *this;
}

// Item 10 - adunare
Account& Account::operator+=(int amount) {
    balance += amount;
    return *this;
}

// Item 10 - scadere
Account& Account::operator-=(int amount) {
    balance -= amount;
    return *this;
}

// Getter pentru sold
int Account::getBalance() const {
    return balance;
}
