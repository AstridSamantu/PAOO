
#pragma once

#include "Book.hpp"
#include <memory>

using namespace std;

class Library {
private:
    shared_ptr<Book> book_;

public:
    Library(int pages);
    int getPages() const;
    void setBook(shared_ptr<Book> book);
    shared_ptr<Book> getBook() const;
};
