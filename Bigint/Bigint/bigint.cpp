//Bigint.cpp

#include "Bigint.hpp"
#include <iostream>

Bigint::Bigint()
{
	for (int i = 0; i < MAX_ARRAY_SIZE; ++i)
	{
		memArray[i] = 0;
	}
}

Bigint::Bigint(int userInput)
{
	for (int i = 0; i < MAX_ARRAY_SIZE; ++i)
	{
		memArray[i] = 0;
	}

	for (int i = 0; userInput > 0; ++i)
	{
		memArray[i] = userInput % 10;
		userInput /= 10;
	}
}

Bigint::Bigint(const char userInput[])
{
    //Sets all values of the array to zero.
	for (int i = 0; i < MAX_ARRAY_SIZE; ++i)
	{
		memArray[i] = 0;
	}

	for (int i = 0; i < MAX_ARRAY_SIZE; ++i)
	{
		if (userInput[i + 1] != '\0')
			continue;

		for (int j = i; j >= 0; --j)
		{
			memArray[j] = (userInput[i - j]) - '0';
		}
		break;
	}
}

std::ostream& operator<<(std::ostream &output, Bigint &example)
{
	int linecounter = 0;
	for (int findingzero = MAX_ARRAY_SIZE - 1; findingzero >= 0; --findingzero)
	{
		if (example.memArray[findingzero] == 0 && findingzero != 0)
			continue;

		for (int startPrinting = findingzero; startPrinting >= 0; --startPrinting)
		{
			output << example.memArray[startPrinting];
			linecounter++;
			if (linecounter == 50)
			{
				std::cout << std::endl;
				linecounter = 0;
			}
		}
		break;
	}

	return output;
}

bool operator==(const Bigint &one, const Bigint &two)
{
	for (int i = MAX_ARRAY_SIZE - 1; i >= 0; --i)
	{
		if (one.memArray[i] == two.memArray[i])
			continue;
		else
			return false;
	}
	return true;
}

bool operator!=(const Bigint &one, const Bigint &two)
{
	return !(one == two);
}

std::istream& operator >> (std::istream &in, Bigint &example)
{
	char userInput;
	char tempStream[MAX_ARRAY_SIZE]{};

	int i = 0;
	in >> userInput;

	while (userInput != ';')
	{
		tempStream[i] = userInput;
		in >> userInput;
		++i;
	}
	tempStream[i] = '\0';
	example = Bigint(tempStream);

	return in;
}

Bigint Bigint::operator+(const Bigint &rhs) const
{
	Bigint temp = *this;
	Bigint result;

	for (int i = 0; i < MAX_ARRAY_SIZE; ++i)
	{
		if ((result.memArray[i] + temp.memArray[i] + rhs.memArray[i]) >= 10)
		{
			result.memArray[i] += ((temp.memArray[i] + rhs.memArray[i]) - 10);
			++result.memArray[i + 1];
		}
		else
		{
			result.memArray[i] += (temp.memArray[i] + rhs.memArray[i]);
		}
	}
	return result;
}

Bigint Bigint::timesDigit(int digit) const
{
	Bigint temp;
	for (int i = 0; i < digit; ++i)
	{
		temp = temp + *this;
	}
	return temp;
}

Bigint Bigint::timesTen(int digitTen) const
{
	Bigint temp;
	for (int i = (MAX_ARRAY_SIZE - digitTen) - 1; i >= 0; --i)
	{
		temp.memArray[i + digitTen] = this->memArray[i];
	}
	return temp;
}

Bigint Bigint::operator*(const Bigint& multiplier) const
{
	Bigint temp;
	for (int i = 0; i < MAX_ARRAY_SIZE; ++i)
	{
		temp = temp + Bigint(this->timesDigit(multiplier.memArray[i]).timesTen(i));
	}
	return temp;
}