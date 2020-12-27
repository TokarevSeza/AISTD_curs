#include "List.h"
#include "Element.h"

bool List::isEmpty()
{
	if (Size == 0)
		return true;
	return false;
}

int List::size()
{
	return Size;
}

Element* List::push(double data_key)
{
	Element* new_element = new Element;
	new_element->setData(data_key);
	if (isEmpty())
	{
		head = tail = new_element;
	}
	else
	{
		new_element->setNext(tail);
		tail = new_element;
	}
	Size++;
	return new_element;
}

Element* List::push(string data)
{
	Element* new_element = new Element;
	new_element->setData(data);
	if (isEmpty())
		head = tail = new_element;
	else
	{
		new_element->setNext(tail);
		tail = new_element;
	}
	Size++;
	return new_element;
}

Element* List::push(double number, string data)
{
	Element* new_element = new Element;
	new_element->setData(number, data);
	if (isEmpty())
		head = tail = new_element;
	else
	{
		new_element->setNext(tail);
		tail = new_element;
	}
	Size++;
	return new_element;
}

void List::push(Element* new_element)
{
	if (isEmpty())
		head = tail = new_element;
	else
	{
		new_element->setNext(tail);
		tail = new_element;
	}
	Size++;
}

Element* List::popFront()
{
	Element* Delete;
	if (isEmpty())
		throw out_of_range("the queue is empty");
	else if (size() == 1)
	{
		Delete = head;
		head = tail = nullptr;
	}
	else
	{
		Delete = head;
		for (Element* now = tail; now->getNext() != nullptr; now = now->getNext())
			head = now;
		head->next = nullptr;
	}
	Size--;
	return Delete;
}

Element* List::pop()
{
	Element* Delete = tail;
	if (isEmpty())
		throw out_of_range("the queue is empty");
	else if (size() == 1)
	{
		Delete = tail;
		head = tail = nullptr;
		Size--;
	}
	else
	{
		tail = tail->getNext();
		Size--;
	}
	return Delete;
}