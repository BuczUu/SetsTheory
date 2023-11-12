//
// Created by ufabi on 11.11.2023.
//

#ifndef SETSTHEORY_PREPROCESSINPUT_H
#define OFFSET 32
#define SETSTHEORY_PREPROCESSINPUT_H


#include <string>
#include "../Set.h"

class PreprocessInput {
private:
    std::string input;
    Set *first;
    Set *second;
public:
    PreprocessInput();

    ~PreprocessInput();

    Set *getFirst() const;

    const std::string &getInput() const;

    void setInput(const std::string &input);

    void setFirst(Set *first);

    Set *getSecond() const;

    void setSecond(Set *second);

    static std::string removeSpacesCommasBrackets(const std::string &input);

    static std::string setSmallLetters(const std::string &input);

    static std::pair<std::string, std::string> split(char sign, const std::string &str);

    void setNames();
};


#endif //SETSTHEORY_PREPROCESSINPUT_H
