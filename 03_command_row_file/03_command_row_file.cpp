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

#define LINE "\n------------------------\n";

void createFile(const string & fname);
void printFile(const string & fname);
void appendFile(const string & fname);
void copyFile(const string & fname1, const string & fname2);
void commandRow();



int main()
{
	cout << "Manual\n------\n";
	cout << "create filename\n"; // (створення текстового файлу, завершення вводу – комбінація Ctrl - Z)
	cout << "print filename\n"; //(вивід  текстового файлу на екран)
	cout << "append filename\n"; // (доповнення текстового файлу, завершення вводу – комбінація Ctrl - Z)
	cout << "copy filename1 filename2\n";
	cout << "exit\n\n";
	
	commandRow();

	cout << endl;
	system("pause");
	return 0;
}

void commandRow()
{
	string command = "";

	while (true)
	{
		//читаємо ком.рядок
		cout << "\ncommand >> ";
		getline(cin, command);
		string str[3] = {};
		int count = 0;

		//розбиваємо командний рядок на слова
		for (int i = 0; i < command.length(); ++i)
			if (command[i] != ' ')
				str[count] += command[i];
			else
				++count;

		//якщо exit то виходимо і далі не продовжуємо
		if (str[0] == "exit")
			break;

		//перебираємо всі існуючі команди і виконуємо відповідні дії
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
						if (str[2] == "")
							cout << "Error. Empty 2-nd namefile. Write path/namefile for copy after command and name of original file\nExample copy file1.txt file2.txt";
						else
						copyFile(str[1], str[2]);
					}
					else
						cout << "! Wrong command " << str[0] << endl;
		cin.clear();
	}


}

void createFile(const string & fname)
{
	ofstream inF;
	inF.open(fname);

	if (!inF.is_open())
	{
		cerr << "Error create. Wrong name/path file (" << fname << ")" << endl;
		return;
	}

	string str = "";
	while (cin.good())
	{
		getline(cin, str);
		inF << str << endl;
	}
	
	inF.close();
	cout << "\t" << fname << " create" << LINE;

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
	cout << "\t" << fname << " print" << LINE;
	outF.close();

}

void appendFile(const string & fname)
{
	ofstream inF;
	inF.open(fname, ios::app);

	if (!inF.is_open())
	{
		cerr << "Error create. Wrong name/path file (" << fname << ")" << endl;
		return;
	}

	string str = "";
	while (cin.good())
	{
		getline(cin, str);
		inF << str << endl;
	}

	inF.close();
	cout << "\t" << fname << " append" << LINE;

}

void copyFile(const string & fname1, const string & fname2)
{
		ifstream fileOriginal;
		ofstream fileCopy;

		fileOriginal.open(fname1, ios::out);
		fileCopy.open(fname2);

		string str;

		if (!fileOriginal.is_open())
		{
			cerr << "Error create. Wrong name/path file (" << fname1 << ")" << endl;
			return;
		}


		while (getline(fileOriginal, str))
		{
			fileCopy << str << endl;
		}

		fileOriginal.close();
		fileCopy.close();
		cout << "\t" << fname2 << " create" << LINE;

}







