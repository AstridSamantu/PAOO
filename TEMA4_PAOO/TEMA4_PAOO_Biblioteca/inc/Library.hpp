#pragma once
#include "Book.hpp"
#include <memory>
#include <mutex>

// RAII: lock in constructor, unlock in destructor; copiere interzisa.
class BookLock {
    std::mutex& mutex_;
public:
    explicit BookLock(std::mutex& mutex);
    ~BookLock();
    BookLock(const BookLock&) = delete;
    BookLock& operator=(const BookLock&) = delete;
};

// Varianta cu shared_ptr si custom deleter: unlock doar la ultimul proprietar.
std::shared_ptr<std::mutex> sharedBookLock(std::mutex& mutex);

std::unique_ptr<Book> makeOwnedBook(const std::string& title);
std::shared_ptr<Book> makeSharedBook(const std::string& title);
