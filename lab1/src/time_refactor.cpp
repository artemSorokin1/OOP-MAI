#include "time_refactor.h"


std::string time_refactor(short hours, short min, std::string format) {

    if (hours <= 0 || hours > 12 || min > 59 || min < 0) {
        return "Wrong data!";
    }

    std::string result{""};

    if (format == "am") {
        hours < 10 ? result += '0' + std::to_string(hours) + ':' : result += std::to_string(hours) + ':';
        min <= 9 ? result += '0' + std::to_string(min) : result += std::to_string(min);

    } else if (format == "pm") {
        int remainder = (hours + 12) % 24;
        remainder == 0 ? result += "00:" : result += std::to_string(remainder) + ':';
        min <= 9 ? result += '0' + std::to_string(min) : result += std::to_string(min);

    } else {
        return "Wrong data!";
    }
    return result;
}

