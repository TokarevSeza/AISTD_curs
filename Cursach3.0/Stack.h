#pragma once
#include"Element.h"
class Stack
{
private:
	Element* top;
	int Size;
public:
	Stack()
	{
		top = nullptr;
		Size = 0;
	}
	~Stack()
	{
		while (!isEmpty())
			pop();
	}

	bool isEmpty();
	Element* return_last();
	Element* pop();
	Element* push(double);
	void push(Element*);
};