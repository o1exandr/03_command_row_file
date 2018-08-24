/*
Завдання 3.
Створити  програму, яка працює подібно стандартній програмі Командний Рядок. Тобто програма очікує команду і виконує її.
Вихід з програми виконувати за командою exit або quit. Реалізувати  наступні команди:
o	create filename(створення текстового файлу, завершення вводу – комбінація Ctrl-Z)
o	print filename(вивід  текстового файлу на екран)
o	append filename(доповнення текстового файлу, завершення вводу – комбінація Ctrl-Z)
o	copy filename1 filename2(копіювання файлу)
При введенні невірної команди або вказанні невірного шляху до файлу програма повинна видавати
відповідне повідомлення(«Невірна команда», «Невірна кількість параметрів», «Невірний шлях до файлу»).

*/


#include "stdafx.h"
#include <iostream> 
#include <string>
#include <fstream>

using namespace std;

void createFile(const string & fname);
void printFile(const string & fname);
void appendFile(const string & fname);
void copyFile(const string & fname1, const string & fname2);



int main()
{
	cout << "Manual\n------\n";
	cout << "create filename\n"; // (створення текстового файлу, завершення вводу – комбінація Ctrl - Z)
	cout << "print filename\n"; //(вивід  текстового файлу на екран)
	cout << "append filename\n"; // (доповнення текстового файлу, завершення вводу – комбінація Ctrl - Z)
	cout << "copy filename1 filename2\n";
	cout << "exit\n\n";
	string command = "";

	


	while (command != "exit")
	{
		cout << "\ncommand >> ";
		getline(cin, command);
		string str[3] = {};
		int count = 0;
		for (int i = 0; i < command.length(); ++i)
			if (command[i] != ' ')
				str[count] += command[i];
			else
				++count;
	//	for (int i = 0; i < 3; ++i)
	//		cout << str[i] << " ";
		if (str[0] == "create")
		{
			createFile(str[1]);
		}
		else
			if (str[0] == "print")
			{
				printFile(str[1]);
			}
			else
				if (str[0] == "append")
				{
					appendFile(str[1]);
				}
				else
					if (str[0] == "copy")
					{
						copyFile(str[1], str[2]);
					}
					else
						if (str[0] != "exit")
							cout << "! Wrong command " << str[0] << endl;
		str[3] = {};
	}


	/*
	if (argc >= 2)
	{
	ifstream fileBefore; // 01_fileBefore.cpp
	ofstream fileAfter;  // 01_fileAfter.cpp

	fileBefore.open(argv[1], ios::out);
	fileAfter.open(argv[2], ios::in | ios::trunc);

	string str;

	if (!fileBefore.is_open())
	{
	cerr << "Error read\n";
	return 0;
	}
	else
	while (getline(fileBefore, str))
	{
	bool flag = 1;
	if (str == "");
	else
	for (int i = 0; i < str.length() - 1; ++i)
	if (str[i] == '/' && str[i + 1] == '/')
	{
	cout << "deleted row:\t" << str << endl;
	flag = 0;
	break;
	}

	if (flag)
	fileAfter << str << endl;

	}

	fileBefore.close();
	fileAfter.close();
	}
	else
	{
	cout << "Function has " << argc << " agrument. Add 2 filename to command row\n";
	}

	*/


	return 0;

}




void createFile(const string & fname)
{
	ofstream inF;
	inF.open(fname, ios::in | ios::trunc);

	if (!inF.is_open())
	{
		cerr << "Error create. Wrong name/path file (" << fname << ")" << endl;
		return;
	}

	string str = "";
	string text = "";
	while (cin.good())
	{
		//cin.getline(str, 256);
		cin >> str;
	}
	//cout << str;
		
	inF << str;
	inF.close();
	cout << "\t" << fname << " create\n";

}


void printFile(const string & fname)
{

	string str;

	ifstream outF(fname, ios::out);
	if (!outF.is_open())
	{
		cerr << "Error read. Wrong name/path file (" << fname << ")" << endl;
		return;
	}

	while (getline(outF, str))
	{
		cout << str << endl;
	}
	cout << "\t" << fname << " print\n";
	outF.close();

}

void appendFile(const string & fname)
{
	ofstream inF;
	inF.open(fname);

	if (!inF.is_open())
	{
		cerr << "Error create\n";
		return;
	}
	else
	{

		int num;
		cout << "Enter number of row(s) ";
		cin >> num;
		cin.ignore();
		string str;


		for (int i = 0; i < num; ++i)
		{
			getline(cin, str);
			inF << str << endl;
		}
		inF.close();
		cout << "\t" << fname << " create\n";
	}


}

void copyFile(const string & fname1, const string & fname2)
{



}



