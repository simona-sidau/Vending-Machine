#ifndef LAB910_REPOINFILE_H
#define LAB910_REPOINFILE_H

#include "IRepo.h"
#include <fstream>
#include "RepositoryException.h"
//#include <vector>


template<class T>
class RepoInFile : public IRepo<T> {
private:
    std::vector<T> entities;
    std::string fileName;


public:
    /**
     * Constructor
     * @param name - file name
     */
    RepoInFile(std::string name) {
        this->fileName = name;
        this->loadFromFile();
    }

    /**
     * Destructor
     */
    ~RepoInFile() = default;

/**
 * Add an entity
 * @param entity - the object to be added
 */
    virtual void add(T entity) override {
        if (!exist(entity.getCode())) {
            this->entities.push_back(entity);
            this->saveToFile();
        } else {
            throw RepositoryException("There already exist an entity with the given code!");
        }
    }

/**
 * Construct a vector which contains all entities
 * @return - a vector
 */
    virtual std::vector<T> getAll() override {
        return this->entities;
    };

/**
 * Modify an entity
 * @param code - unsigned int
 * @param entity - Product Entity
 */
    virtual void update(unsigned int code, T entity) override {
        if (exist(code)) {
            for (int i = 0; i < entities.size(); i++) {
                if (entities[i].getCode() == code) {
                    entities[i] = entity;
                    entities[i].setCode(code);
                }
            }
            this->saveToFile();
        } else {
            throw RepositoryException("The entity does not exist!");
        }
    }

/**
 * Remove an entity from the repository
 * @param code
 */
    virtual void remove(unsigned int code) override {
        if (exist(code)) {
            for (int i = 0; i < entities.size(); i++) {
                if (entities[i].getCode() == code) {
                    entities.erase(entities.begin() + i);
                    this->saveToFile();
                    i = entities.size();
                }
            }
            this->saveToFile();
        } else {
            throw RepositoryException("The entity does not exist!");
        }

    }

/**
 * Save the entities into a .txt file
 */
    void saveToFile() {
        std::ofstream file(this->fileName);
        for (T object: this->entities) {
            file << object.delimitate(' ') << '\n';
        }
        file.close();
    }

/**
 * Convert the entities from the .txt file into a vector
 */
    void loadFromFile() {
        std::string element;
        std::ifstream file(this->fileName);
        while (std::getline(file, element)) {
            T object(element, ' ');
            this->entities.push_back(object);
        }
    }

/**
 * Gets an entity by a given code
 * @param code - unsigned int
 * @return
 */
    T getEntity(unsigned int code) {
        if (exist(code))
            for (int i = 0; i < entities.size(); i++) {
                if (entities[i].getCode() == code) {
                    return entities[i];
                }
            }
        else {
            throw RepositoryException("The entity does not exist!");
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


#endif //LAB910_REPOINFILE_H
