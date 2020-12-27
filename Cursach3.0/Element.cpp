#include "Element.h"

Element* Element::getNext()
{
	return next;
}

double Element::getData()
{
	return data;
}

string Element::getString()
{
	return String;
}

void Element::setNext(Element* new_element)
{
	next = new_element;
}

void Element::setData(double information)
{
	data = information;
}

void Element::setData(string information)
{
	String = information;
}

void Element::setData(double data_key, string information)
{
	data = data_key;
	String = information;
}