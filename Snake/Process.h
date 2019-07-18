#pragma once
#ifndef _MY_PROCESS
#define _MY_PROCESS

void Run();
void Left();
void Up();
void Right();
void Down();
bool Check();
void Make_Food(char ch, int k);
void End_Game();
void Add_Tail(int a, int b);
void Increase_Process();
void Increase_Point(int k, float n);
DWORD WINAPI ThreadProc(LPVOID param);
void Save_Game();

#endif // !_MY_PROCESS

