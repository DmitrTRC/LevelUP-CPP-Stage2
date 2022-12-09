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

    String s3 = std::move(s1);
    std::cout << s3 << std::endl;

    String s4(s2);


    std::cout << "s1 length: " << s1.length() << std::endl;

    std::cout << "s3 < s4: " << (s3 < s4) << std::endl;

    std::cout << "s3 > s4: " << (s3 > s4) << std::endl;

    std::cout << "s3 == s4: " << (s3 == s4) << std::endl;

    return 0;
}