//
// Created by ufabi on 11.11.2023.
//

#include "Scanner.h"
#include <iostream>

Scanner::Scanner() {
    this->size = DEFAULT_SIZE;
    this->input = new char[size];
}

Scanner::Scanner(int newSize) {
    this->size = newSize;
    this->input = new char[this->size];
}

Scanner::~Scanner() {
    delete[] input;
}

void Scanner::readInput() {
    std::cin.getline(this->input, this->size);
}

char *Scanner::getInput() const {
    return input;
}

void Scanner::setInput(char *newInput) {
    this->input = newInput;
}

unsigned int Scanner::getSize() const {
    return size;
}

void Scanner::setSize(unsigned int newSize) {
    this->size = newSize;
}

void Scanner::printInput() {
    std::cout << this->input << std::endl;
}

void Scanner::printResult(const char *result) {
    // todo : print result
}

void Scanner::printResult(const std::string &result) {
    // todo : print result
}
