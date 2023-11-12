//
// Created by ufabi on 12.11.2023.
//

#include "UnitTests.h"
#include <iostream>

UnitTests::UnitTests() {
    setA = new Set();
    setB = new Set();
    setResult = new Set();
}

UnitTests::~UnitTests() {
    delete setA;
    delete setB;
    delete setResult;
}

void UnitTests::testsForSummingSets(){
    setA->setSize(3);
    setA->setElements(new char[3]{'a', 'b', 'c'});
    setB->setSize(3);
    setB->setElements(new char[3]{'a', 'b', 'c'});
    *setResult = *setA + *setB;
    assert(setResult->getSize() == 3);
    assert(setResult->getElements()[0] == 'a');
    assert(setResult->getElements()[1] == 'b');
    assert(setResult->getElements()[2] == 'c');

    setA->setSize(3);
    setA->setElements(new char[3]{'a', 'b', 'c'});
    setB->setSize(1);
    setB->setElements(new char[1]{'d'});
    *setResult = *setA + *setB;
    assert(setResult->getSize() == 4);
    assert(setResult->getElements()[0] == 'a');
    assert(setResult->getElements()[1] == 'b');
    assert(setResult->getElements()[2] == 'c');
    assert(setResult->getElements()[3] == 'd');

    setA->setSize(1);
    setA->setElements(new char[2]{'a', 'b'});
    setB->setSize(3);
    setB->setElements(new char[3]{'b', 'a', 't'});
    *setResult = *setA + *setB;
    assert(setResult->getSize() == 3);
    assert(setResult->contains('a') && setResult->contains('b') && setResult->contains('t') == true);

    setA->setSize(-1);
    assert(setA->getSize() == CAPACITY);
}

void UnitTests::testsForSet() {
    testsForSummingSets();
    testForSubtractingSets();
    testForTheCommonPart();
    testForEquality();
}

void UnitTests::testForSubtractingSets() {
    setA->setSize(3);
    setA->setElements(new char[3]{'a', 'b', 'c'});
    setB->setSize(3);
    setB->setElements(new char[3]{'a', 'b', 'c'});
    *setResult = *setA - *setB;
    assert(setResult->getSize() == 0);

    setA->setSize(3);
    setA->setElements(new char[3]{'a', 'b', 'c'});
    setB->setSize(1);
    setB->setElements(new char[1]{'d'});
    *setResult = *setA - *setB;
    assert(setResult->getSize() == 3);
    assert(setResult->getElements()[0] == 'a');
    assert(setResult->getElements()[1] == 'b');
    assert(setResult->getElements()[2] == 'c');

    setA->setSize(1);
    setA->setElements(new char[2]{'a', 'b'});
    setB->setSize(3);
    setB->setElements(new char[3]{'b', 'a', 't'});
    *setResult = *setA - *setB;
    assert(setResult->getSize() == 0);
}

void UnitTests::testForTheCommonPart() {
    setA->setSize(3);
    setA->setElements(new char[3]{'a', 'b', 'c'});
    setB->setSize(3);
    setB->setElements(new char[3]{'a', 'b', 'c'});
    *setResult = *setA * *setB;
    assert(setResult->getSize() == 3);
    assert(setResult->getElements()[0] == 'a');
    assert(setResult->getElements()[1] == 'b');
    assert(setResult->getElements()[2] == 'c');

    setA->setSize(3);
    setA->setElements(new char[3]{'a', 'b', 'c'});
    setB->setSize(1);
    setB->setElements(new char[1]{'d'});
    *setResult = *setA * *setB;
    assert(setResult->getSize() == 0);

    setA->setSize(2);
    setA->setElements(new char[2]{'a', 'b'});
    setB->setSize(3);
    setB->setElements(new char[3]{'b', 'a', 't'});
    *setResult = *setA * *setB;
    assert(setResult->getSize() == 2);
    assert(setResult->contains('a') && setResult->contains('b') == true);
}

void UnitTests::testForEquality() {
    setA->setSize(3);
    setA->setElements(new char[3]{'a', 'b', 'c'});
    setB->setSize(3);
    setB->setElements(new char[3]{'a', 'b', 'c'});
    assert(*setA == *setB == true);

    setA->setSize(3);
    setA->setElements(new char[3]{'a', 'b', 'c'});
    setB->setSize(1);
    setB->setElements(new char[1]{'d'});
    assert(*setA == *setB == false);

    setA->setSize(2);
    setA->setElements(new char[2]{'a', 'b'});
    setB->setSize(3);
    setB->setElements(new char[3]{'b', 'a', 't'});
    assert(*setA == *setB == false);
}
