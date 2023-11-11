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

//new A = {d,a,f,q} B = {a,b,c}
//add
//sub
//mul
//sets // printuje wszystkie zbiory nazwa+'='+{tablica (elementy oddzielone ', ')}
//exit
//help/info
//is zbior1 in zbior2 => bool


#endif //SETSTHEORY_INTERFACE_H
