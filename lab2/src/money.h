#pragma once
#include <iostream>
#include <vector>


class Money {
private:
    std::vector<unsigned char> capacity;
public:

    Money();
    Money(int value);
    ~Money();
    Money(const Money & money);
    friend std::ostream& operator<< (std::ostream & out, const std::vector<unsigned char>);
    friend Money& operator+(Money& money1, Money& money2);
    friend Money& operator-(Money& money1, Money& money2);
};


std::ostream& operator<< (std::ostream & out, const std::vector<unsigned char>);

Money& operator+(Money& money1, Money& money2);

Money& operator-(Money& money1, Money& money2);