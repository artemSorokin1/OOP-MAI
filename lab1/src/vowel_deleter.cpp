#include "vowel_deleter.h"


const std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};

std::string vowel_deleter(std::string str) {
    std::string result {""};
    for (auto symbol : str) {
        bool is_delete_vowel = false;
        for (const auto & vowel : vowels) {
            if (tolower(symbol) == vowel)
                is_delete_vowel = true;
        }
        if (!is_delete_vowel)
            result += symbol;
    }
    return result;
}



