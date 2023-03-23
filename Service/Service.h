//
// Created by user on 4/26/2022.
//

#ifndef LAB910_SERVICE_H
#define LAB910_SERVICE_H


#include "../Domain/Product.h"
#include "../Repository/IRepo.h"

class Service {
private:
    IRepo<Product> &repository;
public:
    explicit Service(IRepo<Product> &Irepo);
    ~Service() = default;
/**
 * Construct an entity and add it o repository
 * @param code - unsigned int
 * @param name - string
 * @param price - double
 */
    void add(unsigned int code, std::string name, double price, unsigned int stock);
/**
 * Get all the entities
 * @return - a vector which contains all the entities
 */
    std::vector<Product> read();
/**
 * Update an existing entity
 * @param code - unsigned int
 * @param name - string
 * @param price - double
 */
    void update(unsigned int code, std::string name, double price, unsigned int stock);
/**
 * Remove an entity with an given code
 * @param code
 */
    void remove(unsigned int code);

    Product getProduct(unsigned int code);

    void buyProduct(unsigned int code);

    double getPrice(unsigned int code);

    void exist(unsigned int code);
};

class ServiceException {
private:
    std::string err;
public:
    ServiceException(const std::string& msg) : err{ msg } {};

    std::string& get_msg() { return this->err; };
    friend std::ostream& operator<<(std::ostream& out, ServiceException& err);
};

std::ostream& operator<<(std::ostream& out, ServiceException& err);


#endif //LAB910_SERVICE_H
