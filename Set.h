//
// Created by ufabi on 11.11.2023.
//

#ifndef SETSTHEORY_SET_H
#define CAPACITY 100
#define SETSTHEORY_SET_H


class Set {
private:
    char *elements;
    unsigned int size; // number of elements in the set
public:
    Set();

    explicit Set(int size);

    Set(const Set &otherSet);

    ~Set();

    char *getElements() const;

    void setElements(char *elements);

    unsigned int getSize() const;

    void setSize(unsigned int size);

    Set operator+(const Set &otherSet) const;

    Set operator-(const Set &otherSet) const;

    Set operator*(const Set &otherSet) const;

};


#endif //SETSTHEORY_SET_H
