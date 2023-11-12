//
// Created by ufabi on 11.11.2023.
//

#ifndef SETSTHEORY_SET_H
#define CAPACITY 100
#define SETSTHEORY_SET_H

#include <string>

class Set {
private:
    char *elements;
    int size; // number of elements in the set
    std::string name;

public:

public:
    Set();

    explicit Set(int size);

    Set(const Set &otherSet);

    ~Set();

    char *getElements() const;

    void setElements(char *elements);

    int getSize() const;

    void setSize(int size);

    const std::string &getName() const;

    void setName(const std::string &newName);

    bool contains(char element) const;

    void printElements() const;

    Set operator+(const Set &otherSet) const;

    Set operator-(const Set &otherSet) const;

    Set operator*(const Set &otherSet) const;

    Set &operator=(const Set &otherSet);

    bool operator==(const Set &otherSet) const;

};


#endif //SETSTHEORY_SET_H
