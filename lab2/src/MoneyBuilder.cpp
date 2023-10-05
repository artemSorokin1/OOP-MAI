#include "MoneyBuilder.h"


MoneyBuilder::MoneyBuilder() = default;

Money MoneyBuilder::build() {
    return object;
}

MoneyBuilder& MoneyBuilder::setArray(std::vector<unsigned char> &start_money) {
    this->object.sum_of_money = start_money;
    return *this;
}
