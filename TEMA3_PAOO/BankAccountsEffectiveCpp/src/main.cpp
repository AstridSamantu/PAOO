#include "../inc/Account.hpp"
#include "../inc/Client.hpp"
#include <cassert>
#include <iostream>
#include <utility>

int main() {
    std::cout << "=== ITEM 10: Assignment returns *this ===\n";
    Account a(100), b(200), c(300);
    a = b = c;
    assert(a.getBalance() == 300 && b.getBalance() == 300);
    (a += 50) -= 100;
    assert(a.getBalance() == 250);
    a = 500;
    assert(a.getBalance() == 500);
    std::cout << "Chaining, +=, -=, assignment from int: OK\n";

    std::cout << "\n=== ITEM 11: Self-assignment and resources ===\n";
    Balance x(10), y(20);
    Balance* px = &x;
    Balance* py = &x;
    *px = *py; // aliasing: acelasi obiect
    assert(x.get() == 10);
    Balance arr[2] = {Balance(30), Balance(40)};
    arr[0] = arr[0];
    arr[0] = arr[1];
    assert(arr[0].get() == 40);
    x.assignCopyFirst(y);
    assert(x.get() == 20);
    x.assignCopySwap(x); // sigur si pentru auto-atribuire
    assert(x.get() == 20);
    Balance moved(77);
    x = std::move(moved);
    assert(x.get() == 77 && moved.get() == 0);
    x = std::move(x); // auto-move: nu pierde resursa
    assert(x.get() == 77);
    std::cout << "Identity check, copy-first, copy-swap, move: OK\n";

    std::cout << "\n=== ITEM 12: Copy all parts ===\n";
    PremiumClient p1("Ana", 1, 5000, "Gold");
    PremiumClient p2(p1);
    assert(p2.name() == "Ana" && p2.id() == 1 && p2.creditLimit() == 5000 && p2.tier() == "Gold");
    PremiumClient p3("Maria", 2, 100, "Silver");
    p3 = p1;
    assert(p3.name() == "Ana" && p3.id() == 1 && p3.creditLimit() == 5000 && p3.tier() == "Gold");
    std::cout << "Copy constructor and assignment: OK\n";
    std::cout << "\nALL TESTS PASSED\n";
}
