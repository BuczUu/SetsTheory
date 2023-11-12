//
// Created by ufabi on 11.11.2023.
//

#include "PreprocessInput.h"

PreprocessInput::PreprocessInput() {
    this->second = new Set();
    this->first = new Set();
}

PreprocessInput::PreprocessInput(const std::string &input) {
    this->input = input;
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
    first->setName(removeSpacesCommasBrackets(split('=', input).first));
    second->setName(removeSpacesCommasBrackets(split('=', split('}', input).second).first));

    if (first->getName().empty()) {
        first->setName("A");
    }
    if (second->getName().empty()) {
        second->setName("B");
    }
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

void PreprocessInput::setArrays() {
    std::string firstSet = removeDuplicates(removeSpacesCommasBrackets(split('}', substring('{', '}', input)).first));
    std::string secondSet = removeDuplicates(removeSpacesCommasBrackets(split('=', split('}', input).second).second));

    char *firstArray = new char[firstSet.length()];
    char *secondArray = new char[secondSet.length()];

    for (int i = 0; i < firstSet.length(); ++i) {
        firstArray[i] = firstSet[i];
    }

    first->setSize(firstSet.length());
    first->setElements(firstArray);

    for (int i = 0; i < secondSet.length(); ++i) {
        secondArray[i] = secondSet[i];
    }

    second->setSize(secondSet.length());
    second->setElements(secondArray);
}

std::string PreprocessInput::substring(char begin, char end, std::string str) {
    std::string result;
    int i = 0;
    while (str[i] != begin) {
        i++;
    }
    for (int j = i; j < str.length(); ++j) {
        if (str[i] == end) {
            return result;
        }
        result += str[j];
    }

    return result;
}

std::string PreprocessInput::removeDuplicates(const std::string &str) {
    std::string result;

    for (char letter: str) {
        if (result.find(letter) == std::string::npos) {
            result += letter;
        }
    }

    return result;
}
