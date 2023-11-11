//
// Created by ufabi on 11.11.2023.
//

#include "PreprocessInput.h"

PreprocessInput::PreprocessInput() {
//    this->size = newSize;
    this->input = nullptr;
    this->amountOfA = 0;
    this->amountOfB = 0;
}

PreprocessInput::PreprocessInput(char *array, int newSize) {
    this->size = newSize;
    this->input = new char[newSize];
    this->amountOfA = 0;
    this->amountOfB = 0;
}

PreprocessInput::~PreprocessInput() {
    delete input;
}

std::string PreprocessInput::removeSpacesCommasBrackets(std::basic_string<char> input, int size) {
    std::string result;
    for (int i = 0; i < size; i++) {
        if (input[i] != ' ' && input[i] != ',' && input[i] != '{' && input[i] != '}') {
            result += input[i];
        }
    }
    return result;
}

std::string PreprocessInput::getNames(char *input, int size) {
    return std::string();
}

std::string PreprocessInput::setSmallLetters(const char *input, int size) {
    std::string result;
    for (int i = 0; i < size; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            result += input[i] + OFFSET;
        } else {
            result += input[i];
        }
    }

    return result;
}
