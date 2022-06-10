#include <iostream>
#include <locale>
#include <stdexcept>
#include <fstream>

using namespace std;

int inputCheck() 
{
	string path_to_input_file;
	cout << "Введите полное имя файла с входными данными" << std::endl;
	cin >> path_to_input_file;
	ifstream input(path_to_input_file);
	if (!input.is_open())
	{
		throw runtime_error("Неверно указан файл с входными данными. Возможно, файл не существует.");
	}
	char ch;
	int prev_num = 0;
	int found_num = 0;
	int float_num = 0;
	while (input >> ch)
	{
		if (((ch > '9') || (ch < '0')) && 
			((ch != '.')||(ch == '.' && !prev_num)) && 
			((ch != '-')||(ch == '-' && found_num)) && 
			(ch != ' ') && (ch != '\n'))
		{
			printf_s("Входное значение «%c» является недопустимым символом.", ch);
			throw runtime_error("");
		}

		if (ch >= '0' && ch <= '9')
		{
			found_num = 1;
			prev_num = 1;
		}
		else
			prev_num = 0;

		if (ch == '.' && prev_num)
			throw runtime_error("Входное значение не является целым.");
	}
	ifstream input_1(path_to_input_file);
	int num;
	input_1 >> num;
	if (num <= 0 || num >= 100)
	{
		printf_s("Входное значение %d не принадлежит диапазону (1 .. 100).", num);
		throw runtime_error("");
	}
	return num;
}

int get_count(int prev_level, int n) 
{
	return -1;
}

int main() 
{
	setlocale(LC_ALL, "Russian");
	try
	{
		int n;

		inputCheck();
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
	return 0;
}