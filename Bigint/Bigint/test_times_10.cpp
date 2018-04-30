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
        bi = bi.timesTen(0); //Or whatever you call it.

        // Verify
        assert(bi == 77);  //Wrong. Will FAIL, fix and add tests cases
    }
    
    //Add test cases as needed.

    std::cout << "Done testing times10" << std::endl;
}

