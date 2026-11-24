#include "../inc/Book.hpp"
#include <memory>

using namespace std;

// Item 13 - gestionarea automata a resurselor

// Constructor
Book::Book(int pages) {
    pages_ = make_unique<int>(pages);
}

// Getter
int Book::getPages() const {
    return *pages_;
}