#include <vector>
#include "Product.h"


Product::Product() {
    this->code = 0;
    this->name = "";
    this->price = 0;
    this->stock = 0;

}

Product::Product(unsigned int code, std::string name, double price, unsigned int stock) {
    this->code = code;
    this->name = name;
    this->price = price;
    this->stock = stock;

}

Product::Product(const Product &product) {
    this->code = product.code;
    this->name = product.name;
    this->price = product.price;
    this->stock = product.stock;
}
Product::Product(std::string stringProduct, char separator) {

 std::vector<std::string> entities;
    std::stringstream ss (stringProduct);
    std::string object;
    while (getline (ss, object, separator)) {
        entities.push_back(object);
    }
    if(entities.size() == 4) {
        std::stringstream c(entities[0]);
        c >> this->code;
        this->name = entities[1];
        std::stringstream p(entities[2]);
        p >> this->price;
        std::stringstream s(entities[3]);
        s >> this->stock;
    }

}


Product::~Product() = default;

std::string Product::getName() {
    return this->name;
}

void Product::setName(std::string newName) {
    this->name = newName;
}

double Product::getPrice() {
    return this->price;
}

void Product::setPrice(double newPrice) {
    this->price = newPrice;
}

unsigned int Product::getCode() {
    return this->code;
}

void Product::setCode(unsigned int code) {
    this->code = code;

}
unsigned int Product::getStock() {
    return this->stock;
}

void Product::setStock(unsigned int stock) {
    this->stock = stock;

}


std::ostream &operator<<(std::ostream &os, const Product &product) {
    os << "Product{ " << '\n' <<"Code :" << product.code << '\n' << "Name: " << product.name << '\n' <<
    "Price: " << product.price << '\n' << "Stock: "<< product.stock << '\n'
    <<'}' << '\n';
    return os;
}

std::string Product::delimitate(char delimitator) {
    return std::to_string(this->code) + delimitator + this->name + delimitator + std::to_string(this->price) +
    delimitator + std::to_string(this->stock);
}


