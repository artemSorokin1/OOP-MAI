#include "money.h"


int main() {
    try {
        Money money1("123");

        Money money2("123");

       bool a = money1 >= money2;

       std::cout << a << '\n';

    }
    catch (std::exception & ex) {
        std::cout << "error:\t" <<  ex.what() << '\n';
    }

    return 0;
}
