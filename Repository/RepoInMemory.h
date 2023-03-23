#ifndef LAB910_REPOINMEMORY_H
#define LAB910_REPOINMEMORY_H


#include "../Domain/Product.h"
#include "IRepo.h"
#include "RepositoryException.h"

template<class T>
class RepoInMemory : public IRepo<T> {
private:
    std::vector<T> entities;


public:
    RepoInMemory() = default;

    ~RepoInMemory() = default;

/**
 * Add an entity
 * @param entity - Product entity
 */
    void add(T entity) override {
        //if (exist(entity.getCode()) {
        this->entities.push_back(entity);
        /*   } else {
               throw this->RepositoryException("The entity does not exist!");
           }*/
    }

/**
 * Construct a vector which contains all the entities
 * @return - a vector
 */
    std::vector<T> getAll() override {
        return entities;
    }

/**
 * Update an entity
 * @param code - unsigned int
 * @param entity - Product Entity
 */
    void update(unsigned int code, T entity) override {

        for (int i = 0; i < entities.size(); i++) {
            if (entities[i].getCode() == code) {
                entities[i] = entity;
                entities[i].setCode(code);
            }
        }
    }

/**
 * Remove an entity from the repository with a given code
 * @param code
 */
    void remove(unsigned int code) {
        for (int i = 0; i < entities.size(); i++) {
            if (entities[i].getCode() == code) {
                entities.erase(entities.begin() + i);
                i = entities.size();
            }
        }
    }


    T getEntity(unsigned int code) {
        for (int i = 0; i < entities.size(); i++) {
            if (entities[i].getCode() == code) {
                return entities[i];
            }
        }
    }

    bool exist(unsigned int code) {
        for (int i = 0; i < entities.size(); i++) {
            if (entities[i].getCode() == code)
                return true;
        }
        return false;
    }
};

#endif //LAB910_REPOINMEMORY_H
