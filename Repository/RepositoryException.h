//
// Created by user on 5/8/2022.
//

#ifndef MAIN_CPP_REPOSITORYEXCEPTION_H
#define MAIN_CPP_REPOSITORYEXCEPTION_H


#include <string>

class RepositoryException {
private:
    std::string err;
public:
    std::string &get_msg() { return this->err; };

    RepositoryException(const std::string &str) : err{str} {};

    friend std::ostream &operator<<(std::ostream &out, RepositoryException &err){
        out << err.get_msg();
        return out;
    }

};


#endif //MAIN_CPP_REPOSITORYEXCEPTION_H
