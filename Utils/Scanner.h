//
// Created by ufabi on 11.11.2023.
//

#include <string>

#ifndef SETSTHEORY_SCANNER_H
#define DEFAULT_SIZE 100
#define SETSTHEORY_SCANNER_H


class Scanner {
private:
    char *input;
    unsigned int size;

public:
    Scanner();

    explicit Scanner(int newSize);

    ~Scanner();

    void readInput();

    char *getInput() const;

    void setInput(char *input);

    unsigned int getSize() const;

    void setSize(unsigned int size);

    void printInput();

    static void printResult(const char *result);

    static void printResult(const std::string &result);
};


#endif //SETSTHEORY_SCANNER_H
