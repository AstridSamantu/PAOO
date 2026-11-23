#pragma once
#include <memory>
#include <string>

class Book {
    std::string title_;
public:
    explicit Book(std::string title);
    const std::string& title() const;
};

// Deep copy: fiecare obiect detine propriul numar de pagini.
class BookCopy {
    std::unique_ptr<int> pages_;
public:
    explicit BookCopy(int pages);
    BookCopy(const BookCopy& other);
    BookCopy& operator=(const BookCopy& other);
    BookCopy(BookCopy&& other) noexcept = default;
    BookCopy& operator=(BookCopy&& other) noexcept = default;
    int pages() const;
    void setPages(int pages);
};
