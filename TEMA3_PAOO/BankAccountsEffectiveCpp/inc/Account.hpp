
#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

class Account {
private:
    int balance;

public:
    // Constructor
    Account(int amount);

    // Item 10 + Item 11
    Account& operator=(const Account& other);

    // Item 10
    Account& operator+=(int amount);
    Account& operator-=(int amount);

    // Getter
    int getBalance() const;
};

#endif
