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
		throw runtime_error("����������� ���� � �������� �������");
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
		cout << "������ ������� ����������: " << ex.what() << endl;
	}
	return 0;
}