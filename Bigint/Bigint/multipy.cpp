#include <iostream>
#include <fstream>
#include "bigint.hpp"

int main()
{
	std::ifstream file("data1-2.txt");

	if (!file.is_open())
	{
		std::cout << "There was an error opening your file.";
		return 1;
	}

	bigint bi;
	bigint bi2;
	file >> bi;
	while (!file.eof())
	{
		file >> bi2;
		std::cout << "PRINTED NUMBERS:\n" << bi;
		std::cout << " " << bi2 << "\n\n";
		std::cout << "ARITHMATIC:\n" << bi << "\n*\n" << bi2 << "\n\nRESULT:\n" << bi * bi2;
		std::cout << std::endl;
		std::cout << "--------------------------------------------------------------------------------";
		std::cout << std::endl;
		file >> bi;
	}
	file.close();
	std::cout << "END OF FILE.";
	return 0;
}