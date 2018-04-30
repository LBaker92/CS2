/*
INCOMPLETE TESTING OF BIGINT
*/

#include "bigint.hpp"
#include <iostream>

int main()
{
    {
        Bigint test("30");
        std::cout << test;
        std::cout << std::endl;
    }
    {
        Bigint test = 10;
        std::cout << test;
        std::cout << std::endl;
    }
    {
        Bigint LHS = 10;
        Bigint RHS = 20;
        Bigint result = LHS + RHS;
        std::cout << result;
        std::cout << std::endl;
    }
}