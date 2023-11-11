//
// Created by ufabi on 11.11.2023.
//

#include "Set.h"

#include <utility>

Set::Set() {
    this->size = CAPACITY;
    this->elements = new char[size];
}

Set::Set(int size, const std::string &newName) {
    this->size = size;
    this->elements = new char[size];
    this->name = newName;
}

Set::Set(const Set &otherSet) {
    delete[] elements;
    this->name = otherSet.name + "_copied";
    this->size = otherSet.getSize();
    this->elements = new char[this->size];
    for (int i = 0; i < this->size; ++i) {
        this->elements[i] = otherSet.getElements()[i];
    }
}

Set::~Set() {
    delete[] elements;
}

char *Set::getElements() const {
    return elements;
}

void Set::setElements(char *newElements) {
    this->elements = newElements;
}

unsigned int Set::getSize() const {
    return size;
}

void Set::setSize(unsigned int newSize) {
    this->size = newSize;
}

const std::string &Set::getName() const {
    return name;
}

void Set::setName(const std::string &newName) {
    this->name = newName;
}

Set Set::operator+(const Set &otherSet) const {
    // todo : create add operator for sets
    return {};
}

Set Set::operator-(const Set &otherSet) const {
    // todo : create subtract operator for sets
    return {};
}

Set Set::operator*(const Set &otherSet) const {
    // todo : create multiply operator for sets
    return {};
}

Set &Set::operator=(const Set &otherSet) {
    if (this == &otherSet) {
        return *this;
    }

    delete[] elements;
    this->name = otherSet.name;
    this->size = otherSet.getSize();
    this->elements = new char[this->size];
    for (int i = 0; i < this->size; ++i) {
        this->elements[i] = otherSet.getElements()[i];
    }

    return *this;
}