#include <iostream>
#include <locale>
#include <stdexcept>
#include <fstream>

using namespace std;

int inputCheck() 
{
	string path_to_input_file;
	cout << "������� ������ ��� ����� � �������� �������" << std::endl;
	cin >> path_to_input_file;
	ifstream input(path_to_input_file);
	if (!input.is_open())
	{
		throw runtime_error("������� ������ ���� � �������� �������. ��������, ���� �� ����������.");
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
			printf_s("������� �������� �%c� �������� ������������ ��������.", ch);
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
			throw runtime_error("������� �������� �� �������� �����.");
	}
	
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