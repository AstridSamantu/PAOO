#include "../inc/Account.hpp"
#include <utility>

Balance::Balance(int amount) : amount_(new int(amount)) {}
Balance::Balance(const Balance& other)
    : amount_(other.amount_ ? new int(*other.amount_) : nullptr) {}
Balance::Balance(Balance&& other) noexcept : amount_(other.amount_) {
    other.amount_ = nullptr;
}
Balance::~Balance() { delete amount_; }

Balance& Balance::operator=(const Balance& other) {
    if (this == &other) return *this; // metoda 1: identity check
    return assignCopyFirst(other);    // metoda 2: copy first, delete after
}
Balance& Balance::assignCopyFirst(const Balance& other) {
    int* copy = other.amount_ ? new int(*other.amount_) : nullptr;
    delete amount_;
    amount_ = copy;
    return *this;
}
Balance& Balance::assignCopySwap(Balance other) {
    swap(other); // metoda 3: copy and swap (parametru prin valoare)
    return *this;
}
void Balance::swap(Balance& other) noexcept {
    using std::swap;
    swap(amount_, other.amount_);
}
Balance& Balance::operator=(Balance&& other) noexcept {
    if (this != &other) {
        delete amount_; // eliberam resursa veche
        amount_ = other.amount_;
        other.amount_ = nullptr;
    }
    return *this;
}
int Balance::get() const { return amount_ ? *amount_ : 0; }

Account::Account(int amount) : balance_(amount) {}
Account& Account::operator=(const Account& other) {
    if (this != &other) balance_ = other.balance_;
    return *this;
}
Account& Account::operator=(int amount) {
    balance_ = Balance(amount);
    return *this;
}
Account& Account::operator+=(int amount) {
    *this = getBalance() + amount;
    return *this;
}
Account& Account::operator-=(int amount) {
    *this = getBalance() - amount;
    return *this;
}
int Account::getBalance() const { return balance_.get(); }
