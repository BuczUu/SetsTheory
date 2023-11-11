#include <iostream>
#include "Set.h"

int main() {
    Set a;
    a.setSize(3);
    a.setElements(new char[3]{'1','2','3'});
    Set b;
    b.setSize(2);
    b.setElements(new char[2]{'2','3'});

    Set c;
    c = a * b + a;
    c.printElements();
    std::cout<<c.getSize();
    //Set d = a.operator-(b);

    //c.printElements();
    //d.printElements();
    return 0;
}
