#pragma once
#include <iostream>
struct NodeList {
    std::string packageName;
    std::string node;
    std::string on_value;
    std::string off_value;
} __attribute__((aligned(128)));
