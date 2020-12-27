#include "pch.h"
#include "CppUnitTest.h"
#include "../Cursach3.0/Calc.h"
#include "../Cursach3.0/Stack.h"
#include "../Cursach3.0/List.h"
#include "../Cursach3.0/Element.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		string exp;
		TEST_METHOD(Calc1)
		{
			exp = "(ln(12*sin(1/2))/2)^2";
			List* Cheking = check(exp);
			List* translate = inf_to_pref(Cheking);
			List* print = print_pref(translate);
			double correct = pow((log(12 * sin(1 / 2)) / 2), 2);
			double result = Calc(print);
			Assert::AreEqual(correct, result);
		}

		TEST_METHOD(Calc2)
		{
			exp = "(((5+6)*2)-((9-7)*(1+1)))";
			List* Cheking = check(exp);
			List* translate = inf_to_pref(Cheking);
			List* print = print_pref(translate);
			double correct = ((5+6)*2) - ((9-7)*(1+1));
			double result = Calc(print);
			Assert::AreEqual(correct, result);
		}

		TEST_METHOD(Cheking)
		{
			correctness = true;
			exp = "((2+8)";
			List* cheking = check(exp);
			Assert::IsFalse(correctness);
		}

		TEST_METHOD(Cheking2)
		{
			correctness = true;
			exp = "(++95-3)";
			List* cheking = check(exp);
			Assert::IsFalse(correctness);
		}

		TEST_METHOD(Cheking3)
		{
			correctness = true;
			exp = "ctg(17()*89";
			List* cheking = check(exp);
			Assert::IsFalse(correctness);
		}
	};
}
