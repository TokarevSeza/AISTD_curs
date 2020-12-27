#include "Calc.h"
bool correctness = true;

bool if_num(char symbol) // A function that checks if a character is a number
{
	if (isdigit((int)symbol))
		return true;
	else
		return false;
}

bool if_func(char symbol) // A function that checks if a symbol is a function
{
	if (!isdigit(symbol) && (symbol != '+') && (symbol != '+') && (symbol != '-') && (symbol != '*') && (symbol != '/') && (symbol != '^'))
		return true;
	else
		return false;
}

int priority(char symbol) // Function that determines the priority of the entered character
{
	if ((symbol == '(') || (symbol == ')'))
		return brecket;
	else if ((symbol == '+') || (symbol == '-'))
		return plusminus;
	else if ((symbol == '*') || (symbol == '/'))
		return dividemulti;
	else if (symbol == '^')
		return degree;
	else
		return operand;
}

int which_func(string func) // A function that determines what kind of function we have
{
	if (func == "sin")
		return Sin;
	if (func == "cos")
		return Cos;
	if (func == "tg")
		return Tg;
	if (func == "ctg")
		return Ctg;
	if (func == "log")
		return Log;
	if (func == "ln")
		return Ln;
	if (func == "sqrt")
		return Sqrt;
	if (func == "abs")
		return Abs;
}

double func(int func, double data) // Function that calculates the value of a function
{
	switch (func)
	{
	case Sin:
		return sin(data);
	case Cos:
		return cos(data);
	case Tg:
		return tan(data);
	case Ctg:
		return (cos(data) / sin(data));
	case Log:
		return log10(data);
	case Ln:
		return log(data);
	case Sqrt:
		return sqrt(data);
	case Abs:
		return abs(data);
	}
}

double sign(string oper, double data1, double data2) // Function that calculates the value of a signed expression	
{
	switch (oper[0])
	{
	case '+':
		return (data1 + data2);
	case '-':
		return (data1 - data2);
	case '*':
		return (data1 * data2);
	case '/':
		return (data1 / data2);
	case '^':
		return (pow(data1, data2));
	}
}

List* check(string exp) // Function that checks the entered expression for correctness
{
	List* elem = new List;
	size_t breckets = 0;

	for (size_t i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '(')
		{
			breckets++;
			elem->push(priority(exp[i]), "(");
			if ((priority(exp[i + 1]) != operand) && (exp[i + 1] != '('))
			{
				cout << "Invalid input" << endl;
				correctness = false;
				return nullptr;
			}
		}
		else if (if_num(exp[i]))
		{
			double data;
			string number;
			size_t dot_counter = 0;
			while ((if_num(exp[i])) || (exp[i] == '.'))
			{
				number.push_back(exp[i]);
				if (exp[i] == '.')
					dot_counter++;
				if (dot_counter > 1)
				{
					cout << "Invalid input" << endl;
					correctness = false;
					return nullptr;
				}
				i++;
			}
			i--;
			data = stod(number);
			elem->push(data);
		}
		else if (exp[i] = ')')
		{
			breckets--;
			elem->push(priority(exp[i]), ")");
		}
		else if (if_func(exp[i]))
		{
			string func;
			while (if_func(exp[i]))
			{
				func.push_back(exp[i]);
				i++;
			}
			i--;
			elem->push(priority::function, func);
		}
		else
		{
			cout << "Invalid input" << endl;
			correctness = false;
			return nullptr;
		}

	}
	if (breckets != 0)
	{
		cout << "Invalid input" << endl;
		correctness = false;
		return nullptr;
	}
	return elem;
}

List* inf_to_pref(List* elem) // Function converting infix to prefix
{
	List* reverse = new List;
	if (elem == nullptr)
		return nullptr;
	Stack stack;
	while (!elem->isEmpty())
	{
		Element* curr = new Element;
		curr = elem->pop();
		string curr_str = curr->getString();
		double curr_data = curr->getData();
		if (curr_str == ")")
			stack.push(curr);
		else if (curr_str == "(")
			while (stack.return_last()->getString() != ")")
				reverse->push(stack.pop());
		else
		{
			if (!stack.isEmpty())
				while (curr_data <= stack.return_last()->getData())
				{
					reverse->push(stack.pop());
					if (stack.isEmpty())
						break;
				}
			stack.push(curr);

		}
	}
	while (!stack.isEmpty())
		reverse->push(stack.pop());

	List* pref = new List;
	while (!reverse->isEmpty())
	{
		Element* pref_curr = reverse->pop();
		string pref_str = pref_curr->getString();
		double pref_data = pref_curr->getData();
		if (pref_str == "&")
			pref->push(pref_data);
		else
			pref->push(pref_data, pref_str);
	}
	return pref;
}

List* print_pref(List* pref) // A function that displays a prefix form
{
	List* to_print = new List;
	while (!pref->isEmpty())
	{
		Element* curr = pref->popFront();
		string curr_str = curr->getString();
		double curr_data = curr->getData();
		if (curr_str == "&")
		{
			cout << curr_data << ' ';
			to_print->push(curr_data);
		}
		else
		{
			cout << curr_str << ' ';
			to_print->push(curr_data, curr_str);
		}
	}
	return to_print;
}

double Calc(List* to_print) // Function that calculates the result of a prefixed expression
{
	Stack stack;
	double result;
	while (!to_print->isEmpty())
	{
		Element* curr = to_print->pop();
		string curr_str = curr->getString();
		double curr_data = curr->getData();
		double second_oper;

		if ((curr_data == priority::function) && (!stack.isEmpty()))
		{
			result = func(which_func(curr_str), stack.pop()->getData());
			stack.push(result);
		}
		else if (!stack.isEmpty())
		{
			result = stack.pop()->getData();
			if (stack.isEmpty())
				return 0;
			second_oper = stack.pop()->getData();
			result = sign(curr_str, result, second_oper);
			stack.push(result);
		}
	}
}

void print_final(string exp)
{
	cout << "Infix: " << exp << endl;
	List* one = check(exp);
	List* two = inf_to_pref(one);
	cout << "Prefix: ";
	List* three = print_pref(two);
	double result = Calc(two);
	cout << endl << "result = " << result << endl;

}