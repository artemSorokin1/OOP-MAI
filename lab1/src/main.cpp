#include "vowel_deleter.h"


//  Номер по списку - 25
//  Вариант - 6, но случаянно сделал 5 и оставил, ибо незачем добру пропадать


//int main() {
//    short hours, min;
//    char symbol = ':';
//    std::string format;
//    std::cin >> hours >> symbol >> min >> format;
//    std::cout << time_refactor(hours, min, format) << std::endl;
//    return 0;
//}


int main() {
    std::string input;
    std::getline(std::cin, input);
    std::cout << vowel_deleter_v1(input) << std::endl;
}

