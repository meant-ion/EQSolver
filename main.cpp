#include <iostream>
#include <string>
#include "RPNConverter.hpp"
//Simple program to solve basic algebraic equations, like the ones listed below. 
//5 = x + 1 -> x = 4

int main() {

    std::string equation;

    std::cout << "Enter the equation you want to solve: ";
    getline(std::cin, equation);
    std::cout << std::endl;

    return 0;
}