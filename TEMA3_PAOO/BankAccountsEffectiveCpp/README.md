# Effective C++ – Items 10, 11, 12

Tema: Gestionarea simplificata a conturilor bancare.

- Item 10: `Account` returneaza `Account&` din `=`, `+=`, `-=` si `operator=(int)`, permitand inlantuirea.
- Item 11: `Balance` detine un `int*` alocat dinamic; `operator=` verifica identitatea si copiaza inainte de stergere; `assignCopyFirst` si `assignCopySwap` demonstreaza separat celelalte strategii. Move assignment elibereaza resursa veche si lasa sursa valida.
- Item 12: `PremiumClient` copiaza explicit baza `Client` si toti membrii proprii.

## Compilare si rulare (Debian / VS Code)

```bash
cmake -S . -B build
cmake --build build
./build/BankAccountsEffectiveCpp
```

Alternativ:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic src/*.cpp -o proiect
./proiect
```

Programul verifica rezultatele cu `assert` si afiseaza `ALL TESTS PASSED`.
