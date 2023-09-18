#include "vowel_deleter.h"


const std::vector<char> symbols = {'a', 'e', 'i', 'o', 'u', 'y'};

std::string vowel_deleter(std::string input) {
    std::string result {""};
    for (auto & element : input) {
        const char element_lower = tolower(element);
        bool cheak = false;
        for (const auto & symbol : symbols) {
            if (element_lower == symbol)
                cheak = true;
        }
        if (!cheak)
            result += element;
    }
    return result;
}



