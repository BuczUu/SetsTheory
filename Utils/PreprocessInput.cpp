//
// Created by ufabi on 11.11.2023.
//

#include "PreprocessInput.h"
#include <iostream>

PreprocessInput::PreprocessInput() {
    this->second = new Set();
    this->first = new Set();
}

PreprocessInput::~PreprocessInput() {
    delete first;
    delete second;
}

std::string PreprocessInput::removeSpacesCommasBrackets(const std::string &input) {
    std::string result;
    for (char letter: input) {
        if (letter != ' ' && letter != ',' && letter != '{' && letter != '}') {
            result += letter;
        }
    }
    return result;
}

void PreprocessInput::setNames() {
    first->setName(split('=', input).first);
    second->setName(split('=',split('}', input).second).first);

    if (first->getName().empty()) {
        first->setName("A");
    }
    if (second->getName().empty()) {
        second->setName("B");
    }

    std::cout<<first->getName()<<std::endl;
    std::cout<<second->getName()<<std::endl;
}

std::string PreprocessInput::setSmallLetters(const std::string &input) {
    std::string result;
    for (char letter: input) {
        if (letter >= 'A' && letter <= 'Z') {
            result += std::to_string(letter + OFFSET);
        } else {
            result += letter;
        }
    }

    return result;
}

std::pair<std::string, std::string> PreprocessInput::split(char sign, const std::string &str) {
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == sign) {
            return std::make_pair(str.substr(0, i), str.substr(i + 1, str.length()));
        }
    }
    return std::make_pair(str, "");
}

Set *PreprocessInput::getFirst() const {
    return first;
}

void PreprocessInput::setFirst(Set *other) {
    this->first = other;
}

Set *PreprocessInput::getSecond() const {
    return second;
}

void PreprocessInput::setSecond(Set *other) {
    this->second = other;
}

const std::string &PreprocessInput::getInput() const {
    return input;
}

void PreprocessInput::setInput(const std::string &newInput) {
    this->input = newInput;
}
