//
// Created by ufabi on 11.11.2023.
//

#include "Interface.h"

Interface::Interface() {
    this->scanner = new Scanner();
//    this->preprocessInput = new PreprocessInput();
    this->setA = new Set();
    this->setB = new Set();
    this->setResult = new Set();
}

Interface::~Interface() {
    delete scanner;
//    delete preprocessInput;
    delete setA;
    delete setB;
    delete setResult;
}

bool Interface::menu(const std::string &lane) {
    if (lane.substr(0, 4) == "exit" || lane.substr(0, 3) == "end"){
        return true;
    }else if (lane.substr(0, 4) == "help" || lane.substr(0, 4) == "info") {
        help();
    }else if (lane.substr(0, 3) == "add") {
        add(lane);
    } else if (lane.substr(0, 3) == "sub") {
        sub(lane);
    } else if (lane.substr(0, 3) == "mul") {
        mul(lane);
    } else if (lane.substr(0, 4) == "sets") {
        sets();
    } else if (lane.substr(0, 7) == "include") {
        include(lane);
    } else if (lane.substr(0, 5) == "enter") {
        enter(lane);
    }else {
        unknownCommand();
    }
    return false;
}

void Interface::run() {
    bool isRunning = false;
    while (!isRunning) {
        Scanner::printResult(CMD_LANE);
        scanner->readInput();
        isRunning = menu(scanner->getInput());
    }
}

void Interface::add(const std::string &lane) {

}

void Interface::sub(const std::string &lane) {

}

void Interface::mul(const std::string &lane) {

}

void Interface::sets() {
    std::string result = setA->getName() + "= {";

    for (int i = 0; i < setA->getSize(); ++i) {
        result += setA->getElements()[i];
        if (i != setA->getSize() - 1) {
            result += ", ";
        }
    }

    result += "} " + setB->getName() + "= {";

    for (int i = 0; i < setB->getSize(); ++i) {
        result += setB->getElements()[i];
        if (i != setB->getSize() - 1) {
            result += ", ";
        }
    }
}

void Interface::include(const std::string &lane) {

}

void Interface::help() {
    Scanner::printResult(HELP_MSG);
}

void Interface::unknownCommand() {
    Scanner::printResult(ERROR);
}

void Interface::enter(const std::string &basicString) {
//    std::string lane = removeWhiteSpaces(basicString);
}
