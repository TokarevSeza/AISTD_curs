#pragma once
#include "Element.h"

class List
{
private:
	Element* head;
	Element* tail;
	int Size = 0;
public:
	List()
	{
		head = nullptr;
		tail = nullptr;
		Size = 0;
	}
	~List()
	{
		while (isEmpty() == false)
			pop();
	}

	int size();
	bool isEmpty();
	Element* pop();
	Element* push(double);
	Element* push(string);
	Element* push(double, string);
	void push(Element*);
	Element* popFront();
};