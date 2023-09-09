#include "time_refactor.h"

std::string time_refactor(short hours, short min, std::string format) {
    if (hours <= 0 || hours > 12 || min > 59 || min < 0) {
        std::cerr << "wrong data!" << std::endl;
        return "";
    }
    std::string result{""};
    if (format == "am") {
        if (hours < 10) {
            result += '0' + std::to_string(hours) + ':';
        } else {
            result += std::to_string(hours) + ':';
        }
        if (min <= 9) {
            return result + '0' + std::to_string(min);
        } else {
            return result + std::to_string(min);
        }
    } else if (format == "pm") {
        int t = (hours + 12) % 24;
        if (t == 0) {
            result += "00:";
        } else result += std::to_string(t) + ':';
        if (min <= 9) {
            return result + '0' + std::to_string(min);
        } else {
            return result + std::to_string(min);
        }
    } else {
        std::cerr << "wrong data!" << std::endl;
        return "";
    }
}

