//
// Created by ufabi on 11.11.2023.
//

#include <string>

#ifndef SETSTHEORY_SET_H
#define CAPACITY 100
#define DEFAULT_NAME "Default Set"
#define SETSTHEORY_SET_H


class Set {
private:
    char *elements;
    unsigned int size; // number of elements in the set
    std::string name;
public:
    Set();

    explicit Set(int size, const std::string& newName);

    Set(const Set &otherSet);

    ~Set();

    char *getElements() const;

    void setElements(char *elements);

    unsigned int getSize() const;

    void setSize(unsigned int size);

    const std::string &getName() const;

    void setName(const std::string &name);

    Set operator+(const Set &otherSet) const;

    Set operator-(const Set &otherSet) const;

    Set operator*(const Set &otherSet) const;

    Set &operator=(const Set &otherSet);
};


#endif //SETSTHEORY_SET_H
