# PAOO - Effective C++ - Item 13 si Item 14

Tema: biblioteca. Proiect C++17 cu exemple mici, independente.

## Item 13 - Use objects to manage resources
- `makeOwnedBook`: `unique_ptr` (un proprietar, distrugere automata).
- `makeSharedBook`: `shared_ptr` (proprietate partajata, contor de referinte).
- `BookLock`: RAII pentru mutex: lock in constructor, unlock in destructor.

## Item 14 - Think carefully about copying behavior in resource-managing classes
- Copiere interzisa: `BookLock` foloseste `= delete`.
- Reference counting: `sharedBookLock` returneaza `shared_ptr` cu custom deleter care apeleaza `unlock` cand dispare ultimul proprietar.
- Deep copy: `BookCopy` aloca o copie separata a numarului de pagini in copy constructor si copy assignment.
- Move: `BookCopy` transfera proprietatea prin move constructor si move assignment.

`sharedBookLock` nu detine memoria mutexului; mutexul trebuie sa existe cat timp exista orice copie a shared_ptr-ului. Exemplul foloseste un mutex local cu durata de viata suficienta. Mutexul este real (`std::mutex`), dar testele sunt single-threaded.

## Compilare
```bash
cmake -S . -B build
cmake --build build
./build/TEMA4_PAOO_Biblioteca
```

Rezultat: `ALL TESTS PASSED`.
