#pragma once
#include "List.h"
#include "Stack.h"
#include <iostream>
#include <string>
#include <math.h>

enum priority { brecket, plusminus, dividemulti, degree, function, operand};
enum func { Sin, Cos, Tg, Ctg, Log, Ln, Sqrt, Abs};

bool if_num(char);
bool if_func(char);
int priority(char);
int which_func(string func);
double func(int func, double data);
double sign(string oper, double data1, double data2);
List* check(string exp);
List* inf_to_pref(List* elem);
List* print_pref(List* pref);
double Calc(List* to_print);
void print_final(string exp);