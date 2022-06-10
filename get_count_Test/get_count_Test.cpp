#include "pch.h"
#include "CppUnitTest.h"
#include "../Stair_counter/Stair_counter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace getcountTest
{
	TEST_CLASS(getcountTest)
	{
	public:
		
		TEST_METHOD(Normal_work)
		{
			int n = 10;
			int prev_level = 11;
			int exp_result = 10;
			int result = get_count(prev_level, n);
			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(More_blocks)
		{
			int n = 50;
			int prev_level = 30;
			int exp_result = 3287;
			int result = get_count(prev_level, n);
			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(More_prev_level)
		{
			int n = 30;
			int prev_level = 50;
			int exp_result = 296;
			int result = get_count(prev_level, n);
			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(Equal_block_amount)
		{
			int n = 50;
			int prev_level = 50;
			int exp_result = 3657;
			int result = get_count(prev_level, n);
			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(Minimal_data)
		{
			int n = 1;
			int prev_level = 1;
			int exp_result = 0;
			int result = get_count(prev_level, n);
			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(Max_blocks_min_prev_level)
		{
			int n = 100;
			int prev_level = 1;
			int exp_result = 0;
			int result = get_count(prev_level, n);
			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(Min_blocks_max_prev_level)
		{
			int n = 1;
			int prev_level = 101;
			int exp_result = 0;
			int result = get_count(prev_level, n);
			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(Maximum_data)
		{
			int n = 100;
			int prev_level = 101;
			int exp_result = 444793;
			int result = get_count(prev_level, n);
			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(Even_blocks_even_prev_level)
		{
			int n = 36;
			int prev_level = 34;
			int exp_result = 665;
			int result = get_count(prev_level, n);
			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(Even_blocks_odd_prev_level)
		{
			int n = 36;
			int prev_level = 33;
			int exp_result = 663;
			int result = get_count(prev_level, n);
			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(Odd_blocks_even_prev_level)
		{
			int n = 35;
			int prev_level = 34;
			int exp_result = 583;
			int result = get_count(prev_level, n);
			Assert::AreEqual(exp_result, result);
		}

		TEST_METHOD(Odd_blocks_odd_prev_level)
		{
			int n = 35;
			int prev_level = 33;
			int exp_result = 582;
			int result = get_count(prev_level, n);
			Assert::AreEqual(exp_result, result);
		}
	};
}
