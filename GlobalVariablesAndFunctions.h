#pragma once
#ifndef GlobalVariablesAndFunctions
#define GlobalVariablesAndFunctions
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <time.h>
#include <stddef.h>
#define WIDTH 20
#define HIHG 20
#define NUMBER_OF_FIGURES 100

using namespace std;

vector<int> shape;//there are 7 different figures
int figureNumber = -1; // count figures and is used to show curent figure
int position = 0;//there are 4 rotate position of each figure
bool printSpaces;// to print or not space 
bool dropFigure = true;//to drop the next figure
bool gameOver = false;
bool speedUp = false;//to speed up the game when 's' is pressed

enum class Direction
{
	down, left, right
};

void ClearSreen()
{
	COORD cursorPosition;
	cursorPosition.Y = 0;
	cursorPosition.X = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

#endif // !GlobalVariablesAndFunctions

