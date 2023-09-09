#include "time_refactor.h"


int main() {
    short hours, min;
    char c = ':';
    std::string format;
    std::cin >> hours >> c >> min >> format;
    std::cout << time_refactor(hours, min, format) << std::endl;
    return 0;
}

