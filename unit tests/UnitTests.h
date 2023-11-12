//
// Created by ufabi on 12.11.2023.
//

#ifndef SETSTHEORY_UNITTESTS_H
#define SETSTHEORY_UNITTESTS_H
#include <cassert>
#include "../Set.h"

class UnitTests {
private:
    Set *setA;
    Set *setB;
    Set *setResult;

    void testsForSummingSets();

    void testForSubtractingSets();

    void testForTheCommonPart();

    void testForEquality();

public:
    UnitTests();
    ~UnitTests();

    void testsForSet();
};


#endif //SETSTHEORY_UNITTESTS_H
