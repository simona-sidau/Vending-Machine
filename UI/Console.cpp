#include <iostream>
#include "Console.h"
#include "../Repository/RepositoryException.h"


Console::Console(Service &service, CoinService &coinService) : service(service), coinService(coinService) {}


void Console::showMainMenu() {
    std::cout << "1. Admin" << '\n';
    std::cout << "2. User" << '\n';
    std::cout << "x. Exit" << '\n';
    std::cout << " Give option: ";
}

void Console::showAdminMenu() {
    std::cout << "1. Add a product" << '\n';
    std::cout << "2. Modify a product" << '\n';
    std::cout << "3. Delete a product" << '\n';
    std::cout << "4. Show all products" << '\n';
    std::cout << "5. Add a coin" << '\n';
    std::cout << "6. Modify a coin" << '\n';
    std::cout << "7. Delete a coin" << '\n';
    std::cout << "8. Show all coins" << '\n';
    std::cout << "x. Exit" << '\n';
    std::cout << "Give option: ";

}

void Console::showUserMenu() {
    std::cout << "The vending machine can accept only 1, 5, 10 lei bacnotes and 10, 50 bani coins!" << '\n';
    std::cout << "1. Show all products" << '\n';
    std::cout << "2. Buy a product" << '\n';
    std::cout << "x. Exit" << '\n';
    std::cout << "Give option: ";
}

void Console::runMenu() {
    char mainOption;
    bool mainShoulRun = true;
    while (mainShoulRun) {
        this->showMainMenu();
        std::cin >> mainOption;
        switch (mainOption) {
            case '1': {
                char option;
                bool shouldRun = true;
                while (shouldRun) {
                    this->showAdminMenu();
                    std::cin >> option;
                    switch (option) {
                        case '1': {
                            int code, stock;
                            std::string name;
                            double price;
                            do {
                                std::cout << "Give code: ";
                                std::cin >> code;
                                if (std::cin.fail()) {
                                    std::cin.clear();
                                    std::cin.ignore();
                                    std::cout << "Give a natural number: "<< '\n';
                                    std::cin >> code;
                                }
                            } while (std::cin.fail());
                            if(code < 0){
                                std::cout << "Invalid code" << '\n';
                                break;
                            }
                            std::cout << "Give name: ";
                            std::cin >> name;

                            do {
                                std::cout << "Give price: ";
                                std::cin >> price;
                                if (std::cin.fail()) {
                                    std::cin.clear();
                                    std::cin.ignore();
                                    std::cout << "Give a number: " << '\n';
                                    std::cin >> price;
                                }
                            } while (std::cin.fail());
                            do {
                                std::cout << "Stock: ";
                                std::cin >> stock;
                                if (std::cin.fail()) {
                                    std::cin.clear();
                                    std::cin.ignore();
                                    std::cout << "Give a natural number: "<< '\n';
                                    std::cin >> stock;
                                }
                            } while (std::cin.fail());
                            try {
                                service.add(code, name, price, stock);
                                std::cout << "Succesfully added!" << '\n';
                            }
                            catch (ServiceException &err) {
                                std::cout << err << '\n';
                            }
                            catch (ValidatorException &err){
                                std::cout << err << '\n';
                            }
                            catch (RepositoryException &err){
                                std::cout << err << '\n';
                            }
                            break;
                        }
                        case '2': {
                            int code, stock;
                            std::string name;
                            double price;
                            try {
                                do {
                                    std::cout << "Give the code of the product to be modified: ";
                                    std::cin >> code;
                                    if (std::cin.fail()) {
                                        std::cin.clear();
                                        std::cin.ignore();
                                        std::cout << "Give a natural number" << '\n';
                                        std::cin >> code;
                                    }
                                } while (std::cin.fail());
                                if(code < 0){
                                    std::cout << "Invalid code" << '\n';
                                    break;
                                }
                                std::cout << "Give the new name: ";
                                std::cin >> name;
                                do {
                                    std::cout << "Give the new price: ";
                                    std::cin >> price;
                                    if (std::cin.fail()) {
                                        std::cin.clear();
                                        std::cin.ignore();
                                        std::cout << "Give a number" << '\n';
                                        std::cin >> price;
                                    }
                                } while (std::cin.fail());
                                do {
                                    std::cout << "Give the new stock: ";
                                    std::cin >> stock;
                                    if (std::cin.fail()) {
                                        std::cin.clear();
                                        std::cin.ignore();
                                        std::cout << "Give a number: "<< '\n';
                                        std::cin >> stock;
                                    }
                                } while (std::cin.fail());
                            }
                            catch (std::invalid_argument) {
                                std::cout << "Invalid argument!" << '\n';
                            }
                            try {
                                service.update(code, name, price, stock);
                                std::cout << "Succesfully updated!" << '\n';
                            }
                            catch (ValidatorException &err){
                                std::cout << err << '\n';
                            }
                            catch (ServiceException &err) {
                                std::cout << err << '\n';
                            }
                            catch (RepositoryException &err){
                                std::cout << err << '\n';
                            }
                            break;
                        }
                        case '3': {
                            int code;
                            do {
                                std::cout << "Give the code of the product to be deleted: ";
                                std::cin >> code;
                                if (std::cin.fail()) {
                                    std::cin.clear();
                                    std::cin.ignore();
                                    std::cout << "Give a natural number" << '\n';
                                    std::cin >> code;
                                }
                            } while (std::cin.fail());
                            if(code < 0){
                                std::cout << "Invalid code" << '\n';
                                break;
                            }
                            try {
                                service.remove(code);
                                std::cout << "Succesfully deleted!" << '\n';
                            }
                            catch (ServiceException &err) {
                                std::cout << err << '\n';
                            }
                            catch (ValidatorException &err) {
                                std::cout << err << '\n';
                            }
                            catch (RepositoryException &err) {
                                std::cout << err << '\n';
                            }
                            break;
                        }
                        case '4': {
                            std::vector<Product> products = service.read();
                            for (int i = 0; i < products.size(); i++) {
                                std::cout << products[i];
                            }
                            break;
                        }
                        case '5': {
                            int number;
                            double value;
                            do {
                                std::cout << "Give value: ";
                                std::cin >> value;
                                if (std::cin.fail()) {
                                    std::cin.clear();
                                    std::cin.ignore();
                                    std::cout << "Give a valid value: "<< '\n';
                                    std::cin >> value;
                                }
                            } while (std::cin.fail());
                            do {
                                std::cout << "Give number: ";
                                std::cin >> number;
                                if (std::cin.fail()) {
                                    std::cin.clear();
                                    std::cin.ignore();
                                    std::cout << "Give a natural number: "<< '\n';
                                    std::cin >> number;
                                }
                            } while (std::cin.fail());
                            if(number < 0){
                                std::cout << "Invalid number" << '\n';
                                break;
                            }
                            try {
                                coinService.add(value, number);
                                std::cout << "Succesfully added!" << '\n';
                            }
                            catch (CoinServiceException &err) {
                                std::cout << err << '\n';
                            }
                            catch (RepositoryException &err){
                                std::cout << err << '\n';
                            }
                            catch (ValidatorException &err){
                                std::cout << err << '\n';
                            }
                            break;
                        }
                        case '6': {
                            int code, number;
                            double value;
                            do {
                                std::cout << "Give the code of the coin to be modified: ";
                                std::cin >> code;
                                if (std::cin.fail()) {
                                    std::cin.clear();
                                    std::cin.ignore();
                                    std::cout << "Give a valid code: "<< '\n';
                                    std::cin >> code;
                                }
                            } while (std::cin.fail());
                            if(code < 0){
                                std::cout << "Invalid code" << '\n';
                                break;
                            }
                            do {
                                std::cout << "Give the new value: ";
                                std::cin >> value;
                                if (std::cin.fail()) {
                                    std::cin.clear();
                                    std::cin.ignore();
                                    std::cout << "Give a valid value: "<< '\n';
                                    std::cin >> value;
                                }
                            } while (std::cin.fail());
                            do {
                                std::cout << "Give the new number: ";
                                std::cin >> number;
                                if (std::cin.fail()) {
                                    std::cin.clear();
                                    std::cin.ignore();
                                    std::cout << "Give a natural number: "<< '\n';
                                    std::cin >> number;
                                }
                            } while (std::cin.fail());
                            if(number < 0){
                                std::cout << "Invalid number" << '\n';
                                break;
                            }
                            try {
                                coinService.update(code, value, number);
                                std::cout << "Succesfully updated!" << '\n';
                            }
                            catch (CoinServiceException &err) {
                                std::cout << err << '\n';
                            }
                            catch (RepositoryException &err){
                                std::cout << err << '\n';
                            }
                            catch (ValidatorException &err){
                                std::cout << err << '\n';
                            }
                            break;
                        }
                        case '7': {
                            int code;
                            do {
                                std::cout << "Give the code of the coin to be deleted: ";
                                std::cin >> code;
                                if (std::cin.fail()) {
                                    std::cin.clear();
                                    std::cin.ignore();
                                    std::cout << "Give a natural number: "<< '\n';
                                    std::cin >> code;
                                }
                            } while (std::cin.fail());
                            if(code < 0){
                                std::cout << "Invalid code" << '\n';
                                break;
                            }
                            try {
                                coinService.remove(code);
                                std::cout << "Succesfully deleted" << '\n';
                            }
                            catch (CoinServiceException &err) {
                                std::cout << err << '\n';
                            }
                            catch (RepositoryException &err){
                                std::cout << err << '\n';
                            }
                            catch (ValidatorException &err){
                                std::cout << err << '\n';
                            }
                            break;
                        }
                        case '8': {
                            std::vector<Coin> coins = coinService.read();
                            for (int i = 0; i < coins.size(); i++) {
                                std::cout << coins[i];
                            }
                            break;
                        }
                        case 'x': {
                            shouldRun = false;
                            break;
                        }
                        default: {
                            std::cout << "Invalid option! Try again!" << '\n';
                            break;
                        }
                    }
                }
                break;
            }
            case '2': {
                char userOption;
                bool userShouldRun = true;
                while (userShouldRun) {
                    this->showUserMenu();
                    std::cin >> userOption;
                    switch (userOption) {
                        case '1': {
                            std::vector<Product> products = service.read();
                            for (int i = 0; i < products.size(); i++) {
                                std::cout << products[i];
                            }
                            break;
                        }
                        case '2': {
                            int codeProduct;
                            double price;
                            std::vector<double> money;
                            try {
                                money = coinService.insertMoney();
                                std::cout << std::endl;

                                do {
                                    std::cout << "Give code: ";
                                    std::cin >> codeProduct;
                                    if(std::cin.fail()){
                                        std::cin.clear();
                                        std::cin.ignore();
                                        std::cout << "Give a valid code: ";
                                        std::cin >> codeProduct;
                                    }
                                }while(std::cin.fail());
                                if(codeProduct < 0){
                                    std::cout << "Invalid code" << '\n';
                                    break;
                                }

                                service.exist(codeProduct);
                                price = service.getPrice(codeProduct);

                                if (price > money[5]) {
                                    std::cout << "Insufficient credit!" << '\n';
                                    break;
                                }

                                if (!coinService.verifyChange(money[5] - price)) {
                                    std::cout << "The change cannot be given!" << '\n';
                                }
                                else {
                                    service.buyProduct(codeProduct);
                                    double change = money[5] - price;
                                    coinService.giveChange(money, change);

                                    if (change) {
                                        std::cout << "Pick up your product and your change!" << '\n'
                                                  << "Have a nice day! :)" << '\n';
                                    } else {
                                        std::cout << "Pick up your product!" << '\n' << " Have a nice day!" << '\n';
                                    }

                                }
                            }

                            catch (ServiceException &err) {
                                std::cout << err << '\n';
                            }
                            catch (CoinServiceException &err) {
                                std::cout << err << '\n';
                            }
                            catch (RepositoryException &err){
                                std::cout << err << '\n';
                            }
                            catch (ValidatorException &err){
                                std::cout << err << '\n';
                            }

                            break;
                        }
                        case 'x': {
                            userShouldRun = false;
                            break;
                        }
                        default: {
                            std::cout << "Invalid option! Try again!" << '\n';
                        }

                    }
                }
                break;
            }
            case 'x': {
                mainShoulRun = false;
                break;
            }
            default: {
                std::cout << "Invalid option! Try again!" << '\n';
            }
                break;
        }
    }
}


