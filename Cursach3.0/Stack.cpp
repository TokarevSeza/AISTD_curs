#include "Stack.h"

bool Stack::isEmpty()
{
	if (Size == 0)
		return true;
	return false;
}


Element* Stack::return_last()
{
	return top;
}

Element* Stack::pop()
{
	Element* to_delete = top;
	if (isEmpty())
		throw out_of_range("the stack is empty");
	else if (Size == 1)
	{
		top == nullptr;
		Size--;
	}
	else
	{
		top = top->getNext();
		Size--;
	}
	return to_delete;
}

Element* Stack::push(double data)
{
	Element* new_element = new Element;
	new_element->setData(data);
	if (isEmpty())
		top = new_element;
	else
	{
		new_element->setNext(top);
		top = new_element;

	}
	Size++;
	return new_element;
}

void Stack::push(Element* new_element)
{
	if (isEmpty())
		top = new_element;
	else
	{
		new_element->setNext(top);
		top = new_element;
	}
	Size++;
}