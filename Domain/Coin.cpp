#include <vector>
#include "Coin.h"

Coin::Coin() {
    this->code = 0;
    this->value = 0;
    this->number = 0;
}

Coin::Coin(unsigned int code, double value, unsigned int number) {
    this->code = code;
    this->value = value;
    this->number = number;
}

Coin::Coin(const Coin &coin) {
    this->code = coin.code;
    this->value = coin.value;
    this->number = coin.number;
}

Coin::Coin(std::string stringCoin, char separator) {
    std::vector<std::string> entities;
    std::stringstream ss (stringCoin);
    std::string object;
    while (getline (ss, object, separator)) {
        entities.push_back(object);
    }
    if(entities.size() == 3) {
        std::stringstream  c(entities[0]);
        c >> this->code;
        std::stringstream v(entities[1]);
        v >> this->value;
        std::stringstream n(entities[2]);
        n >> this->number;
    }
}



double Coin::getValue() const {
    return value;
}

unsigned int Coin::getNumber() const{
    return number;
}

void Coin::setValue(double value)  {
    Coin::value = value;
}

void Coin::setNumber(unsigned int number) {
    Coin::number = number;
}

bool Coin::operator==(const Coin &rhs) const {
    return value == rhs.value &&
           number == rhs.number;
}

bool Coin::operator!=(const Coin &rhs) const {
    return !(rhs == *this);
}

bool Coin::operator<(const Coin &rhs) const {
    if (value < rhs.value)
        return true;
    if (rhs.value < value)
        return false;
    return number < rhs.number;
}

bool Coin::operator>(const Coin &rhs) const {
    return rhs < *this;
}

bool Coin::operator<=(const Coin &rhs) const {
    return !(rhs < *this);
}

bool Coin::operator>=(const Coin &rhs) const {
    return !(*this < rhs);
}

std::string Coin::delimitate(char delimitator) {
    return std::to_string(this->code) + delimitator +std::to_string(this->value) + delimitator + std::to_string(this->number);
}

std::ostream &operator<<(std::ostream &os, const Coin &coin) {
    os <<"Coin{" <<'\n' << "value: " << coin.value << ", number: " << coin.number << '\n' << '}' << '\n';
    return os;
}

unsigned int Coin::getCode() const {
    return this->code;
}

void Coin::setCode(unsigned int code) {
    this->code = code;
}

