#pragma once
#include <stdexcept>
using namespace std;
class Element
{
	Element* next;
	double data;
	string String;

	void setData(string);
	void setNext(Element*);
	void setData(double, string);
	void setData(double);
public:
	Element()
	{
		data = -1;
		String = "&";
		next = nullptr;
	}
	~Element()
	{
		delete next;
		next = nullptr;
	}

	Element* getNext();
	double getData();
	string getString();
	friend class List;
	friend class Stack;
};