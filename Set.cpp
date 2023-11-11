//
// Created by ufabi on 11.11.2023.
//

#include <iostream>
#include "Set.h"

Set::Set() {
    this->size = CAPACITY;
    this->elements = new char[size];
}

Set::Set(int size) {
    this->size = size;
    this->elements = new char[size];
}

Set::Set(const Set &otherSet) {
    delete[] elements;
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

int Set::getSize() const {
    return size;
}

void Set::setSize(int newSize) {
    this->size = newSize;
}

void Set::printElements() const {
    for (int i = 0; i < this->size; ++i) {
        std::cout << this->elements[i] << " ";
    }
    std::cout << std::endl;
}

bool Set::contains(char element) const {
    for (int i = 0; i < this->size; ++i) {
        if (this->elements[i] == element) {
            return true;
        }
    }

    return false;
}

Set Set::operator+(const Set &otherSet) const {
    Set result;
    result.setSize(this->size + otherSet.getSize());
    for (int i = 0; i < this->size; ++i) {
        result.getElements()[i] = this->elements[i];
    }
    int j = this->size;
    for (int i = 0; i < otherSet.getSize(); ++i) {
        if (!contains(otherSet.getElements()[i])) {
            result.getElements()[j++] = otherSet.getElements()[i];
        }
    }
    result.setSize(j);
    return result;
}

Set Set::operator-(const Set &otherSet) const {
    Set result;
    result.setSize(this->size);
    result.setElements(new char[result.getSize()]);
    int j = 0;
    for (int i = 0; i < this->size; ++i) {
        if (!otherSet.contains(this->elements[i])) {
            result.getElements()[j++] = this->elements[i];
        }
    }
    result.setSize(j);
    return result;
}

Set Set::operator*(const Set &otherSet) const {
    Set result(std::min(this->size, otherSet.getSize()));
    int j = 0;
    for (int i = 0; i < this->size; ++i) {
        if (otherSet.contains(this->elements[i])) {
            result.getElements()[j++] = this->elements[i];
        }
    }
    result.setSize(j);
    return result;
}

Set &Set::operator=(const Set &otherSet) {
    if (this == &otherSet) {
        return *this;
    }

    delete[] elements;
    this->size = otherSet.getSize();
    this->elements = new char[this->size];
    for (int i = 0; i < this->size; ++i) {
        this->elements[i] = otherSet.getElements()[i];
    }

    return *this;
}
