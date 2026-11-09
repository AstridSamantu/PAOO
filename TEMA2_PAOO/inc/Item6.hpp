
#ifndef ITEM6_HPP
#define ITEM6_HPP

// Metoda moderna C++11
class Item6Modern {
public:
    Item6Modern() {}

    Item6Modern(const Item6Modern&) = delete;
    Item6Modern& operator=(const Item6Modern&) = delete;
};

// Metoda clasica C++98
class Item6Clasic {
private:
    Item6Clasic(const Item6Clasic&);
    Item6Clasic& operator=(const Item6Clasic&);

public:
    Item6Clasic() {}
};

#endif
