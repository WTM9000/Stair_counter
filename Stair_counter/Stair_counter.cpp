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
	while (input >> ch)
	{

		if (((ch > '9') || (ch < '0')) && (ch != ',') && (ch != '.') && (ch != ' ') && (ch != '\n'))
		{
			printf_s("Входное значение «%c» является недопустимым символом.", ch);
			throw runtime_error("");
		}
	}
	return 0;
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
		inputCheck();
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
	return 0;
}