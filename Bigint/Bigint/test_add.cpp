// Bigint Test Program
//
// Tests:  int constructor, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main() {
	{

		// VERY INCOMPLETE set of tests.


		//------------------------------------------------------
		// Setup fixture
		Bigint left(0);
		Bigint right(0);
		Bigint result;

		// Test 
		result = left + right;

		// Verify
		assert(left == 0);
		assert(right == 0);
		assert(result == 0);
	}

	{
		//------------------------------------------------------
		// Setup fixture
		Bigint left(1);
		Bigint right(0);
		Bigint result;

		// Test
		result = left + right;

		// Verify
		assert(left == 1);
		assert(right == 0);
		assert(result == 1);
	}
	{
		//------------------------------------------------------
		// Setup fixture
		Bigint left(1);
		Bigint right(1);
		Bigint result;

		// Test
		result = left + right;

		// Verify
		assert(left == 1);
		assert(right == 1);
		assert(result == 2);
	}

	// MY TESTS ********************************************

	{
		//------------------------------------------------------
		// Setup fixture
		Bigint left("1");
		Bigint right("1");
		Bigint result;

		// Test
		result = left + right;

		// Verify
		assert(left == 1);
		assert(right == 1);
		assert(result == 2);
	}

	std::cout << "Done with testing addition." << std::endl;


	//MY TESTS

	//Testing + operator with default, int, char[] constructors.
	//Test uses +, ==, !=, and [] overloaded operators.

	//***TESTING DEFAULT CONSTRUCTOR***

	//DEFAULT + DEFAULT
	//------------------------------------------------------
	{
		Bigint left;
		Bigint right;
		Bigint result;

		// Test
		result = left + right;

		// Verify
		assert(left == 0);
		assert(right == 0);
		assert(result == 0);
	}

	//DEFAULT + INT
	//------------------------------------------------------
	{
		Bigint left;
		Bigint right(5);
		Bigint result;

		// Test
		result = left + right;

		// Verify
		assert(left == 0);
		assert(right == 5);
		assert(result == 5);
	}

	//DEFAULT + CHAR[]
	//------------------------------------------------------
	{
		Bigint left;
		Bigint right("100");
		Bigint result;

		// Test
		result = left + right;

		// Verify
		assert(left == 0);
		assert(right == 100);
		assert(result == 100);
	}

	//***TESTING INT CONSTRUCTOR

	//INT + INT
	//------------------------------------------------------
	{
		Bigint left(1);
		Bigint right(1);
		Bigint result;

		// Test
		result = left + right;

		// Verify
		assert(left == 1);
		assert(right == 1);
		assert(result == 2);
	}

	//INT + INT WITH CARRY
	//------------------------------------------------------
	{
		Bigint left(1);
		Bigint right(9);
		Bigint result;

		// Test
		result = left + right;

		// Verify
		assert(left == 1);
		assert(right == 9);
		assert(result == 10);

		// Testing number carrying
		std::cout << "Int + int with carrying: 1 + 9 = " << result;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "-------------------";
		std::cout << std::endl;
		std::cout << "The tens place is: " << result[1];
		std::cout << std::endl;
		std::cout << "The ones place is: " << result[0];
		std::cout << std::endl;
		std::cout << "-------------------";
		std::cout << std::endl;
		std::cout << std::endl;
	}

	//INT + CHAR[]
	//------------------------------------------------------
	{
		Bigint left(1);
		Bigint right("100");
		Bigint result;

		// Test
		result = left + right;

		// Verify
		assert(left == 1);
		assert(right == 100);
		assert(result == 101);
	}

	//INT + CHAR[] WITH CARRY
	//------------------------------------------------------
	{
		Bigint left(1);
		Bigint right("9");
		Bigint result;

		// Test
		result = left + right;

		// Verify
		assert(left == 1);
		assert(right == 9);
		assert(result == 10);

		//Testing number carrying
		std::cout << "Int + char[] with carrying: 1 + 9 = " << result;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "-------------------";
		std::cout << std::endl;
		std::cout << "The tens place is: " << result[1];
		std::cout << std::endl;
		std::cout << "The ones place is: " << result[0];
		std::cout << std::endl;
		std::cout << "-------------------";
		std::cout << std::endl;
		std::cout << std::endl;
	}

	//***TESTING CHAR[] CONSTRUCTOR

	//Char[] + Char[]
	//------------------------------------------------------
	{
		Bigint left("100");
		Bigint right("100");
		Bigint result;

		// Test
		result = left + right;

		// Verify
		assert(left == 100);
		assert(right == 100);
		assert(result == 200);
	}

	//Char[] + Char[] WITH CARRY
	//------------------------------------------------------
	{
		Bigint left("99");
		Bigint right("11");
		Bigint result;

		// Test
		result = left + right;

		// Verify
		assert(left == 99);
		assert(right == 11);
		assert(result == 110);

		//Testing number carrying
		std::cout << "Char[] + char[] with carrying: 99 + 11 = " << result;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "-------------------";
		std::cout << std::endl;
		std::cout << "The hundreds place is: " << result[2];
		std::cout << std::endl;
		std::cout << "The tens place is:     " << result[1];
		std::cout << std::endl;
		std::cout << "The ones place is:     " << result[0];
		std::cout << std::endl;
		std::cout << "-------------------";
		std::cout << std::endl;
		std::cout << std::endl;
	}
	std::cout << "Done testing the add operator.";
	std::cout << std::endl;
}