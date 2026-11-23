#pragma once
#include <utility>

class Balance {
    int* amount_;
public:
    explicit Balance(int amount = 0);
    Balance(const Balance& other);
    Balance(Balance&& other) noexcept;
    ~Balance();
    Balance& operator=(const Balance& other); // identity check + copy-first
    Balance& operator=(Balance&& other) noexcept;
    Balance& assignCopyFirst(const Balance& other);
    Balance& assignCopySwap(Balance other);
    void swap(Balance& other) noexcept;
    int get() const;
};

class Account {
    Balance balance_;
public:
    explicit Account(int amount = 0);
    Account& operator=(const Account& other);
    Account& operator=(int amount);
    Account& operator+=(int amount);
    Account& operator-=(int amount);
    int getBalance() const;
};
