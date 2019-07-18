#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <Windows.h>
#include "Hieu_ung.h"
#include "Setup.h"
#include "Process.h"
#define fi "Data.txt"

using namespace std;

extern FILE* f;
extern int sp, pt, length, dir, kind, vip, pass, x[200], y[200];
extern short c[200][100];
float ii;
bool ok = true;

void Arr()
{
	for (int i = length; i > 0; i--)
	{
		x[i] = x[i - 1];
		y[i] = y[i - 1];
	}
}

DWORD WINAPI ThreadProc(LPVOID param)
{
	for (ii = 10; ii >= 0; ii -= 0.1)
	{
		COORD t = GetConsoleCursorPosition();
		if (c[x[0]][y[0]] == 3) break;
		Gotoxy(60, 22);
		ChangeColor(15);
		cout << "Your Time Remain: ";
		if (ii >= 8) ChangeColor(10);
		else if (ii >= 6) ChangeColor(9);
		else if (ii >= 4) ChangeColor(11);
		else if (ii >= 2) ChangeColor(14);
		else ChangeColor(12);
		printf("%.1f  ", ii);
		Sleep(50);
		Gotoxy(t.X, t.Y);
		ChangeColor(14);
	}
	Increase_Point(2, ii);
	COORD t = GetConsoleCursorPosition();
	c[x[0]][y[0]] = 0;
	Gotoxy(60, 22);
	for (int j = 0; j < 20; j++)
		cout << " ";
	Gotoxy(t.X, t.Y);
	ChangeColor(14);
	return 0;
}

void Add_Tail(int a, int b)
{
	length++;
	x[length] = a;
	x[length] = b;
}

void Left()
{
	int temp1 = x[0] - 1, temp2 = x[0];
	if (kind == 1)
	{
		if (x[0] == 0) temp1 = 119;
		Gotoxy(temp1, y[0]);
		ChangeColor(3);
		cout << "X";
		Gotoxy(temp2, y[0]);
		ChangeColor(14);
		cout << "O";
		if (c[temp1][y[0]] != 2)
		{
			Gotoxy(x[length], y[length]);
			cout << " ";
		}
		else Add_Tail(x[length], y[length]);
		Gotoxy(temp1, y[0]);
		Arr();
		if (x[0] == 0) x[0] = 119;
		else x[0]--;
		return;
	}
	if (x[0] == 20 && c[x[0]][y[0]] != 1) temp1 = 100;
	Gotoxy(temp1, y[0]);
	ChangeColor(3);
	cout << "X";
	Gotoxy(temp2, y[0]);
	ChangeColor(14);
	cout << "O";
	if (c[temp1][y[0]] != 2)
	{
		Gotoxy(x[length], y[length]);
		cout << " ";
	}
	else Add_Tail(x[length], y[length]);
	Gotoxy(temp1, y[0]);
	Arr();
	if (x[0] == 20 && c[x[0]][y[0]] != 1) x[0] = 100;
	else x[0]--;
}

void Up()
{
	int temp1 = y[0] - 1, temp2 = y[0];
	if (kind == 1)
	{
		if (y[0] == 0) temp1 = 19;
		Gotoxy(x[0], temp1);
		ChangeColor(3);
		cout << "X";
		Gotoxy(x[0], temp2);
		ChangeColor(14);
		cout << "O";
		if (c[x[0]][temp1] != 2)
		{
			Gotoxy(x[length], y[length]);
			cout << " ";
		}
		else Add_Tail(x[length], y[length]);
		Gotoxy(x[0], temp1);
		Arr();
		if (y[0] == 0) y[0] = 19;
		else y[0]--;
		return;
	}
	if (y[0] == 4 && c[x[0]][y[0]] != 1) temp1 = 24;
	Gotoxy(x[0], temp1);
	ChangeColor(3);
	cout << "X";
	Gotoxy(x[0], temp2);
	ChangeColor(14);
	cout << "O";
	if (c[x[0]][temp1] != 2)
	{
		Gotoxy(x[length], y[length]);
		cout << " ";
	}
	else Add_Tail(x[length], y[length]);
	Gotoxy(x[0], temp1);
	Arr();
	if (y[0] == 4 && c[x[0]][y[0]] != 1) y[0] = 24;
	else y[0]--;
}

void Right()
{
	int temp1 = x[0] + 1, temp2 = x[0];
	if (kind == 1)
	{
		if (x[0] == 119) temp1 = 0;
		Gotoxy(temp1, y[0]);
		ChangeColor(3);
		cout << "X";
		Gotoxy(temp2, y[0]);
		ChangeColor(14);
		cout << "O";
		if (c[temp1][y[0]] != 2)
		{
			Gotoxy(x[length], y[length]);
			cout << " ";
		}
		else Add_Tail(x[length], y[length]);
		Gotoxy(temp1, y[0]);
		Arr();
		if (x[0] == 119) x[0] = 0;
		else x[0]++;
		return;
	}
	if (x[0] == 100 && c[x[0]][y[0]] != 1) temp1 = 20;
	Gotoxy(temp1, y[0]);
	ChangeColor(3);
	cout << "X";
	Gotoxy(temp2, y[0]);
	ChangeColor(14);
	cout << "O";
	if (c[temp1][y[0]] != 2)
	{
		Gotoxy(x[length], y[length]);
		cout << " ";
	}
	else Add_Tail(x[length], y[length]);
	Gotoxy(temp1, y[0]);
	Arr();
	if (x[0] == 100 && c[x[0]][y[0]] != 1) x[0] = 20;
	else x[0]++;
}

void Down()
{
	int temp1 = y[0] + 1, temp2 = y[0];
	if (kind == 1)
	{
		if (y[0] == 19) temp1 = 0;
		Gotoxy(x[0], temp1);
		ChangeColor(3);
		cout << "X";
		Gotoxy(x[0], temp2);
		ChangeColor(14);
		cout << "O";
		if (c[x[0]][temp1] != 2)
		{
			Gotoxy(x[length], y[length]);
			cout << " ";
		}
		else Add_Tail(x[length], y[length]);
		Gotoxy(x[0], temp1);
		Arr();
		if (y[0] == 19) y[0] = 0;
		else y[0]++;
		return;
	}
	if (y[0] == 24) temp1 = 4;
	Gotoxy(x[0], temp1);
	ChangeColor(3);
	cout << "X";
	Gotoxy(x[0], temp2);
	ChangeColor(14);
	cout << "O";
	if (c[x[0]][temp1] != 2)
	{
		Gotoxy(x[length], y[length]);
		cout << " ";
	}
	else Add_Tail(x[length], y[length]);
	Gotoxy(x[0], temp1);
	Arr();
	if (y[0] == 24 && c[x[0]][y[0]] != 1) y[0] = 4;
	else y[0]++;
}

void Save_Game()
{
	FILE* g = fopen("data.txt", "w");
	if (kind < 7) fprintf(g, "1\n%d %d %d %d %d\n", kind, sp, pt, dir, length);
	else fprintf(g, "1\n%d %d %d %d %d %d\n", kind, sp, pt, dir, length, pass);
	for (int i = 0; i < length; i++)
		fprintf(g, "%d %d\n", x[i], y[i]);
	fclose(g);
}

bool Check()
{
	if (_kbhit())
	{
		char ch = _getch();
		if (ch == 32) ch = _getch();
		switch (ch)
		{
		case 27:
			PlaySound(NULL, NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
			Save_Game();
			system("cls");
			Print(8, 12, 3, 7, "          GOOD BYE         ");
			system("cls");
			ChangeColor(15);
			exit(0);
		case 112:
			while (!_kbhit())
			{
			}
		}
	}
	if (c[x[0]][y[0]] == 1) return false;
	for (int i = 1; i <= length; i++)
		if (x[0] == x[i] && y[0] == y[i]) return false;
	if (kind >= 7)
	{
		if (c[x[0]][y[0]] == 3)
		{
			if (kind == 11)
			{
				ok = false;
				End_Game();
				ChangeColor(15);
				fclose(f);
				f = fopen(fi, "w");
				fprintf(f, "0");
				fclose(f);
				exit(0);
			}
			else
			{
				kind++;
				Campaign();
			}
		}
	}
	if (c[x[0]][y[0]] == 2)
	{
		//vip++;
		c[x[0]][y[0]] = 0;
		if (kind < 7 || (((kind == 7 || kind == 8) && pass < 30) || ((kind == 9 || kind == 10) && pass < 25)
			|| (kind == 11 && pass < 20))) Make_Food('$', 2);
		Increase_Point(1, 0);
		/*if (vip % 1 == 0)
		{
			Make_Food('#', 3);
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)& ThreadProc, NULL, 0, NULL);
		}*/
	}
	return true;
}

void Increase_Process()
{
	COORD t = GetConsoleCursorPosition();
	Gotoxy(38 + pass, 27);
	switch (kind)
	{
	case 7:
		ChangeColor(3);
		break;
	case 8:
		ChangeColor(4);
		break;
	case 9:
		ChangeColor(2);
		break;
	case 10:
		ChangeColor(8);
		break;
	case 11:
		ChangeColor(5);
		break;
	}
	cout << (char)219;
	Gotoxy(t.X, t.Y);
}

void Increase_Point(int k, float n)
{
	if (k == 1)
		switch (sp)
		{
		case 1: pt += 2;
			break;
		case 2: pt += 3;
			break;
		case 3: pt += 4;
			break;
		case 4: pt += 5;
			break;
		case 5: pt += 6;
			break;
		}
	else pt += (int)n * 10;
	if (kind >= 7 && (pass + 1) % kind == 0) pt += kind;
	COORD t = GetConsoleCursorPosition();
	if (kind == 1)
	{
		Gotoxy(15, 22);
		for (int i = 0; i < 10; i++)
			cout << " ";
		Gotoxy(15, 22);
	}
	else
	{
		Gotoxy(15, 27);
		for (int i = 0; i < 10; i++)
			cout << " ";
		Gotoxy(15, 27);
	}
	cout << pt;
	Gotoxy(t.X, t.Y);
	if (kind >= 7)
	{
		pass++;
		bool ok = false;
		switch (kind)
		{
		case 7:
			if (pass == 30) ok = true;
			break;
		case 8:
			if (pass == 30) ok = true;
			break;
		case 9:
			if (pass == 25) ok = true;
			break;
		case 10:
			if (pass == 25) ok = true;
			break;
		case 11:
			if (pass == 20) ok = true;
			break;
		}
		if (ok) Make_Food('#', 3);
		else Increase_Process();
	}
}

bool isOK_Food(int a, int b)
{
	if (c[a][b] == 1) return false;
	for (int i = 0; i <= length; i++)
		if (a == x[i] && b == y[i]) return false;
	if (kind != 1)
		if (a < 20 || a>100 || b < 4 || b>24) return false;
	if (c[a][b] == 0) return true;
	else return false;
}

void Make_Food(char ch, int k)
{
	int x, y;
	srand((unsigned int)time(NULL));
	if (kind == 1)
	{
		do
		{
			x = rand() % (119 - 0 + 1) + 0;
			y = rand() % (19 - 0 + 1) + 0;
		} while (!isOK_Food(x, y));
	}
	else
	{
		do
		{
			x = rand() % (99 - 21 + 1) + 21;
			y = rand() % (22 - 4 + 1) + 4;
		} while (!isOK_Food(x, y));
	}
	c[x][y] = k;
	COORD t = GetConsoleCursorPosition();
	Gotoxy(x, y);
	int color = rand() % (15 - 1 + 1) + 1;
	ChangeColor(color);
	cout << ch;
	ChangeColor(14);
	Gotoxy(t.X, t.Y);
}

void Run()
{
	char direct = _getch();
	if (direct == -32) direct = _getch();
	switch (direct)
	{
	case 75:
		if (dir != 3) {
			Left();
			dir = 1;
		}
		break;
	case 72:
		if (dir != 4) {
			Up();
			dir = 2;
		}
		break;
	case 77:
		if (dir != 1) {
			Right();
			dir = 3;
		}
		break;
	case 80:
		if (dir != 2) {
			Down();
			dir = 4;
		}
		break;
	default:
		switch (dir)
		{
		case 1:
			Left();
			break;
		case 2:
			Up();
			break;
		case 3:
			Right();
			break;
		case 4:
			Down();
			break;
		}
	}
}

void End_Game()
{
	PlaySound(NULL, NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	system("cls");
	if (ok) Print(8, 12, 3, 7, "          YOU LOSE         ");
	else Print(11, 9, 2, 14, "          YOU WIN          ");
	system("cls");
	while (_kbhit())
	{
		int ch = _getch();
	}
	for (int i = 1; i <= 15; i++)
	{
		if (_kbhit()) break;
		Gotoxy(25, 5);
		ChangeColor(15);
		cout << "Your Score: ";
		ChangeColor(i);
		cout << pt;
		Sleep(300);
	}
	system("cls");
	FILE* g = NULL;
	switch (kind)
	{
	case 1:
		g = fopen("rank_classic.txt", "r");
		break;
	case 2:case 3:case 4:case 5:case 6:
		g = fopen("rank_modern.txt", "r");
		break;
	case 7:case 8:case 9:case 10:case 11:
		g = fopen("rank_campaign.txt", "r");
		break;
	}
	int a[5];
	for (int i = 0; i < 5; i++)
		fscanf(g, "%d", &a[i]);
	int i;
	while (_kbhit())
	{
		int ch = _getch();
	}
	for (i = 0; i < 5; i++)
		if (pt >= a[i] && pt > 0)
		{
			PlaySound(TEXT("Winning_sound.wav"), NULL, SND_FILENAME | SND_ASYNC);
			if (i == 0)	Print(7, 11, 2, 4, "        SNAKE MASTER       ");
			else Print(7, 11, 2, 4, "         HIGH SCORE        ");
			system("cls");
			break;
		}
	for (int j = 4; j > i; j--)
		if (j > 0) a[j] = a[j - 1];
	if (i < 5)
	{
		a[i] = pt;
		fclose(g);
		switch (kind)
		{
		case 1:
			g = fopen("rank_classic.txt", "w");
			break;
		case 2:case 3:case 4:case 5:case 6:
			g = fopen("rank_modern.txt", "w");
			break;
		case 7:case 8:case 9:case 10:case 11:
			g = fopen("rank_campaign.txt", "w");
			break;
		}
		for (int i = 0; i < 5; i++)
			fprintf(g, "%d\n", a[i]);
		fclose(g);
		ChangeColor(7);
		HighScores();
		for (int j = 0; j < 10; j++)
		{
			Gotoxy(37, 5 + i);
			cout << "      ";
			Sleep(100);
			Gotoxy(37, 5 + i);
			ChangeColor(4);
			cout << i + 1 << ". " << pt;
			Sleep(100);
		}
		while (!_kbhit())
		{
		}
		system("cls");
	}
}