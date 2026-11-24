
#include <iostream>
#include "../inc/Book.hpp"
#include "../inc/Library.hpp"

using namespace std;

int main() {
    // Item 13 - gestionarea automata a memoriei
    Book b(200);
    cout << "Item 13: " << b.getPages() << endl;

    // Item 14 - proprietate partajata
    Library l1(200);
    Library l2(300);

    cout << "Initial:" << endl;
    cout << "L1: " << l1.getPages() << endl;
    cout << "L2: " << l2.getPages() << endl;

    l2.setBook(l1.getBook());

    cout << "Dupa partajare:" << endl;
    cout << "L1: " << l1.getPages() << endl;
    cout << "L2: " << l2.getPages() << endl;

    return 0;
}
