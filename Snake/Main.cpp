#include <iostream>
#include "Setup.h"
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <thread>
#include "Process.h"
#include "Hieu_ung.h"
#define fi "Data.txt"
using namespace std;

FILE* f;
int sp = 4, pt = 0, length = 1, dir = 3, kind = 7, vip = 0, pass, x[200], y[200], xx, yy;
float thoigian = -1;
short c[200][100];

int main()
{
	f = fopen(fi, "r");
	Get_Data_And_Init();
	ChangeColor(14);
	while (!_kbhit())
	{
	}
	srand((unsigned int)time(NULL));
	int x;
	x = rand() % (3 - 1 + 1) + 1;
	switch (x)
	{
	case 1:
		PlaySound(TEXT("senorita.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
		break;
	case 2:
		PlaySound(TEXT("Faded.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
		break;
	case 3:
		PlaySound(TEXT("Despacito.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
		break;
	}
	while (true)
	{
		while (!_kbhit())
		{
			switch (dir)
			{
			case 1: Left();
				break;
			case 2: Up();
				break;
			case 3: Right();
				break;
			case 4: Down();
				break;
			}
			switch (sp)
			{
			case 1: Sleep(650);
				break;
			case 2: Sleep(400);
				break;
			case 3: Sleep(200);
				break;
			case 4: Sleep(100);
				break;
			case 5: Sleep(50);
				break;
			}
			if (!Check())
			{
				End_Game();
				ChangeColor(15);
				fclose(f);
				f = fopen(fi, "w");
				fprintf(f, "0");
				fclose(f);
				return 0;
			}
		}
		Run();
		if (!Check())
		{
			End_Game();
			ChangeColor(15);
			fclose(f);
			f = fopen(fi, "w");
			fprintf(f, "0");
			fclose(f);
			return 0;
		}
	}
	fclose(f);
	f = fopen(fi, "w");
	fprintf(f, "0");
	fclose(f);
	return 0;
}