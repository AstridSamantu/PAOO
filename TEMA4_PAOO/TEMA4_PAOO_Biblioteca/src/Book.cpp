#include "../inc/Book.hpp"
#include <stdexcept>
#include <utility>

Book::Book(std::string title) : title_(std::move(title)) {}
const std::string& Book::title() const { return title_; }

BookCopy::BookCopy(int pages) : pages_(std::make_unique<int>(pages)) {}
BookCopy::BookCopy(const BookCopy& other)
    : pages_(other.pages_ ? std::make_unique<int>(*other.pages_) : nullptr) {}
BookCopy& BookCopy::operator=(const BookCopy& other) {
    if (this != &other) {
        auto copy = other.pages_ ? std::make_unique<int>(*other.pages_) : nullptr;
        pages_ = std::move(copy);
    }
    return *this;
}
int BookCopy::pages() const {
    if (!pages_) throw std::logic_error("Obiect mutat: fara pagini");
    return *pages_;
}
void BookCopy::setPages(int pages) {
    if (!pages_) throw std::logic_error("Obiect mutat: fara pagini");
    *pages_ = pages;
}
