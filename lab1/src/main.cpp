#include "time_refactor.h"


//  Номер по списку - 25
//  Вариант - 5


int main() {
    short hours, min;
    char symbol = ':';
    std::string format;
    std::cin >> hours >> symbol >> min >> format;
    std::cout << time_refactor(hours, min, format) << std::endl;
    return 0;
}

