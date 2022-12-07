//
// Created by Dmitry Morozov on 20/9/22.
//

#include "String.hpp"

#include <iostream>


int main() {

    String s1;
    String s2("Hello");
    s1 = "Hello";
    s1.append(s2);
    s1.append(" World");
    std::cout << s1 << std::endl;

    return 0;
}