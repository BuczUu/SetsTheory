//
// Created by ufabi on 11.11.2023.
//

#ifndef SETSTHEORY_PREPROCESSINPUT_H
#define OFFSET 32
#define SETSTHEORY_PREPROCESSINPUT_H


#include <string>

class PreprocessInput {
private:
    char *input;
    unsigned int size;
    unsigned int amountOfA;
    unsigned int amountOfB;

public:
    PreprocessInput();

    PreprocessInput(char *array, int newSize);

    ~PreprocessInput();

    static std::string removeSpacesCommasBrackets(std::basic_string<char> input, int size);

    static std::string setSmallLetters(const char *input, int size);

    static std::string getNames(char *input, int size);

};


#endif //SETSTHEORY_PREPROCESSINPUT_H
