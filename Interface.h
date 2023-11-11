//
// Created by ufabi on 11.11.2023.
//

#ifndef SETSTHEORY_INTERFACE_H
#define CMD_LANE "sets_theory>"
#define HELP_MSG "help/info - print this message\n" \
                 "add - add two sets\n" \
                 "sub - subtract two sets\n" \
                 "mul - multiply two sets\n" \
                 "sets - print all sets\n" \
                 "include - check if set is included in another set\n" \
                 "exit/end - exit program\n"

#define ERROR "Unknown command! Type 'help' for more information.\n"
#define SETSTHEORY_INTERFACE_H


#include "Utils/PreprocessInput.h"
#include "Utils/Scanner.h"
#include "Set.h"

class Interface {
private:
    Scanner *scanner;
//    PreprocessInput *preprocessInput;
    Set *setA;
    Set *setB;
    Set *setResult;

    bool menu(const std::string &lane);

    void add(const std::string &lane);

    void sub(const std::string &lane);

    void mul(const std::string &lane);

    void sets();

    void include(const std::string &lane);

    static void help();

    static void unknownCommand();

public:
    Interface();

    ~Interface();

    void run();

    void enter(const std::string &basicString);
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
