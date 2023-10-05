#pragma once
#include <iostream>
#include "money.h"


class MoneyBuilder {
private:
    Money object;
public:
    MoneyBuilder();
    Money build();
    MoneyBuilder& setArray(std::vector<unsigned char> & start_money);
};