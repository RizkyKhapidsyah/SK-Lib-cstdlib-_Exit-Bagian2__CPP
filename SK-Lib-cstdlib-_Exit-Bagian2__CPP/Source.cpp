#include <iostream>
#include <conio.h>

/*
    Source by CPPReference (https://en.cppreference.com)
    Modified For Learn by RK
    I.D.E : VS2022
*/

class Static {
public:
    ~Static() {
        std::cout << "Static dtor\n";
    }
};

class Local {
public:
    ~Local() {
        std::cout << "Local dtor\n";
    }
};

Static static_variable; // dtor of this object will *not* be called

void atexit_handler() {
    std::cout << "atexit handler\n";
}

int main() {
    Local local_variable; // dtor objek ini *tidak* akan dipanggil

    // handler *tidak* akan dipanggil
    const int result = std::atexit(atexit_handler);

    if (result != 0) {
        std::cerr << "atexit registration failed\n";
        return EXIT_FAILURE;
    }

    std::cout << "test" << std::endl; // flush dari std::endl
    // harus ada di sini, jika tidak, tidak akan ada yang dicetak
    std::_Exit(EXIT_FAILURE);

    _getch();
    return 0;
}