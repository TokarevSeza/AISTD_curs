#include<iostream>
#include<string>
#include"Calc.h"
#include"List.h"
#include"Element.h"
using namespace std;

int main()
{
	string str = "(((5+6)*2)-((9-7)*(1+1)))";
	print_final(str);
	return 0;
}