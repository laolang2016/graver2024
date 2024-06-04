#include <iostream>

#include "doctest/doctest.h"

TEST_SUITE("test_common") {
    TEST_CASE("test_common_one") {
        std::cout << "test_common_one start" << std::endl;
        std::cout << "test_common_one end" << std::endl;
    }
}