/*
Project:        Stack
Description:    Functional model of the C++ Standard Library Stack Data Structure.
Author:         Logan Baker
*/

#ifndef STACK_HPP
#define STACK_HPP
#include "Node.hpp"
#include <iostream>
#include <memory>

template <typename T>
class Stack
{
public:
    //Default Constructor
	Stack() : tos(0) {}; //Init top of stack to NULL.

    //Deconstructor
	~Stack();

    //Copy constructor
	Stack(const Stack<T> &RHS);

    /*
    Assignment operator overload.
    //EX:   Stack<int> testStack1, testStack2;
            testStack2 = testStack1;
    */
	Stack<T>& operator= (Stack<T> RHS);

    //Swaps the values of two stack objects.
    void swap(Stack<T> &RHS);

    //Adds a value to the stack object.
	void push(const T&);

    //Removes a value from the stack object.
	T pop();

    //Checks if the Stack is full (uses Memory library).
	bool isFull() const;

    //Checks if the stack is empty.
	bool isEmpty() const { return tos == 0; };

    //Gets the amount of items on the stack.
	int size();
private:
	node<T> *tos;
};

template<typename T>
Stack<T>::~Stack()
{
	while (tos != 0) //While there are still items in the stack.
	{
		node<T> *temp; //Pointer to a node.
		temp = tos; //Sets node to the top of the stack.
		tos->next; //Top of stack points to next, which points to the next node.
		delete temp; //Cleaning up the temp node we made.
	}
}

template <typename T>
Stack<T>::Stack(const Stack<T>& actual)
{
	node<T> *temp = actual.tos, *bottom = 0;
	tos = 0;
	while (temp != 0) //While there are still items on actual's stack.
	{
		if (tos == 0) //If there's nothing on the new stack.
		{
			tos = new node<T>(temp->data); 
			bottom = tos;
		}
		else //Add the item below the TOS.
		{
			bottom->next = new node<T>(temp->data);
			bottom = bottom->next;
		}
		temp = temp->next;
	}
}

template <typename T>
void Stack<T>::swap(Stack<T> &rhs)
{
	node<T> *temp = tos;
	tos = rhs.tos;
	rhs.tos = temp;
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack<T> rhs)
{
	swap(rhs);
	return *this;
}

template <typename T>
void Stack<T>::push(const T& x)
{
	if (!isFull())
	{
		node<T> *temp = new node<T>(x); //Create a new dynamic node called x.
		temp->next = tos; //Next is assigned to the top of the stack.
		tos = temp; //Top of stack becomes the temp node.
	}
}

template <typename T>
T Stack<T>::pop()
{
	if (isEmpty()) //If the stack is empty, go into this statement.
	{
		std::cout << "Stack is empty, cannot pop." << std::endl;
		exit(0);
	}
	T result = tos->data; //Declare variable and assign the top of stack's data to it.
	node<T> *temp = tos; //Declare a temporary pointer and assign it to the top of the stack.
	tos = tos->next; //Assign the top of stack to the next node in the stack.
	delete temp; //Delete the pointer to the top of the stack.
	return result; //Return the value stored in result.
}

template <typename T>
bool Stack<T>::isFull() const
{
	node<T> *temp = new (std::nothrow) node<T>(); //FIND OUT
	if (temp) //If there's enough memory to create the node, delete the node and return false.
	{
		delete temp;
		return false;
	}
	return true;
}

template <typename T>
int Stack<T>::size()
{
	int counter = 0;
	while (tos != 0)
	{
		++counter;
		tos = tos->next;
	}
	return counter;
}

#endif
