#include "money.h"


#define all(x) x.begin(), x.end()



Money::~Money(){

}


Money::Money(Money &&other) {
    this->sum_of_money = other.sum_of_money;
    other.~Money();
}


Money::Money(std::string start_sum) {
    int n = (int)start_sum.size();
    for (int i = 0; i < n; ++i) {
        if (start_sum[i] != ',' && (start_sum[i] < '0' || start_sum[i] > '9'))
            throw std::invalid_argument("Incorect data");
        else if (start_sum[i] != ',') {
            this->sum_of_money.push_back(static_cast<unsigned char>(start_sum[i]));
        }
    }
}


Money::Money(const Money &money) : sum_of_money(money.sum_of_money) {}


Money& Money::operator= (const Money &money) {
    this->sum_of_money = money.sum_of_money;
    return *this;
}


Money& operator+ (Money& money1, Money& money2) {
    std::vector<unsigned char> result;
    size_t sum_of_money_1_size = money1.sum_of_money.size();
    size_t sum_of_money_2_size = money2.sum_of_money.size();
    std::reverse(all(money1.sum_of_money));
    std::reverse(all(money2.sum_of_money));
    result.resize(std::max(sum_of_money_1_size, sum_of_money_2_size));
    int reminder = 0;
    for (size_t i = 0; i < std::min(sum_of_money_1_size, sum_of_money_2_size); i++) {
        int temp = reminder + (money1.sum_of_money[i] - '0') + (money2.sum_of_money[i] - '0');
        reminder = temp / 10;
        temp = temp % 10;
        result[i] = static_cast<unsigned char>(temp + '0');
    }

    if (sum_of_money_1_size > sum_of_money_2_size) {
        for (size_t i = sum_of_money_2_size; i < sum_of_money_1_size; ++i) {
            int temp = reminder + (money1.sum_of_money[i] - '0');
            reminder = temp / 10;
            temp %= 10;
            result[i] = static_cast<unsigned char>(temp + '0');
        }
    } else if (sum_of_money_1_size < sum_of_money_2_size) {
        for (size_t i = sum_of_money_1_size; i < sum_of_money_2_size; ++i) {
            int temp = reminder + (money2.sum_of_money[i] - '0');
            reminder = temp / 10;
            temp %= 10;
            result[i] = static_cast<unsigned char>(temp + '0');
        }
    }

    if (reminder != 0) {
        result.push_back(static_cast<unsigned char>(reminder + '0'));
    }

    std::reverse(all(result));
    money1.sum_of_money = result;

    return money1;
}


Money& operator- (Money& money1, Money& money2) {
    int len_sum_of_money1 = money1.sum_of_money.size();
    int len_sum_of_money2 = money2.sum_of_money.size();
    std::vector<int> sum_of_money1(len_sum_of_money1), sum_of_money2(len_sum_of_money2);
    for (int i = 0; i < len_sum_of_money1; ++i) {
        sum_of_money1[i] = money1.sum_of_money[i] - '0';
    }
    for (int i = 0; i < len_sum_of_money2; ++i) {
        sum_of_money2[i] = money2.sum_of_money[i] - '0';
    }
    if (len_sum_of_money1 > len_sum_of_money2) {
        std::reverse(all(sum_of_money2));
        for (int i = 0; i < len_sum_of_money1 - len_sum_of_money2; ++i) {
            sum_of_money2.push_back(0);
        }
        std::reverse(all(sum_of_money2));
    } else {
        std::reverse(all(sum_of_money1));
        for (int i = 0; i < len_sum_of_money2 - len_sum_of_money1; ++i) {
            sum_of_money1.push_back(0);
        }
        std::reverse(all(sum_of_money1));
    }


    std::vector<int> result(std::max(len_sum_of_money1, len_sum_of_money2));
    std::vector<unsigned char> temp;
    for (int i = (int)result.size() - 1; i >= 0; --i) {
        result[i] = sum_of_money1[i] - sum_of_money2[i];
    }

    if (result[0] < 0) {
        for (int i = 0; i < result.size(); ++i) {
            result[i] = abs(result[i]);
        }

        temp.push_back('-');
        for (int i = 0; i < result.size(); ++i) {
            temp.emplace_back(static_cast<unsigned char>(result[i] + '0'));
        }
        money1.sum_of_money = temp;
        return money1;
    }

    for (int i = result.size() - 1; i >= 0; --i) {
        if (result[i] < 0) {
            result[i - 1]--;
            result[i] += 10;
        }
    }

    for (int i = 0; i < result.size(); ++i) {
        temp.emplace_back(static_cast<unsigned char>(result[i] + '0'));
    }

    std::reverse(all(temp));
    for (auto rit = temp.rbegin(); rit != temp.rend(); ++rit) {
        if (*rit == '0') {
            temp.pop_back();
        } else
            break;
    }
    money1.sum_of_money = temp;

    return money1;

}


std::ostream& operator<< (std::ostream & out, const Money & money) {
    int n = (int)money.sum_of_money.size();
    for (int i = 0; i < n - 2; ++i) {
        out << money.sum_of_money[i];
    }
    out << ',' << money.sum_of_money[n - 2] << money.sum_of_money[n - 1];

    return out;
}


bool operator== (const Money& money1, const Money & money2) { return money1.sum_of_money == money2.sum_of_money; }


bool operator> (const Money& money1, const Money & money2) {
    if (money1.sum_of_money.size() != money2.sum_of_money.size()) {
        return money1.sum_of_money.size() > money2.sum_of_money.size();
    }
    return money1.sum_of_money > money2.sum_of_money;
}


bool operator< (const Money& money1, const Money & money2) {
    if (money1.sum_of_money.size() != money2.sum_of_money.size()) {
        return money1.sum_of_money.size() < money2.sum_of_money.size();
    }
    return money1.sum_of_money < money2.sum_of_money;
}


bool operator<= (const Money& money1, const Money & money2) {
    if (money1.sum_of_money.size() != money2.sum_of_money.size()) {
        return money1.sum_of_money.size() < money2.sum_of_money.size();
    }
    return money1.sum_of_money <= money2.sum_of_money;
}


bool operator>= (const Money& money1, const Money & money2) {
    if (money1.sum_of_money.size() != money2.sum_of_money.size()) {
        return money1.sum_of_money.size() > money2.sum_of_money.size();
    }
    return money1.sum_of_money >= money2.sum_of_money;
}


bool operator!= (const Money& money1, const Money & money2) {
    return money1.sum_of_money != money2.sum_of_money;
}


std::string Money::getSumOfMoney() const {
    std::string str = "";
    for (const auto & elem : this->sum_of_money) {
        str += elem;
    }
    return str;
}


