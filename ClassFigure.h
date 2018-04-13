#pragma once
#ifndef ClassFigure
#define ClassFigure
#include "GlobalVariablesAndFunctions.h"

class Figure
{
private:
	char figureSign;
	void FigureRotation();
	void UndoMove();
	void GameOver();
	void GetPoints();
	void MoveFiguresDown(int);
	void DestroyFigures(int, int);
	Direction figureDirection[NUMBER_OF_FIGURES];
public:
	int score;
	Figure()
	{
		figureSign = '#';
		score = 0;
	}
	int figures[7][4] =//these are the figures coordinates 
	{	
		0, 1, 2, 3,
		0, 2, 3, 5,
		1, 3, 5, 7,
		1, 2, 3, 4,
		1, 3, 4, 5,
		1, 2, 3, 5,
		0, 1, 3, 5
	};
	struct Figurs
	{
		vector<int> X = vector<int>(4);//x coordinate
		vector<int> Y = vector<int>(4);//y coordinate
	};
	Figurs figure[NUMBER_OF_FIGURES];
	void DrawFigure(int, int, int, int);
	void DrawPreviousFigures(int, int);
	void GetKeyboardCommands();
	void DescribeFigureMovement();
	void FigureTouchTheWall();
	void FigureReachTheBottom();
	void FigureTouchOtherFigure();
	void Rules();
};

Figure aFigure;

#endif // !ClassFigure
