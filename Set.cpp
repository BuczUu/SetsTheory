//
// Created by ufabi on 11.11.2023.
//

#include <iostream>
#include "Set.h"
#include <algorithm>

Set::Set() {
    this->size = CAPACITY;
    this->elements = new char[size];
}

Set::Set(int size) {
    if (size < 0) {
        std::cout << "Size cannot be negative, your size has been changed on " << CAPACITY << std::endl;
        size = CAPACITY;
    }
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
    if (newSize < 0) {
        std::cout << "Size cannot be negative, your size has been changed on " << CAPACITY << std::endl;
        newSize = CAPACITY;
    }
    this->size = newSize;
}

void Set::printElements() const {
    for (int i = 0; i < this->size; ++i) {
        std::cout << this->elements[i] << " ";
    }
    std::cout << std::endl;
}

std::string Set::toStr() const {
    std::string result = getName() + " = " + "{";
    for (int i = 0; i < this->size; ++i) {
        result += this->elements[i];
        if (i != this->size - 1) {
            result += ", ";
        }
    }
    result += "}";
    return result;
}

bool Set::contains(char element) const {
    return std::find(this->elements, this->elements + this->size, element) != this->elements + this->size;
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

const std::string &Set::getName() const {
    return name;
}

void Set::setName(const std::string &newName) {
    this->name = newName;
}

bool Set::operator==(const Set &otherSet) const {
    if (this->size != otherSet.getSize()) {
        return false;
    }

    if (this->size == 0 && otherSet.getSize() == 0) {
        return true;
    }

    if (this->size == otherSet.getSize()) {
        for (int i = 0; i < size; ++i) {
            if (!otherSet.contains(this->elements[i])) {
                return false;
            }
        }
    }
    return true;
}
