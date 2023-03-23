#include "Validator.h"


bool Validator::validateName(const std::string &str) {
    if (str.empty())
        return false;

    int space = 0;

    for (const auto &c: str)
        if (isspace(c))
            space++;
    if (space == str.size())
        return false;
    for (const auto &c: str)
        if (isdigit(c) || (!isalnum(c) && !isspace(c)))
            return false;

    return true;
}

bool Validator::validateCode(unsigned int code) {
    if (code < 0)
        return false;
    return true;
}

bool Validator::validatePrice(float price) {
    if (price <= 0)
        return false;
    return true;
}

bool Validator::validateValue(double value) {
    double accptedValues[10] = {0.1, 0.5, 1, 5, 10};

    for (int i = 0; i <= 4; i++) {
        if (value == accptedValues[i]) {
            return true;
        }
    }

    if (value < 0.11 && value > 0.09)
        return true;

    return false;
}

bool Validator::validateNumber(unsigned int number) {
    if (number < 0) {
        return false;
    }
    return true;
}

bool Validator::valdidateStock(unsigned int stock) {
    if (stock < 0)
        return false;
    return true;
}

std::ostream &operator<<(std::ostream &out, ValidatorException &err) {
    out << err.get_msg();
    return out;
}

