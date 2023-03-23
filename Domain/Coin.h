//
// Created by user on 5/3/2022.
//

#ifndef LAB910_COIN_H
#define LAB910_COIN_H

#include <string>
#include <ostream>
#include <sstream>



class Coin {
private:
    unsigned int code;
    double value;
    unsigned int number;
public:
    Coin();
    Coin(unsigned int code, double value, unsigned int number);
    Coin(const Coin &coin);
    Coin(std::string stringCoin, char separator);
    ~Coin() = default;

    unsigned int getCode() const;

    void setCode(unsigned int code);

    double getValue() const;

    unsigned int getNumber() const;

    void setValue(double value);

    void setNumber(unsigned int number);

    bool operator==(const Coin &rhs) const;

    bool operator!=(const Coin &rhs) const;

    bool operator<(const Coin &rhs) const;

    bool operator>(const Coin &rhs) const;

    bool operator<=(const Coin &rhs) const;

    bool operator>=(const Coin &rhs) const;

    std::string delimitate(char delimitator);

    friend std::ostream &operator<<(std::ostream &os, const Coin &coin);
};


#endif //LAB910_COIN_H
