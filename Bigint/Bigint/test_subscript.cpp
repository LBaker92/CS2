// Bigint Test Program
//
// Tests:  subscript, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
	
	{
		// Setup
		Bigint bi(4);

		// Test 
		int digit = bi[0];

		// Verify
		assert(bi    == 4);
		assert(digit == 4);
	}
	
	//Add test cases!!

	{
		// Setup
		Bigint bi;

		// Test 
		int digit = bi[0];

		// Verify
		assert(bi == 0);  
		assert(digit == 0);
	}

	{
		// Setup
		Bigint bi("100");

		// Test 
		int hunPlace = bi[2];
		int tenPlace = bi[1];
		int onePlace = bi[0];

		// Verify
		assert(bi == 100); 
		assert(hunPlace == 1);
		assert(tenPlace == 0);
		assert(onePlace == 0);
	}

	{
		// Setup
		Bigint bi(100);

		// Test 
		int hunPlace = bi[2];
		int tenPlace = bi[1];
		int onePlace = bi[0];

		// Verify
		assert(bi == 100);  
		assert(hunPlace == 1);
		assert(tenPlace == 0);
		assert(onePlace == 0);
	}

	std::cout << "Done testing subscript." << std::endl;
}

