#include <iostream>
#include "BiuldingMap.h"
#include "GlobalVariablesAndFunctions.h"
#include "FigureBehavior.h"

int main()
{
	srand(time(0));
	while (!gameOver)
	{
		aMap.DrawMap();
		aFigure.DescribeFigureMovement();
		aFigure.GetKeyboardCommands();
		aFigure.FigureReachTheBottom();
		aFigure.FigureTouchTheWall();
		aFigure.Rules();
		aFigure.FigureTouchOtherFigure();
		ClearSreen();
		Sleep(300);
	}
	return 0;
}
