#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <Windows.h>
using namespace std;
#pragma warning (disable : 4996)
void CreateTXT(char* fname)
{
	ofstream fout(fname);
	char ch;
	string s;
	do
	{
		cin.get();
		cin.sync();
		cout << "enter line: "; getline(cin, s);
		fout << s << endl;
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}

void PrintTXT(char* fname)
{
	ifstream fin(fname);
	string s;
	while (getline(fin, s))
	{
		cout << s << endl;
	}
	cout << endl;
}

int MinWord(char* fname, char* tname)
{

	ofstream tout(tname);

	int min = 100;
	char* minWord;
	ifstream fin(fname);
	char s[100];
	char* w;
	int k = 0, k1 = 0;
	while (fin.getline(s, sizeof(s)))
	{
		w = strtok(s, " .,:;!?-'");
		minWord = w;
		int min = 100;
		while (w != NULL)
		{
			int tmp = strlen(w);
			if (tmp < min)
			{
				min = tmp;
				minWord = w;
			}
			k++;
			w = strtok(NULL, " .,:;!?-'");
		}
		k1++;
		tout << minWord << endl;
	}
	tout << k1;
	return k;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int d;
	char fname[100];

	do
	{
		cout << endl;
		cout << "Виберіть дію" << endl;
		cout << "[1] створити файл " << endl;
		cout << "[2] вивід файлу оригіналу" << endl;
		cout << "[3] вивід файлу форматоватого" << endl;
		cout << "[9]  Відкрити файл." << endl;
		cout << "[0] вихід " << endl << endl;
		cout << "Введіть пункт >> ";
		cin >> d;
		switch (d)
		{
		case 1:

			cout << "Введіть назву файлу:"; cin >> fname;
			CreateTXT(fname);
			break;
		case 2:
			char tname[100];
			cout << "Введіть назву нового файлу:";
			cin >> tname;
			cout << "Загальна кількість слів = " << MinWord(fname, tname) << endl;
			PrintTXT(tname);
			break;
		case 3:
			PrintTXT(fname);
			break;
		case 9:
			cout << "Введіть ім'я файлу: "; cin >> fname;
			break;
		case 0:
			d = 0;
			break;
		default:
			cout << "Ви ввели помилкове значення!" << endl;
			break;

		}

	} while (d != 0);

	return 0;
}