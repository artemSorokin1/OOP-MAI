#include "vowel_deleter.h"


std::vector<char> symbols = {'a', 'e', 'i', 'o', 'u', 'y'};

std::string vowel_deleter_v2(std::string input) {
    std::string res {""};
    for (auto & elem : input) {
        const char elem_lower = tolower(elem);
        bool cheak = false;
        for (const auto & symbol : symbols) {
            if (elem_lower == symbol) {
                cheak = true;
            }
        }
        if (!cheak) res += elem;
    }
    return res;
}

std::string vowel_deleter_v1(std::string input) {
    std::string res {""};
    for (auto & elem : input) {
        char elem_lower = tolower(elem);
        if (elem_lower != 'a' && elem_lower != 'e' && elem_lower != 'i' && elem_lower != 'o' && elem_lower != 'u' && elem_lower != 'y') {
            res += elem;
        }
    }
    return res;
}

