#include "../inc/Book.hpp"
#include "../inc/Library.hpp"
#include <cassert>
#include <iostream>
#include <mutex>
#include <utility>

int main() {
    std::cout << "ITEM 13 - RAII si smart pointers\n";
    auto uniqueBook = makeOwnedBook("C++ simplu");
    assert(uniqueBook->title() == "C++ simplu");
    auto shared1 = makeSharedBook("Algoritmi");
    auto shared2 = shared1;
    assert(shared1.use_count() == 2);
    std::cout << "unique_ptr: " << uniqueBook->title() << "\n";
    std::cout << "shared_ptr: " << shared1->title() << ", proprietari=" << shared1.use_count() << "\n";

    std::cout << "\nITEM 14 - copiere si mutare\n";
    std::mutex mutex;
    {
        BookLock guard(mutex); // Nu poate fi copiat.
        assert(!mutex.try_lock());
    }
    assert(mutex.try_lock());
    mutex.unlock();
    std::cout << "BookLock: deblocat automat\n";

    {
        auto lock1 = sharedBookLock(mutex);
        auto lock2 = lock1; // reference counting
        lock1.reset();
        assert(!mutex.try_lock()); // inca detinut de lock2
        lock2.reset(); // custom deleter -> unlock
    }
    assert(mutex.try_lock());
    mutex.unlock();
    std::cout << "shared lock: unlock la ultimul proprietar\n";

    BookCopy original(100);
    BookCopy copy = original; // deep copy
    copy.setPages(200);
    assert(original.pages() == 100 && copy.pages() == 200);
    BookCopy assigned(1);
    assigned = original;
    assert(assigned.pages() == 100);
    assigned = assigned; // self assignment
    BookCopy moved = std::move(copy); // move constructor
    assert(moved.pages() == 200);
    BookCopy destination(10);
    destination = std::move(moved); // move assignment
    assert(destination.pages() == 200);
    std::cout << "deep copy: original=" << original.pages() << ", copie=" << destination.pages() << "\n";
    std::cout << "ALL TESTS PASSED\n";
}
