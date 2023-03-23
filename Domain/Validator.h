#ifndef MAIN_CPP_VALIDATOR_H
#define MAIN_CPP_VALIDATOR_H


#include <string>

class Validator {
public:
    //Product validator
    static bool validateName(const std::string &str);

    static bool validateCode(unsigned int code);

    static bool validatePrice(float price);

    static bool valdidateStock(unsigned int stock);

    //Coin validator
    static bool validateValue(double value);

    static bool validateNumber(unsigned int number);

};

class ValidatorException {
private:
    const std::string err;
public:
    const std::string &get_msg() const { return this->err; };

    ValidatorException(const std::string err) : err(err) {};

    friend std::ostream &operator<<(std::ostream &out, ValidatorException &err);
};

std::ostream &operator<<(std::ostream &out, ValidatorException &err);


#endif //MAIN_CPP_VALIDATOR_H
