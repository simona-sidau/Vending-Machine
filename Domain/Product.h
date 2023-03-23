#ifndef LAB9_10_PRODUCT_H
#define LAB9_10_PRODUCT_H

#include <string>
#include <ostream>
#include <sstream>

class Product{
private:
    unsigned int code;
    std::string name;
    double price;
    unsigned int stock;
public:
    /**
     * Constructor
     */
    Product();
    /**
     * Constructor with parameters
     * @param code - entity's code - unsigned int
     * @param name - entity's name - string
     * @param price - entity's price - float
     */
    Product(unsigned int code, std::string name, double price, unsigned int stock);

    /**
     * Copy constructor
     * @param product - a Product Entity
     *
     */
    Product(const Product &product);

    Product(std::string stringProduct, char separator);

    /**
     * Destructor
     */
    ~Product();

    /**
     * Gets the name of the entity
     * @return - the entity's name
     */
    std::string getName();
    /**
     * Sets a new name for the entity
     * @param newName
     */
    void setName(std::string newName);

    /**
     * Gets the entity's price
     * @return - the price of entity
     */
    double getPrice();

    /**
     * Sets a new price for an entity
     * @param newPrice - float
     */
    void setPrice(double newPrice);

    /**
     * Gets the code of a product
     * @return - the product's code
     */
    unsigned int getCode();

    /**
     * Sets a new code for a product
     * @param code - new code for entity
     */
    void setCode(unsigned int code);
    /**
     * sets a new stock for a product
     * @param stock - unsigned int
     */
    void setStock(unsigned int stock);
    /**
     * Gets the stock of a product
     * @return - unsigned int
     */
    unsigned int getStock();

    std::string delimitate(char delimitator);

    friend std::ostream &operator<<(std::ostream &os, const Product &product);
};
#endif //LAB9_10_PRODUCT_H
