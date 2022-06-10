#include "pch.h"
#include "CppUnitTest.h"
#include "../Stair_counter/Stair_counter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace inputCheck_Test
{
	TEST_CLASS(inputCheck_Test)
	{
	public:
		
		TEST_METHOD(Proper_data)
		{
			char input_data[200] = "25";
			int exp_result = 25;
			int result = inputCheck(input_data);
			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(Data_below_limit)
		{
			char input_data[200] = "0";
			int exp_result = -3;
			int result = inputCheck(input_data);
			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(Data_over_limit)
		{
			char input_data[200] = "101";
			int exp_result = -3;
			int result = inputCheck(input_data);
			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(Unallowed_symbol_no_number)
		{
			char input_data[200] = "*&^";
			int exp_result = -1;
			int result = inputCheck(input_data);
			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(Symbol_before_number)
		{
			char input_data[200] = "*&&25";
			int exp_result = -1;
			int result = inputCheck(input_data);
			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(Symbol_after_number)
		{
			char input_data[200] = "25#$";
			int exp_result = -1;
			int result = inputCheck(input_data);
			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(Empty_input_data)
		{
			char input_data[200] = "";
			int exp_result = -2;
			int result = inputCheck(input_data);
			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(Number_with_spaces)
		{
			char input_data[200] = "     25         ";
			int exp_result = 25;
			int result = inputCheck(input_data);
			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(Multiple_numbers)
		{
			char input_data[200] = "25 34";
			int exp_result = -5;
			int result = inputCheck(input_data);
			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(Non_integer)
		{
			char input_data[200] = "2,5";
			int exp_result = -4;
			int result = inputCheck(input_data);
			Assert::AreEqual(exp_result, result);
		}
	};
}
