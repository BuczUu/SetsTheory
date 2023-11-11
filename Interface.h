//
// Created by ufabi on 11.11.2023.
//

#ifndef SETSTHEORY_INTERFACE_H
#define SETSTHEORY_INTERFACE_H


#include "Utils/PreprocessInput.h"
#include "Utils/Scanner.h"

class Interface {
private:
    Scanner scanner;
    PreprocessInput preprocessInput;

    void menu();

public:
    Interface();
    ~Interface();

    void run();
};


#endif //SETSTHEORY_INTERFACE_H
