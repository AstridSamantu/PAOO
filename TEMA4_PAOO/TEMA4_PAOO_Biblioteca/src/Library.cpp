
#include "../inc/Library.hpp"

using namespace std;

Library::Library(int pages) {
    book_ = make_shared<Book>(pages);
}

int Library::getPages() const {
    return book_->getPages();
}

void Library::setBook(shared_ptr<Book> book) {
    book_ = book;
}

shared_ptr<Book> Library::getBook() const {
    return book_;
}
