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

    explicit PreprocessInput(const std::string &input);

    ~PreprocessInput();

    Set *getFirst() const;

    const std::string &getInput() const;

    void setInput(const std::string &input);

    void setFirst(Set *first);

    Set *getSecond() const;

    void setSecond(Set *second);

    static std::string removeSpacesCommasBrackets(const std::string &input);

    static std::pair<std::string, std::string> split(char sign, const std::string &str);

    void setNames();

    void setArrays();

    static std::string substring(char begin, char end, std::string str);

    static std::string removeDuplicates(const std::string &str);
};


#endif //SETSTHEORY_PREPROCESSINPUT_H
