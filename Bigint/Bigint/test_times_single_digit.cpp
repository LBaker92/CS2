// Bigint Test Program
//
// Tests:  times_10, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        Bigint bi(3);

        // Test 
        bi = bi.timesDigit(1);  //Or whatever you call it.

        // Verify
        assert(bi == 12);  //Will FAIL, fix and add test cases.
    }


    //Add test cases as needed.
    
    std::cout << "Done testing Bigint * single digit" << std::endl;
}
