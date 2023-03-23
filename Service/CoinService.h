#ifndef LAB910_COINSERVICE_H
#define LAB910_COINSERVICE_H


#include "../Domain/Coin.h"
#include "../Repository/IRepo.h"

class CoinService {
private:
    IRepo<Coin> &repo;
    unsigned int coinCode = 0;
public:
    CoinService(IRepo<Coin> &IRepo);

    ~CoinService() = default;

    void add(double value, unsigned int number);

    std::vector<Coin> read();

    void update(unsigned int code, double value, unsigned int number);

    void remove(unsigned int code);

    bool verifyChange(double change);

/**
 * Adds to a vector the money insert
 * position 0 - the number of 0.1 coins
 * position 1 - the number of 0.5 coins
 * position 2 - the number of 1 lei bacnotes
 * position 3 - the number of 5 lei bacnotes
 * position 4 - the number of 10 lei bacnotes
 * position 5 - the sum introduced
 *
 * @return a vector with int elements
 */
    std::vector<double> insertMoney();

    void giveChange(std::vector<double> &money, double change);
};

    class CoinServiceException {
    private:
        std::string err;
    public:
        CoinServiceException(const std::string& msg) : err{ msg } {};

        std::string& get_msg() { return this->err; };
        friend std::ostream& operator<<(std::ostream& out, CoinServiceException& err);
    };

    std::ostream& operator<<(std::ostream& out, CoinServiceException& err);




#endif //LAB910_COINSERVICE_H
