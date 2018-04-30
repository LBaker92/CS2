// Bigint Test Program
//
// Tests:  default constructor, uses ==
//
//  
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    // Setup

    // Test 
    Bigint bi;

    // Verify
    assert(bi == 0);
    std::cout << "0 == " << bi << std::endl;

    std::cout << "Done testing default constructor." << std::endl;
}

