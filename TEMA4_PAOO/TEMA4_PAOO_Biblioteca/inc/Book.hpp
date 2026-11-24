#ifndef BOOK_HPP
#define BOOK_HPP

#include <memory>
using namespace std;

class Book {
private:
    unique_ptr<int> pages_;

public:
    Book(int pages);
    int getPages() const;
};

#endif