#include "money.h"


Money::Money() {
    money = {'0', '0', '0'};
}


Money::~Money() noexcept {

}


Money::Money(int value) {

}


Money::Money(const Money &money) {

}


Money Money::operator+() {

}


Money Money::operator-() {

}

std::ostream& operator<< (std::ostream & out, const std::vector<unsigned char> & money) {
    int n = (int)money.size();
    for (int i = 0; i < n - 2; ++i) {
        std::cout << money[i];
    }
    std::cout << ',' << money[n - 2] << money[n - 1] << std::endl;
}

