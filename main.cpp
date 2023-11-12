#include "Interface.h"
#include "Utils/PreprocessInput.h"
#include <iostream>
#include "unit tests/UnitTests.h"

int main() {
//    Interface interface;
//    interface.run();

    // A = {1,2,3,45,5} B = {1,2,3,4,5}
    std::string res = "Aasd={1,2,3,45,5 }Bsad={1,2,3,4,5}";
//    std::string fist, second;
//    fist=PreprocessInput::split('=', res).first;
//    second=PreprocessInput::split('=', res).first;
//    std::cout<<PreprocessInput::removeSpacesCommasBrackets(fist)<<std::endl;
//    std::cout<<PreprocessInput::removeSpacesCommasBrackets(second)<<std::endl;

    PreprocessInput preprocessInput;
    preprocessInput.setInput(res);
    preprocessInput.setNames();

    return 0;
}
