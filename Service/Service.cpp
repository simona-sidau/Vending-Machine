//
// Created by user on 4/26/2022.
//

#include "Service.h"
#include "../Domain/Validator.h"
#include "../Repository/RepositoryException.h"


Service::Service(IRepo<Product> &Irepo) : repository(Irepo) {}


void Service::add(unsigned int code, std::string name, double price, unsigned int stock) {
    if (!Validator::validateName(name)) {
        throw ValidatorException("Invalid name!");
    }
    if (!Validator::validateCode(code)) {
        throw ValidatorException("Invalid code!");
    }
    if (!Validator::validatePrice(price)) {
        throw ValidatorException("Invalid price!");
    }
    if (!Validator::valdidateStock(stock)) {
        throw ValidatorException("Invalid stock!");
    }
    Product product(code, name, price, stock);
    repository.add(product);
}

std::vector<Product> Service::read() {
    return repository.getAll();
}

void Service::update(unsigned int code, std::string name, double price, unsigned int stock) {
    if (!Validator::validateName(name)) {
        throw ValidatorException("Invalid name!");
    }
    if (!Validator::validatePrice(price)) {
        throw ValidatorException("Invalid price!");
    }
    if (!Validator::validateCode(code)) {
        throw ValidatorException("Invalid code!");
    }
    if (!Validator::valdidateStock(stock)) {
        throw ValidatorException("Invalid stock!");
    }
    Product product(code, name, price, stock);
    repository.update(code, product);

}

void Service::remove(unsigned int code) {

    if (!Validator::validateCode(code))
        throw ValidatorException("The product does not exist!");
    repository.remove(code);
}

Product Service::getProduct(unsigned int code) {
    return repository.getEntity(code);
}

void Service::buyProduct(unsigned int code) {
    Product product = this->getProduct(code);
    if (product.getStock() == 0) {
        throw ValidatorException("Insufficient stock!");

    }

    this->update(code, product.getName(), product.getPrice(), product.getStock() - 1);


}

double Service::getPrice(unsigned int code) {
        return this->getProduct(code).getPrice();

}

void Service::exist(unsigned int code) {
        if (!repository.exist(code)) {
            throw ValidatorException("Invalid code!");
        }
}

std::ostream &operator<<(std::ostream &out, ServiceException &err) {
    out << err.get_msg();
    return out;
}