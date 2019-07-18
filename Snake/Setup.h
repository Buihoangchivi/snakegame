#pragma once
#ifndef _MY_SETUP
#define _MY_SETUP

void Snake_Init();
void Get_Data_And_Init();
void Resume_Game();
void New_Game();
void Classic();
void Modern();
void Campaign();
void Speed();
void Print(int a, int b, int c, int d, const char s[100]);
void HighScores();
void Select(int& k);
void Select_Resume(int& k);
void Select_Modern();
void GameType();
void Instruction();
void Color(int& temp);
void Box();
void Tunnel();
void Mill();
void Rails();
void Apartment();

#endif
