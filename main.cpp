#include "Interface.h"
#include "Utils/PreprocessInput.h"
#include <iostream>

int main() {
//    Interface interface;
//    interface.run();


    std::string res = PreprocessInput::removeSpacesCommasBrackets(PreprocessInput::setSmallLetters("set= {A, B, C}", 10), 10);
    std::cout << res << std::endl;
    return 0;
}
