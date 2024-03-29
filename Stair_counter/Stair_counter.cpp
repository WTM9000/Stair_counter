#include <iostream>
#include <locale>
#include <stdexcept>
#include <fstream>

using namespace std;

/*!
* \��������� ���������� �� ����� ������ �� ������������ �����������
* \return - ����� �������, ���� ������ ���������
*/
int inputCheck() 
{
	// �������� ������ ��� ����� � �������� �������
	string path_to_input_file; // ������ ��� �����
	cout << "������� ������ ��� ����� � �������� �������" << std::endl;
	cin >> path_to_input_file;

	// ��������� ���������� �����
	size_t pos = path_to_input_file.rfind('.');
	if (path_to_input_file.substr(pos + 1, string::npos) != "txt")
		throw runtime_error("������� ������� ���������� �����. ���� ������ ����� ���������� .txt.");

	//��������� ������������� �����
	ifstream input(path_to_input_file);
	if (!input.is_open())
	{
		throw runtime_error("������� ������ ���� � �������� �������. ��������, ���� �� ����������.");
	}

	char ch; // ����������� ������ �� �����
	int prev_num = 0; // ��������� ����������� ������ - �����
	int found_num = 0; // ������� ����� 
	int float_num = 0; // ������� ����� ����� �����
	int is_empty = 0; // ���� ����

	// ��������� ���������� ����� �� ������������
	while (input >> ch)
	{
		is_empty = 1; // ���� �� ����

		// ���� ����������� ������ �������� ������������, ��� ���������� ������ ������������� � ������������ �����...
		if (((ch > '9') || (ch < '0')) && 
			((ch != '.')||(ch == '.' && !prev_num)) && 
			((ch != '-')||(ch == '-' && found_num)) &&
			(float_num && !prev_num) &&
			(ch != ' ') && (ch != '\n'))
		{
			// ������ ������
			printf_s("������� �������� �%c� �������� ������������ ��������.", ch);
			throw runtime_error("");
		}

		// ���� ����������� ������ - �����
		if (ch >= '0' && ch <= '9' && !float_num)
		{
			found_num = 1; // �������� �����
			prev_num = 1; // ��������� ����������� ������ - �����
		}
		else
			prev_num = 0; // ��������� ����������� ������ - �� �����

		// ���� ����������� ������ - �����, � ���������� ������ - ����� ����� �����
		if (ch >= '0' && ch <= '9' && float_num)
		{
			// ��������� ����� - �������, ������ ������
			throw runtime_error("������� �������� �� �������� �����.");
		}

		// ���� ����������� ������ - �����, � ��������� ����������� ������ - �����
		if (ch == '.' && prev_num)
		{
			// ������� ����� ����� �����
			float_num = 1;
		}
	}

	// ���� ���� �������� ����
	if (!is_empty)
	{
		// ������ ������
		throw runtime_error("����������� ������� ��������.");
	}

	// �������� ����� �� �����
	ifstream input_1(path_to_input_file);
	int num = 0;
	input_1 >> num;

	// ���� ����� ��� ����������� ���������
	if (num <= 0 || num > 100)
	{
		// ������ ������
		printf_s("������� �������� %d �� ����������� ��������� (1 .. 100).", num);
		throw runtime_error("");
	}
	// ������� ���������� �����
	return num;
}

/*!
* \ ���������� ���-�� ��������� �������, ������� ����� ��������� �� n �������
* \param[in] prev_level - ����� ������� �� ������� ������ �������, �.�. ����� ������� �� ������ ������ ������������ ������� ������ ����
*                         ������ ����� �����
* \param[in] n - ����� �������, �� ������� ����� ���� ���������� �������, (0, 100]
*/
int get_count(int prev_level, int n) 
{
	// ���� ������ �����������
	if (0 == n)
		return 1; // ������� ��������� �������������

	// �������� ������� �������
	int count = 0;

	// ��� ������� ���������� ���-�� ������� �� ������� ������
	for (int level = 1; level < prev_level; ++level) {
		// ���� ������ �����������
		if ((n - level) < 0)
			break; // ��������� ����
		// ��������� ���-�� ��������� �������, ������� ����� ��������� �� ���������� ������� � ��������� ����������� ����� � �������� �������
		count += get_count(level, n - level);
	}
	// ������� ���-�� �������
	return count;
}

int main() 
{
	setlocale(LC_ALL, "Russian");

	try
	{
		int n; // ���-�� �������
		// �������� ����� ������� �� �����, ���� ���������� ����� ���������
		n = inputCheck();

		// ��������� ���-�� ������� � �������� ��������� � ����
		ofstream ofst("output.txt");
		ofst << get_count(n + 1, n);
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
}