#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <utility>


class Money {
private:
    std::vector<unsigned char> sum_of_money;
public:

    Money(std::string start_sum = "000");
    Money(std::initializer_list<unsigned char> list) : sum_of_money(list) {}
    ~Money();
    Money(const Money & money);
    Money& operator= (const Money& money);
    friend std::ostream& operator<< (std::ostream & out, const Money & money);
    friend Money& operator+ (Money& money1, Money& money2);
    friend Money& operator- (Money& money1, Money& money2);
    friend bool operator== (const Money& money1, const Money & money2);
    friend bool operator< (const Money& money1, const Money & money2);
    friend bool operator> (const Money& money1, const Money & money2);
    friend bool operator>= (const Money& money1, const Money & money2);
    friend bool operator<= (const Money& money1, const Money & money2);
    friend bool operator!= (const Money& money1, const Money & money2);
    std::string get() const;
};


std::ostream& operator<< (std::ostream & out, const Money & money);

Money& operator+ (Money& money1, Money& money2);

Money& operator- (Money& money1, Money& money2);

bool operator== (const Money& money1, const Money & money2);

bool operator!= (const Money& money1, const Money & money2);

bool operator> (const Money& money1, const Money & money2);

bool operator< (const Money& money1, const Money & money2);

bool operator<= (const Money& money1, const Money & money2);

bool operator>= (const Money& money1, const Money & money2);

