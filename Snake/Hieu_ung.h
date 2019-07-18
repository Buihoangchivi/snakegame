#include <Windows.h>
#pragma once
#ifndef _MY_Hieu_Ung
#define _MY_Hieu_Ung

void Gotoxy(short x, short y);
void ChangeColor(int k);
COORD GetConsoleCursorPosition();
void Print_Title(int a, int b, const char s[100]);
void FixConsoleWindow();
void Nocursortype();

#endif 

