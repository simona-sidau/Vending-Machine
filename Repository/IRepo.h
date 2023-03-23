#ifndef LAB910_IREPO_H
#define LAB910_IREPO_H

#include<vector>


template<class T> class IRepo{
public:
    virtual void add(T Entity) = 0;

    virtual std::vector<T> getAll() = 0;

    virtual void update(unsigned  int code, T Entity) = 0;

    virtual void remove(unsigned int code) = 0;

    virtual T getEntity(unsigned int code) = 0;

    virtual bool exist(unsigned int code) = 0;

};

#endif //LAB910_IREPO_H
