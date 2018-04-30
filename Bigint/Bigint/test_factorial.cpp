#include "bigint.hpp"
#include <iostream>

int main()
{
	Bigint bi(6);

	std::cout << bi << " factorial = " << !bi;
	std::cout << std::endl;

	Bigint bi2("100");

	std::cout << bi2 << " factorial = " << !bi2;
	std::cout << std::endl;

	Bigint bi3;

	std::cout << bi3 << " factorial = " << !bi3;
	std::cout << std::endl;

return 0;
}
