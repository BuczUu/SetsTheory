//
// Created by ufabi on 11.11.2023.
//

#include "Interface.h"
#include "Utils/PreprocessInput.h"

Interface::Interface() {
    this->scanner = new Scanner();
    this->preprocessInput = new PreprocessInput();
    this->setA = nullptr;
    this->setB = nullptr;
    this->setResult = new Set();
    setResult->setName(RESULT_NAME);
}

Interface::~Interface() {
    delete scanner;
    delete preprocessInput;
    delete setA;
    delete setB;
    delete setResult;
}

bool Interface::menu(const std::string &lane) {
    if (lane.substr(0, 4) == "exit" || lane.substr(0, 3) == "end") {
        return true;
    } else if (lane.substr(0, 4) == "help" || lane.substr(0, 4) == "info") {
        help();
    } else if (lane.substr(0, 3) == "add") {
        add(lane);
    } else if (lane.substr(0, 3) == "sub") {
        sub(lane);
    } else if (lane.substr(0, 3) == "mul") {
        mul(lane);
    } else if (lane.substr(0, 4) == "sets" || lane.substr(0, 4) == "list" || lane.substr(0, 4) == "show" ||
               lane.substr(0, 4) == "print") {
        sets();
    } else if (lane.substr(0, 7) == "include") {
        include(lane);
    } else if (lane.substr(0, 5) == "enter") {
        enter(lane);
    } else {
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
    *setResult = *setA + *setB;
    Scanner::printResult(setResult->toStr());
}

void Interface::sub(const std::string &lane) {
    *setResult = *setA - *setB;
    Scanner::printResult(setResult->toStr());
}

void Interface::mul(const std::string &lane) {
    *setResult = *setA * *setB;
    Scanner::printResult(setResult->toStr());
}

void Interface::sets() {
    if (setA == nullptr || setB == nullptr) {
        Scanner::printResult("No sets entered yet!");
    } else {
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

        result += "}";
        Scanner::printResult(result);
    }
}

void Interface::include(const std::string &lane) {
    Scanner::printResult("Not implemented yet!");
}

void Interface::help() {
    Scanner::printResult(HELP_MSG);
}

void Interface::unknownCommand() {
    Scanner::printResult(ERROR);
}

void Interface::enter(const std::string &basicString) {
    if (PreprocessInput::removeSpacesCommasBrackets(basicString.substr(5, basicString.length())).empty()){
        Scanner::printResult("No set name entered!\n");
    }else{
        preprocessInput->setInput(basicString.substr(6, basicString.size() - 6));
        preprocessInput->setNames();
        preprocessInput->setArrays();

        setA = preprocessInput->getFirst();
        setB = preprocessInput->getSecond();
    }

}
