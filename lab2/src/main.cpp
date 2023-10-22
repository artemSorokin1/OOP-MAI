#include "money.h"


int main() {
    try {
        Money money1 = {'1', '2', '3'};

        Money money2("2000");

        std::string str = money1.get();
        std::cout << str << '\n';
    }
    catch (std::exception & ex) {
        std::cout << "error:\t" <<  ex.what() << '\n';
    }

    return 0;
}
