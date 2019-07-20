#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include "Setup.h"
#include "Hieu_ung.h"
#include "Process.h"

using namespace std;

extern FILE* f;
extern int sp, pt, length, dir, kind, vip, pass, x[200], y[200];
extern float thoigian;
extern short c[200][100];
int k, c1, c2, t;

void Snake_Init()
{
	vip = 0;
	x[0] = 30;
	y[0] = 10;
	x[1] = 29;
	y[1] = 10;
	ChangeColor(14);
	Gotoxy(x[0], y[0]);
	cout << "X";
	Gotoxy(x[1], y[1]);
	cout << "O";
	ChangeColor(15);
	Make_Food('$', 2);
}

void Get_Data_And_Init()
{
	FixConsoleWindow();
	Nocursortype();
	fscanf(f, "%d", &t);
	if (t == 0) New_Game();
	else Resume_Game();
}

void Print(int a, int b, int c, int d, const char s[100])
{
	for (int i = 0; i < 10; i++)
	{
		if (_kbhit())
		{
			int ch = _getch();
			break;
		}
		if (i % 2 == 0) Print_Title(a, b, s);
		else Print_Title(c, d, s);
		Sleep(300);
	}
	Print_Title(14, 2, s);
}

void Select(int& k)
{
	ChangeColor(3);
	Gotoxy(30, 5);
	cout << "  New Game  ";
	Gotoxy(30, 6);
	cout << "  Level  ";
	Gotoxy(30, 7);
	cout << "  Game Type  ";
	Gotoxy(30, 8);
	cout << "  High Scores  ";
	Gotoxy(30, 9);
	cout << "  Instruction  ";
	ChangeColor(15);
	switch (k)
	{
	case 1:
		Gotoxy(30, 5);
		cout << "> New Game <";
		break;
	case 2:
		Gotoxy(30, 6);
		cout << "> Level <";
		break;
	case 3:
		Gotoxy(30, 7);
		cout << "> Game Type <";
		break;
	case 4:
		Gotoxy(30, 8);
		cout << "> High Scores <";
		break;
	case 5:
		Gotoxy(30, 9);
		cout << "> Instruction <";
		break;
	}
	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == 13)
			{
				ChangeColor(5);
				for (int i = 0; i < 5; i++)
				{
					switch (k)
					{
					case 1:
						Gotoxy(30, 5);
						cout << "                 ";
						Sleep(100);
						Gotoxy(30, 5);
						cout << "  New Game  ";
						Sleep(100);
						break;
					case 2:
						Gotoxy(30, 6);
						cout << "                 ";
						Sleep(100);
						Gotoxy(30, 6);
						cout << "  Level  ";
						Sleep(100);
						break;
					case 3:
						Gotoxy(30, 7);
						cout << "                 ";
						Sleep(100);
						Gotoxy(30, 7);
						cout << "  Game Type  ";
						Sleep(100);
						break;
					case 4:
						Gotoxy(30, 8);
						cout << "                 ";
						Sleep(100);
						Gotoxy(30, 8);
						cout << "  High Scores  ";
						Sleep(100);
						break;
					case 5:
						Gotoxy(30, 9);
						cout << "                 ";
						Sleep(100);
						Gotoxy(30, 9);
						cout << "  Instruction  ";
						Sleep(100);
						break;
					}
				}
				return;
			}
			if (ch == 72)
			{
				switch (k)
				{
				case 1:
					k = 5;
					break;
				case 2:
					k = 1;
					break;
				case 3:
					k = 2;
					break;
				case 4:
					k = 3;
					break;
				case 5:
					k = 4;
					break;
				}
				Select(k);
				return;
			}
			else if (ch == 80)
			{
				switch (k)
				{
				case 1:
					k = 2;
					break;
				case 2:
					k = 3;
					break;
				case 3:
					k = 4;
					break;
				case 4:
					k = 5;
					break;
				case 5:
					k = 1;
					break;
				}
				Select(k);
				return;
			}
		}
	}
}

void Select_Resume(int& k)
{
	ChangeColor(3);
	Gotoxy(30, 4);
	cout << "  Continue  ";
	Gotoxy(30, 5);
	cout << "  New Game  ";
	Gotoxy(30, 6);
	cout << "  Level  ";
	Gotoxy(30, 7);
	cout << "  Game Type  ";
	Gotoxy(30, 8);
	cout << "  High Scores  ";
	Gotoxy(30, 9);
	cout << "  Instruction  ";
	ChangeColor(15);
	switch (k)
	{
	case 0:
		Gotoxy(30, 4);
		cout << "> Continue <";
		break;
	case 1:
		Gotoxy(30, 5);
		cout << "> New Game <";
		break;
	case 2:
		Gotoxy(30, 6);
		cout << "> Level <";
		break;
	case 3:
		Gotoxy(30, 7);
		cout << "> Game Type <";
		break;
	case 4:
		Gotoxy(30, 8);
		cout << "> High Scores <";
		break;
	case 5:
		Gotoxy(30, 9);
		cout << "> Instruction <";
		break;
	}
	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == 13)
			{
				ChangeColor(5);
				for (int i = 0; i < 5; i++)
				{
					switch (k)
					{
					case 0:
						Gotoxy(30, 4);
						cout << "                 ";
						Sleep(100);
						Gotoxy(30, 4);
						cout << "  Continue  ";
						Sleep(100);
						break;
					case 1:
						Gotoxy(30, 5);
						cout << "                 ";
						Sleep(100);
						Gotoxy(30, 5);
						cout << "  New Game  ";
						Sleep(100);
						break;
					case 2:
						Gotoxy(30, 6);
						cout << "                 ";
						Sleep(100);
						Gotoxy(30, 6);
						cout << "  Level  ";
						Sleep(100);
						break;
					case 3:
						Gotoxy(30, 7);
						cout << "                 ";
						Sleep(100);
						Gotoxy(30, 7);
						cout << "  Game Type  ";
						Sleep(100);
						break;
					case 4:
						Gotoxy(30, 8);
						cout << "                 ";
						Sleep(100);
						Gotoxy(30, 8);
						cout << "  High Scores  ";
						Sleep(100);
						break;
					case 5:
						Gotoxy(30, 9);
						cout << "                 ";
						Sleep(100);
						Gotoxy(30, 9);
						cout << "  Instruction  ";
						Sleep(100);
						break;
					}
				}
				return;
			}
			if (ch == 72)
			{
				switch (k)
				{
				case 0:
					k = 5;
					break;
				case 1:
					k = 0;
					break;
				case 2:
					k = 1;
					break;
				case 3:
					k = 2;
					break;
				case 4:
					k = 3;
					break;
				case 5:
					k = 4;
					break;
				}
				Select_Resume(k);
				return;
			}
			else if (ch == 80)
			{
				switch (k)
				{
				case 0:
					k = 1;
					break;
				case 1:
					k = 2;
					break;
				case 2:
					k = 3;
					break;
				case 3:
					k = 4;
					break;
				case 4:
					k = 5;
					break;
				case 5:
					k = 0;
					break;
				}
				Select_Resume(k);
				return;
			}
		}
	}
}

void GameType()
{
	system("cls");
	Print(6, 2, 3, 15, "         GAME TYPE         ");
	ChangeColor(15);
	cout << "\n\t> 1. Classic <";
	ChangeColor(3);
	cout << "\n\t  2. Modern";
	cout << "\n\t  3. Campaign";
	kind = 1;
	Gotoxy(8, 5);
	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == 13) break;
			if (ch == 72)
			{
				switch (kind)
				{
				case 1:
					Gotoxy(8, 5);
					ChangeColor(3);
					cout << "  1. Classic  ";
					Gotoxy(8, 7);
					ChangeColor(15);
					cout << "> 3. Campaign <";
					kind = 7;
					break;
				case 2:
					Gotoxy(8, 6);
					ChangeColor(3);
					cout << "  2. Modern  ";
					Gotoxy(8, 5);
					ChangeColor(15);
					cout << "> 1. Classic <";
					kind = 1;
					break;
				case 7:
					Gotoxy(8, 7);
					ChangeColor(3);
					cout << "  3. Campaign  ";
					Gotoxy(8, 6);
					ChangeColor(15);
					cout << "> 2. Modern <";
					kind = 2;
					break;
				}
			}
			else if (ch == 80)
			{
				switch (kind)
				{
				case 1:
					Gotoxy(8, 5);
					ChangeColor(3);
					cout << "  1. Classic  ";
					Gotoxy(8, 6);
					ChangeColor(15);
					cout << "> 2. Modern <";
					kind = 2;
					break;
				case 2:
					Gotoxy(8, 6);
					ChangeColor(3);
					cout << "  2. Modern  ";
					Gotoxy(8, 7);
					ChangeColor(15);
					cout << "> 3. Campaign <";
					kind = 7;
					break;
				case 7:
					Gotoxy(8, 7);
					ChangeColor(3);
					cout << "  3. Campaign  ";
					Gotoxy(8, 5);
					ChangeColor(15);
					cout << "> 1. Classic <";
					kind = 1;
					break;
				}
			}
		}
	}
	ChangeColor(5);
	for (int i = 0; i < 5; i++)
	{
		switch (kind)
		{
		case 1:
			Gotoxy(8, 5);
			cout << "                 ";
			Sleep(100);
			Gotoxy(8, 5);
			cout << "  1. Classic  ";
			Sleep(100);
			break;
		case 2:
			Gotoxy(8, 6);
			cout << "                 ";
			Sleep(100);
			Gotoxy(8, 6);
			cout << "  2. Modern  ";
			Sleep(100);
			break;
		case 7:
			Gotoxy(8, 7);
			cout << "                 ";
			Sleep(100);
			Gotoxy(8, 7);
			cout << "  3. Campaign  ";
			Sleep(100);
			break;
		}
	}
	system("cls");
}

void HighScores()
{
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
	int a;
	Gotoxy(23, 5);
	ChangeColor(3);
	cout << "High Scores :";
	for (int i = 0; i < 5; i++)
	{
		fscanf(g, "%d", &a);
		Gotoxy(37, 5 + i);
		ChangeColor(15);
		cout << i + 1 << ". " << a;
	}
	fclose(g);
}

void Instruction()
{
	system("cls");
	ChangeColor(15);
	Gotoxy(20, 5);
	cout << "- Use Left Arrow, Up Arrow, Right Arrow and Down Arrow to move snake.";
	Sleep(500);
	Gotoxy(20, 7);
	cout << "- Control the snake to eat food and make it longer. The longer snake is, the more your point is.";
	Sleep(500);
	Gotoxy(20, 9);
	cout << "- You can choose snake's speed, game type. Default speed is Fast and Default Game type is Classic.";
	Sleep(500);
	Gotoxy(20, 11);
	cout << "- Note: + The higer snake's speed is, the more your point is";
	Gotoxy(20, 12);
	cout << "        + If you want to pause game, Press 'P'";
	Gotoxy(20, 13);
	cout << "        + If you want to resume game, Press any key";
	Gotoxy(20, 14);
	cout << "        + If you want to exit game, Press 'Esc'";
	while (!_kbhit())
	{
	}
	while (_kbhit())
	{
		char ch = _getch();
	}
	system("cls");
}

void Speed()
{
	system("cls");
	Print(7, 11, 5, 12, "           SPEED           ");
	ChangeColor(15);
	cout << "\n\t> 1. Extra Slow <";
	ChangeColor(3);
	cout << "\n\t  2. Slow";
	cout << "\n\t  3. Medium";
	cout << "\n\t  4. Fast";
	cout << "\n\t  5. Extra Fast";
	sp = 1;
	Gotoxy(8, 5);
	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == 13) break;
			if (ch == 72)
			{
				switch (sp)
				{
				case 1:
					Gotoxy(8, 5);
					ChangeColor(3);
					cout << "  1. Extra Slow  ";
					Gotoxy(8, 9);
					ChangeColor(15);
					cout << "> 5. Extra Fast <";
					sp = 5;
					break;
				case 2:
					Gotoxy(8, 6);
					ChangeColor(3);
					cout << "  2. Slow  ";
					Gotoxy(8, 5);
					ChangeColor(15);
					cout << "> 1. Extra Slow <";
					sp = 1;
					break;
				case 3:
					Gotoxy(8, 7);
					ChangeColor(3);
					cout << "  3. Medium  ";
					Gotoxy(8, 6);
					ChangeColor(15);
					cout << "> 2. Slow <";
					sp = 2;
					break;
				case 4:
					Gotoxy(8, 8);
					ChangeColor(3);
					cout << "  4. Fast  ";
					Gotoxy(8, 7);
					ChangeColor(15);
					cout << "> 3. Medium <";
					sp = 3;
					break;
				case 5:
					Gotoxy(8, 9);
					ChangeColor(3);
					cout << "  5. Extra Fast  ";
					Gotoxy(8, 8);
					ChangeColor(15);
					cout << "> 4. Fast <";
					sp = 4;
					break;
				}
			}
			else if (ch == 80)
			{
				switch (sp)
				{
				case 1:
					Gotoxy(8, 5);
					ChangeColor(3);
					cout << "  1. Extra Slow  ";
					Gotoxy(8, 6);
					ChangeColor(15);
					cout << "> 2. Slow <";
					sp = 2;
					break;
				case 2:
					Gotoxy(8, 6);
					ChangeColor(3);
					cout << "  2. Slow  ";
					Gotoxy(8, 7);
					ChangeColor(15);
					cout << "> 3. Medium <";
					sp = 3;
					break;
				case 3:
					Gotoxy(8, 7);
					ChangeColor(3);
					cout << "  3. Medium  ";
					Gotoxy(8, 8);
					ChangeColor(15);
					cout << "> 4. Fast <";
					sp = 4;
					break;
				case 4:
					Gotoxy(8, 8);
					ChangeColor(3);
					cout << "  4. Fast  ";
					Gotoxy(8, 9);
					ChangeColor(15);
					cout << "> 5. Extra Fast <";
					sp = 5;
					break;
				case 5:
					Gotoxy(8, 9);
					ChangeColor(3);
					cout << "  5. Extra Fast  ";
					Gotoxy(8, 5);
					ChangeColor(15);
					cout << "> 1. Extra Slow <";
					sp = 1;
					break;
				}
			}
		}
	}
	ChangeColor(5);
	for (int i = 0; i < 5; i++)
	{
		switch (sp)
		{
		case 1:
			Gotoxy(8, 5);
			cout << "                 ";
			Sleep(100);
			Gotoxy(8, 5);
			cout << "  1. Extra Slow  ";
			Sleep(100);
			break;
		case 2:
			Gotoxy(8, 6);
			cout << "                 ";
			Sleep(100);
			Gotoxy(8, 6);
			cout << "  2. Slow  ";
			Sleep(100);
			break;
		case 3:
			Gotoxy(8, 7);
			cout << "                 ";
			Sleep(100);
			Gotoxy(8, 7);
			cout << "  3. Medium  ";
			Sleep(100);
			break;
		case 4:
			Gotoxy(8, 8);
			cout << "                 ";
			Sleep(100);
			Gotoxy(8, 8);
			cout << "  4. Fast  ";
			Sleep(100);
			break;
		case 5:
			Gotoxy(8, 9);
			cout << "                 ";
			Sleep(100);
			Gotoxy(8, 9);
			cout << "  5. Extra Fast  ";
			Sleep(100);
			break;
		}
	}
	ChangeColor(15);
	system("cls");
}

void New_Game()
{
	k = 1;
	while (true)
	{
		Select(k);
		switch (k)
		{
		case 1:
			system("cls");
			switch (kind)
			{
			case 1: Classic();
				break;
			case 2: Modern();
				break;
			case 7: Campaign();
				break;
			}
			Snake_Init();
			return;
		case 2: Speed();
			break;
		case 3: GameType();
			break;
		case 4:
			system("cls");
			Print(7, 11, 2, 4, "        HIGH SCORES        ");
			HighScores();
			while (!_kbhit())
			{
			}
			system("cls");
			while (_kbhit())
			{
				char ch = _getch();
			}
			break;
		case 5:
			Instruction();
			break;
		default:
			break;
		}
	}
}

void Resume_Game()
{
	k = 0;
	while (true)
	{
		Select_Resume(k);
		switch (k)
		{
		case 0:
			system("cls");
			fscanf(f, "%d%d%d%d%d%d%f", &kind, &sp, &pt, &dir, &length, &vip, &thoigian);
			switch (kind)
			{
			case 1: Classic();
				break;
			case 2:case 3:case 4:case 5:case 6:
				Modern();
				break;
			case 7:case 8:case 9:case 10:case 11:
				fscanf(f, "%d", &pass);
				Check();
				Campaign();
				break;
			}
			ChangeColor(14);
			fscanf(f, "%d%d", &x[0], &y[0]);
			Gotoxy(x[0], y[0]);
			cout << "X";
			for (int i = 1; i < length; i++)
			{
				fscanf(f, "%d%d", &x[i], &y[i]);
				Gotoxy(x[i], y[i]);
				cout << "O";
			}
			switch (kind)
			{
			case 7:
				if (pass == 40) Make_Food('#', 3);
				break;
			case 8:
				if (pass == 35) Make_Food('#', 3);
				break;
			case 9:
				if (pass == 30) Make_Food('#', 3);
				break;
			case 10:
				if (pass == 25) Make_Food('#', 3);
				break;
			case 11:
				if (pass == 20) Make_Food('#', 3);
				break;
			}
			Make_Food('$', 2);
			if (thoigian > 0) Make_Food('@', 4);
			while (!_kbhit())
			{
			}
			return;
		case 1:
			system("cls");
			switch (kind)
			{
			case 1: Classic();
				break;
			case 2: Modern();
				break;
			case 7: Campaign();
				break;
			}
			Snake_Init();
			return;
		case 2: Speed();
			break;
		case 3: GameType();
			break;
		case 4:
			system("cls");
			Print(7, 11, 2, 4, "        HIGH SCORES        ");
			HighScores();
			while (!_kbhit())
			{
			}
			system("cls");
			while (_kbhit())
			{
				char ch = _getch();
			}
			break;
		case 5:
			Instruction();
			break;
		default:
			break;
		}
	}
}

void Classic()
{
	Print(8, 2, 14, 7, "       CLASSIC MODE        ");
	system("cls");
	Gotoxy(0, 20);
	ChangeColor(8);
	for (int i = 0; i < 120; i++) cout << "_";
	ChangeColor(15);
	cout << "\n\n\tScore: " << pt;
}

void Select_Modern()
{
	Gotoxy(30, 5);
	ChangeColor(15);
	cout << "> 1. Box <";
	ChangeColor(3);
	Gotoxy(30, 6);
	cout << "  2. Tunnel";
	Gotoxy(30, 7);
	cout << "  3. Mill";
	Gotoxy(30, 8);
	cout << "  4. Rails";
	Gotoxy(30, 9);
	cout << "  5. Apartment";
	kind = 2;
	Gotoxy(8, 5);
	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == 13) break;
			if (ch == 72)
			{
				switch (kind)
				{
				case 2:
					Gotoxy(30, 5);
					ChangeColor(3);
					cout << "  1. Box  ";
					Gotoxy(30, 9);
					ChangeColor(15);
					cout << "> 5. Apartment <";
					kind = 6;
					break;
				case 3:
					Gotoxy(30, 6);
					ChangeColor(3);
					cout << "  2. Tunnel  ";
					Gotoxy(30, 5);
					ChangeColor(15);
					cout << "> 1. Box <";
					kind = 2;
					break;
				case 4:
					Gotoxy(30, 7);
					ChangeColor(3);
					cout << "  3. Mill  ";
					Gotoxy(30, 6);
					ChangeColor(15);
					cout << "> 2. Tunnel <";
					kind = 3;
					break;
				case 5:
					Gotoxy(30, 8);
					ChangeColor(3);
					cout << "  4. Rails  ";
					Gotoxy(30, 7);
					ChangeColor(15);
					cout << "> 3. Mill <";
					kind = 4;
					break;
				case 6:
					Gotoxy(30, 9);
					ChangeColor(3);
					cout << "  5. Apartment  ";
					Gotoxy(30, 8);
					ChangeColor(15);
					cout << "> 4. Rails <";
					kind = 5;
					break;
				}
			}
			else if (ch == 80)
			{
				switch (kind)
				{
				case 2:
					Gotoxy(30, 5);
					ChangeColor(3);
					cout << "  1. Box  ";
					Gotoxy(30, 6);
					ChangeColor(15);
					cout << "> 2. Tunnel <";
					kind = 3;
					break;
				case 3:
					Gotoxy(30, 6);
					ChangeColor(3);
					cout << "  2. Tunnel  ";
					Gotoxy(30, 7);
					ChangeColor(15);
					cout << "> 3. Mill <";
					kind = 4;
					break;
				case 4:
					Gotoxy(30, 7);
					ChangeColor(3);
					cout << "  3. Mill  ";
					Gotoxy(30, 8);
					ChangeColor(15);
					cout << "> 4. Rails <";
					kind = 5;
					break;
				case 5:
					Gotoxy(30, 8);
					ChangeColor(3);
					cout << "  4. Rails  ";
					Gotoxy(30, 9);
					ChangeColor(15);
					cout << "> 5. Apartment <";
					kind = 6;
					break;
				case 6:
					Gotoxy(30, 9);
					ChangeColor(3);
					cout << "  5. Apartment  ";
					Gotoxy(30, 5);
					ChangeColor(15);
					cout << "> 1. Box <";
					kind = 2;
					break;
				}
			}
		}
	}
	ChangeColor(5);
	for (int i = 0; i < 5; i++)
	{
		switch (kind)
		{
		case 2:
			Gotoxy(30, 5);
			cout << "                 ";
			Sleep(100);
			Gotoxy(30, 5);
			cout << "  1. Box  ";
			Sleep(100);
			break;
		case 3:
			Gotoxy(30, 6);
			cout << "                 ";
			Sleep(100);
			Gotoxy(30, 6);
			cout << "  2. Tunnel  ";
			Sleep(100);
			break;
		case 4:
			Gotoxy(30, 7);
			cout << "                 ";
			Sleep(100);
			Gotoxy(30, 7);
			cout << "  3. Mill  ";
			Sleep(100);
			break;
		case 5:
			Gotoxy(30, 8);
			cout << "                 ";
			Sleep(100);
			Gotoxy(30, 8);
			cout << "  4. Rails  ";
			Sleep(100);
			break;
		case 6:
			Gotoxy(30, 9);
			cout << "                 ";
			Sleep(100);
			Gotoxy(30, 9);
			cout << "  5. Apartment  ";
			Sleep(100);
			break;
		}
	}
	ChangeColor(15);
	system("cls");
}

void Color(int& temp)
{
	if (temp == 1)
	{
		swap(c1, c2);
		temp = 0;
	}
	else temp++;
	ChangeColor(c1);
}

void Box()
{
	Print(3, 4, 2, 14, "            BOX            ");
	system("cls");
	ChangeColor(3);
	Gotoxy(20, 4);
	for (int i = 0; i <= 80; i++)
	{
		cout << (char)219;
		c[i + 20][4] = 1;
	}
	for (int i = 0; i <= 20; i++)
	{
		Gotoxy(20, 4 + i);
		cout << (char)219;
		c[20][4 + i] = 1;
		Gotoxy(100, 4 + i);
		c[100][4 + i] = 1;
		cout << (char)219;
	}
	Gotoxy(20, 24);
	for (int i = 0; i <= 80; i++)
	{
		cout << (char)219;
		c[i + 20][24] = 1;
	}
}

void Tunnel()
{
	Print(3, 4, 2, 14, "           TUNNEL          ");
	system("cls");
	Gotoxy(20, 4);
	int temp = -1;
	c1 = 4; c2 = 15;
	for (int i = 0; i <= 5; i++)
	{
		Color(temp);
		cout << (char)219;
		c[i + 20][4] = 1;
	}
	Gotoxy(20, 5);
	for (int i = 0; i <= 1; i++)
	{
		Gotoxy(20, 5 + i);
		for (int j = 0; j <= 1; j++)
		{
			Color(temp);
			cout << (char)219;
			c[20 + j][5 + i] = 1;
		}
	}
	//----------------------------------
	temp = -1;
	Gotoxy(95, 4);
	for (int i = 0; i <= 5; i++)
	{
		Color(temp);
		cout << (char)219;
		c[100 - i][4] = 1;
	}
	Gotoxy(99, 5);
	for (int i = 0; i <= 1; i++)
	{
		Gotoxy(99, 5 + i);
		for (int j = 0; j <= 1; j++)
		{
			Color(temp);
			cout << (char)219;
			c[100 - j][5 + i] = 1;
		}
	}
	//----------------------------------
	temp = -1;
	Gotoxy(20, 24);
	for (int i = 0; i <= 5; i++)
	{
		Color(temp);
		cout << (char)219;
		c[i + 20][24] = 1;
	}
	Gotoxy(20, 23);
	for (int i = 0; i <= 1; i++)
	{
		Gotoxy(20, 23 - i);
		for (int j = 0; j <= 1; j++)
		{
			Color(temp);
			cout << (char)219;
			c[20 + j][23 - i] = 1;
		}
	}
	//----------------------------------
	temp = -1;
	Gotoxy(95, 24);
	for (int i = 0; i <= 5; i++)
	{
		Color(temp);
		cout << (char)219;
		c[100 - i][24] = 1;
	}
	Gotoxy(99, 23);
	for (int i = 0; i <= 1; i++)
	{
		Gotoxy(99, 23 - i);
		for (int j = 0; j <= 1; j++)
		{
			Color(temp);
			cout << (char)219;
			c[100 - j][23 - i] = 1;
		}
	}
	//----------------------------------
	temp = -1;
	Gotoxy(40, 12);
	for (int i = 0; i < 40; i++)
	{
		Color(temp);
		cout << (char)219;
		c[40 + i][12] = 1;
	}
	//----------------------------------
	temp = -1;
	Gotoxy(40, 16);
	for (int i = 0; i < 40; i++)
	{
		Color(temp);
		cout << (char)219;
		c[40 + i][16] = 1;
	}
	//----------------------------------
}

void Mill()
{
	Print(3, 4, 2, 14, "            MILL           ");
	system("cls");
	c1 = 2; c2 = 15;
	int temp = -1;
	for (int i = 0; i < 12; i++)
	{
		Gotoxy(46, 4 + i);
		for (int j = 0; j <= 1; j++)
		{
			Color(temp);
			Gotoxy(46 + j, 4 + i);
			cout << (char)219;
			c[46 + j][4 + i] = 1;
		}
	}
	//----------------------------------
	temp = -1;
	for (int i = 0; i < 12; i++)
	{
		Gotoxy(73, 24 - i);
		for (int j = 0; j <= 1; j++)
		{
			Color(temp);
			Gotoxy(73 + j, 24 - i);
			cout << (char)219;
			c[73 + j][24 - i] = 1;
		}
	}
	//----------------------------------
	temp = -1;
	for (int i = 0; i < 28; i++)
	{
		Gotoxy(20 + i, 20);
		Color(temp);
		cout << (char)219;
		c[20 + i][20] = 1;
	}
	//----------------------------------
	temp = -1;
	for (int i = 0; i < 28; i++)
	{
		Gotoxy(73 + i, 8);
		Color(temp);
		cout << (char)219;
		c[73 + i][8] = 1;
	}
	//----------------------------------
}

void Rails()
{
	Print(3, 4, 2, 14, "           RAILS           ");
	system("cls");
	int temp = -1;
	c1 = 8; c2 = 15;
	Gotoxy(20, 4);
	for (int i = 0; i <= 80; i++)
	{
		Color(temp);
		cout << (char)219;
		c[i + 20][4] = 1;
	}
	//----------------------------------
	temp = -1;
	for (int i = 0; i <= 7; i++)
	{
		Color(temp);
		Gotoxy(20, 4 + i);
		cout << (char)219;
		c[20][4 + i] = 1;
		Gotoxy(100, 4 + i);
		c[100][4 + i] = 1;
		Color(temp);
		cout << (char)219;
	}
	//----------------------------------
	temp = -1;
	for (int i = 13; i <= 20; i++)
	{
		Gotoxy(20, 4 + i);
		Color(temp);
		cout << (char)219;
		c[20][4 + i] = 1;
		Gotoxy(100, 4 + i);
		c[100][4 + i] = 1;
		Color(temp);
		cout << (char)219;
	}
	//----------------------------------
	temp = -1;
	Gotoxy(20, 24);
	for (int i = 0; i <= 80; i++)
	{
		Color(temp);
		cout << (char)219;
		c[i + 20][24] = 1;
	}
	//----------------------------------
	temp = -1;
	Gotoxy(40, 9);
	for (int i = 0; i < 40; i++)
	{
		Color(temp);
		cout << (char)219;
		c[40 + i][9] = 1;
	}
	//----------------------------------
	temp = -1;
	Gotoxy(40, 19);
	for (int i = 0; i < 40; i++)
	{
		Color(temp);
		cout << (char)219;
		c[40 + i][19] = 1;
	}
	//----------------------------------
}

void Apartment()
{
	Print(3, 4, 2, 14, "         APARTMENT         ");
	system("cls");
	c1 = 5; c2 = 15;
	int temp = -1;
	Gotoxy(20, 12);
	for (int i = 0; i <= 80; i++)
		if (i < 38 || i > 43)
		{
			Color(temp);
			cout << (char)219;
			c[20 + i][12] = 1;
		}
		else
		{
			cout << " ";
			Color(temp);
		}
	//----------------------------------
	temp = -1;
	Gotoxy(20, 16);
	for (int i = 0; i <= 80; i++)
	{
		Color(temp);
		cout << (char)219;
		c[20 + i][16] = 1;
	}
	//----------------------------------
	temp = -1;
	Color(temp); Color(temp);
	for (int i = 0; i <= 7; i++)
	{
		Gotoxy(64, 17 + i);
		Color(temp);
		cout << (char)219 << (char)219;
		c[64][17 + i] = 1;
		Color(temp);
		c[65][17 + i] = 1;
	}
	//----------------------------------
	temp = -1;
	Color(temp); Color(temp);
	for (int i = 0; i <= 6; i++)
	{
		Gotoxy(56, 5 + i);
		Color(temp);
		cout << (char)219 << (char)219;
		c[56][5 + i] = 1;
		Color(temp);
		c[57][5 + i] = 1;
	}
	//----------------------------------
	temp = -1;
	//Color(temp); Color(temp);
	for (int i = 0; i <= 4; i++)
	{
		Gotoxy(20, 5 + i);
		Color(temp);
		cout << (char)219 << (char)219;
		c[20][5 + i] = 1;
		Color(temp);
		c[21][5 + i] = 1;
	}
	//----------------------------------
	temp = -1;
	Gotoxy(20, 4);
	Color(temp); Color(temp);
	for (int i = 0; i <= 59; i++)
		if (i < 12 || i > 17)
		{
			Color(temp);
			cout << (char)219;
			c[20 + i][4] = 1;
		}
		else
		{
			cout << " ";
			Color(temp);
		}
	//----------------------------------
}

void Modern()
{
	Print(5, 8, 2, 14, "        MODERN MODE        ");
	system("cls");
	if (k != 0) Select_Modern();
	switch (kind)
	{
	case 2:
		Box();
		break;
	case 3:
		Tunnel();
		break;
	case 4:
		Mill();
		break;
	case 5:
		Rails();
		break;
	case 6:
		Apartment();
		break;
	}
	switch (kind)
	{
	case 2:
		ChangeColor(3);
		break;
	case 3:
		ChangeColor(4);
		break;
	case 4:
		ChangeColor(2);
		break;
	case 5:
		ChangeColor(8);
		break;
	case 6:
		ChangeColor(5);
		break;
	}
	Gotoxy(18, 3);
	for (int i = 0; i <= 84; i++)
	{
		cout << (char)176;
		c[i + 18][3] = 1;
	}
	for (int i = 0; i <= 22; i++)
	{
		Gotoxy(18, 3 + i);
		cout << (char)176 << (char)176;
		c[18][3 + i] = 1;
		Gotoxy(101, 3 + i);
		c[101][3 + i] = 1;
		cout << (char)176 << (char)176;
	}
	Gotoxy(18, 25);
	for (int i = 0; i <= 84; i++)
	{
		cout << (char)176;
		c[i + 18][25] = 1;
	}
	ChangeColor(15);
	cout << "\n\n\tScore: " << pt;
}

void Campaign()
{
	if (kind == 7) Print(11, 9, 2, 14, "       CAMPAIGN MODE       ");
	system("cls");
	if (t == 0)
	{
		pass = 0;
		vip = 0;
		length = 1;
		for (int i = 20; i <= 100; i++)
			for (int j = 4; j <= 24; j++)
				c[i][j] = 0;
	}
	int temp = 0;
	switch (kind)
	{
	case 7:
		Box();
		ChangeColor(3);
		temp = 30;
		break;
	case 8:
		Tunnel();
		ChangeColor(4);
		temp = 30;
		break;
	case 9:
		Mill();
		ChangeColor(2);
		temp = 25;
		break;
	case 10:
		Rails();
		ChangeColor(8);
		temp = 25;
		break;
	case 11:
		Apartment();
		ChangeColor(5);
		temp = 20;
		break;
	}
	Gotoxy(18, 3);
	for (int i = 0; i <= 84; i++)
	{
		cout << (char)176;
		c[i + 18][3] = 1;
	}
	for (int i = 0; i <= 22; i++)
	{
		Gotoxy(18, 3 + i);
		cout << (char)176 << (char)176;
		c[18][3 + i] = 1;
		Gotoxy(101, 3 + i);
		c[101][3 + i] = 1;
		cout << (char)176 << (char)176;
	}
	Gotoxy(18, 25);
	for (int i = 0; i <= 84; i++)
	{
		cout << (char)176;
		c[i + 18][25] = 1;
	}
	Gotoxy(39, 27);
	for (int i = 0; i < temp; i++)
		cout << (char)176;
	Gotoxy(39, 27);
	for (int i = 0; i < pass; i++)
		cout << (char)219;
	Gotoxy(8, 27);
	ChangeColor(15);
	cout << "Score: " << pt;
	Gotoxy(30, 27);
	cout << "Process: ";
	if (kind > 7)
	{
		Make_Food('$', 2);
		while (!_kbhit())
		{
		}
		char ch = _getch();
	}
	if (t != 0) t = 0;
}