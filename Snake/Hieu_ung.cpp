#include <Windows.h>
#include <iostream>
#include "Hieu_ung.h"

using namespace std;

void Gotoxy(short x, short y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

void ChangeColor(int k)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, k);
}

COORD GetConsoleCursorPosition()
{
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
	{
		return cbsi.dwCursorPosition;
	}
	else
	{
		// The function failed. Call GetLastError() for details.
		COORD invalid = { 0, 0 };
		return invalid;
	}
}

void FixConsoleWindow()
{
	HWND cW = GetConsoleWindow();
	LONG style = GetWindowLong(cW, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(cW, GWL_STYLE, style);
}

void Nocursortype()
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = FALSE;
	info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void Print_Title(int a, int b, const char s[100])
{
	ChangeColor(a);
	Gotoxy(45, 1);
	cout << "*****************************\n";
	Gotoxy(45, 2);
	cout << "*";
	ChangeColor(b);
	cout << s;
	ChangeColor(a);
	cout << "*\n";
	Gotoxy(45, 3);
	cout << "*****************************\n";
}