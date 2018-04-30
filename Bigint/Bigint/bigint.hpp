/*
Project:        Bigint
Description:    A user-defined data structure that allows for math to be done on integers greater than 2^31 − 1.
Author:         Logan Baker
*/
#ifndef BIGINT_HPP
#define BIGINT_HPP
#include <iostream>

constexpr int MAX_ARRAY_SIZE = 500;

class Bigint
{
public:
    //CONSTRUCTORS
    Bigint(); //Initializes a Bigint object with a value of 0.
    Bigint(int N); //Init a Bigint object with an integer value of N.
    Bigint(const char N[]); //Init a Bigint object with size N. N is a char array.

    //FUNCTIONS
    Bigint timesDigit(int num) const;
    Bigint timesTen(int num) const;

    //OPERATOR OVERLOADS
    Bigint operator+ (const Bigint &rhs) const; //Adds two Bigint objects together.
    Bigint operator* (const Bigint& rhs) const; //Multiplies two Bigint objects together.
    int& operator[] (const int index) { return memArray[index]; } //Overloading subscript operator to return the index of the memArray inside Bigint objects.
    friend std::ostream& operator<<(std::ostream &os, Bigint &num); //Overloading output operator to use Bigints in output stream.
    friend std::istream& operator >> (std::istream &is, Bigint &num); //Overloading input operator to use Bigints in input stream.
    friend bool operator== (const Bigint &LHS, const Bigint &RHS); //Overloading == operator to compare two Bigints.
    friend bool operator!= (const Bigint &LHS, const Bigint &RHS); //Overloading != operator to compare two Bigints.

private:
    int memArray[MAX_ARRAY_SIZE];
};

#endif BIGINT_HPP