#include <iostream>
#include <iomanip>
#include "CoinService.h"
#include "../Domain/Validator.h"
#include "../Repository/RepositoryException.h"


CoinService::CoinService(IRepo<Coin> &IRepo) : repo(IRepo) {}

void CoinService::add(double value, unsigned int number) {
        if (!Validator::validateValue(value)) {
            throw ValidatorException("Invalid value!");
        }
        if (!Validator::validateNumber(number)) {
            throw ValidatorException("Invalid number!");
        }
        Coin coin(this->coinCode, value, number);
        repo.add(coin);
        this->coinCode++;

}

std::vector<Coin> CoinService::read() {
    return repo.getAll();
}

void CoinService::update(unsigned int code, double value, unsigned int number) {
        if (!Validator::validateValue(value)) {
            throw ValidatorException("Invalid value!");
        }
        if (!Validator::validateNumber(number)) {
            throw ValidatorException("Invalid number!");
        }
        Coin coin(code, value, number);
        repo.update(code, coin);

}

void CoinService::remove(unsigned int code) {
    try {
        repo.remove(code);
    }
    catch (ValidatorException &err) {
        throw CoinServiceException(err.get_msg());
    }

    catch (RepositoryException &err) {
        throw CoinServiceException(err.get_msg());
    }

}

bool CoinService::verifyChange(double change) {

    std::vector<Coin> coins = repo.getAll();

    for (int i = 4; i >= 0; i--) {
        unsigned int number = coins[i].getNumber();
        if (coins[i].getValue() <= change && number > 0) {
            double value = coins[i].getValue();
            while (change >= coins[i].getValue() && number > 0) {
                if (i > 0) {
                    change -= value;
                    number--;
                } else {
                    change = change - 1 + 0.9;
                    number--;
                    if (change < 0.1 && change > 0) {
                        number--;
                        change = 0;
                    }

                }
            }

        }

       // return true;
    }
    return change == 0;
}

std::vector<double> CoinService::insertMoney() {
    try {
        std::cout << "Insert money: ";
        std::vector<double> money(6, 0.0);

        float curentInsert;
        double moneyInsert = 0.0;

        do {
            do {
                std::cin >> curentInsert;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << "Give a valid value: ";
                    std::cin >> curentInsert;
                }

            }while (std::cin.fail());
            if (curentInsert != 0)
                if (!Validator::validateValue(curentInsert)) {
                    throw ValidatorException("Invalid bacnote!");
                }

            switch ((int) (curentInsert * 10)) {
                case 1: {
                    money[0]++;
                    moneyInsert = moneyInsert + 1 - 0.9;
                    break;
                }
                case 5: {
                    money[1]++;
                    moneyInsert += 0.5;
                    break;
                }
                case 10: {
                    money[2]++;
                    moneyInsert += 1;
                    break;
                }
                case 50: {
                    money[3]++;
                    moneyInsert += 5;
                    break;
                }
                case 100: {
                    money[4]++;
                    moneyInsert += 10;
                    break;
                }
            }
        } while (curentInsert != 0);

        money[5] = moneyInsert;
        std::cout << "Money insert: " << moneyInsert << '\n';
        return money;
    }
    catch (ValidatorException &err) {
        throw CoinServiceException(err.get_msg());
    }

}

void CoinService::giveChange(std::vector<double> &money, double change) {

    std::vector<Coin> coins = repo.getAll();
    std::cout << "Change: ";

    for (int i = 4; i >= 0; i--) {
        unsigned int number = coins[i].getNumber();
        double value = coins[i].getValue();
        while (value <= change && number > 0) {
            number--;
            change -= coins[i].getValue();
            if (change < 0.1 && change > 0) {
                number--;
                std::cout << "0.1" << ",  ";
            }
            else{
                std::cout<<std::setprecision(1) << value << ", ";
            }
        }


        Coin coin(i, value, number);
        repo.update(i, coin);
    }

    std::cout << '\n';

    for (int i = 0; i <= 4; i++) {
        Coin coin(i, coins[i].getValue(), coins[i].getNumber() + money[i]);
        repo.update(i, coin);
    }


}

std::ostream &operator<<(std::ostream &out, CoinServiceException &err) {
    out << err.get_msg();
    return out;
}
