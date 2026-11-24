
#include <iostream>
#include "../inc/Account.hpp"
#include "../inc/Client.hpp"

using namespace std;

int main() {

    // ITEM 10 - Atribuire in lant
    Account a(100), b(200), c(300);

    a = b = c;
    cout << "Item 10: " << a.getBalance() << endl;


    // ITEM 11 - Autoatribuire
    a = a;
    cout << "Item 11: " << a.getBalance() << endl;


    // ITEM 12 - Copierea tuturor atributelor
    PremiumClient p1("Ana", 100);
    PremiumClient p2("Maria", 500);

    p1 = p2;

    cout << "Item 12: " << p1.getName()
         << " " << p1.getPoints() << endl;

    return 0;
}
