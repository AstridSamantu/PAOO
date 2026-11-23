#include "../inc/Library.hpp"
#include <utility>

BookLock::BookLock(std::mutex& mutex) : mutex_(mutex) { mutex_.lock(); }
BookLock::~BookLock() { mutex_.unlock(); }

std::shared_ptr<std::mutex> sharedBookLock(std::mutex& mutex) {
    mutex.lock();
    try {
        return std::shared_ptr<std::mutex>(&mutex, [](std::mutex* p) { p->unlock(); });
    } catch (...) {
        mutex.unlock();
        throw;
    }
}

std::unique_ptr<Book> makeOwnedBook(const std::string& title) {
    return std::make_unique<Book>(title);
}
std::shared_ptr<Book> makeSharedBook(const std::string& title) {
    return std::make_shared<Book>(title);
}
