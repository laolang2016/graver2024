#include <iostream>
#include <memory>

#include "graver/common/common.h"
#include "graver/person/person.h"

int main(int argc, char** argv) {
    UNUSED(argc);
    UNUSED(argv);
    auto person = std::make_unique<Person>(18, "laolang");
    std::cout << "Hello . My name is " << person->name() << " ." << std::endl;
    return 0;
}
