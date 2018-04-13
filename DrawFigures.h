#pragma once
#ifndef DrawFigures
#define DrawFigures
#include "ClassFigure.h"
#include "ClassMap.h"

void Figure::DrawFigure(int i, int j, int color, int figureNumber)
{
	for (int n = 0; n < figure[figureNumber].X.size(); n++) //for all figure's parts x and y coordinates 
	{
		if (i == figure[figureNumber].X[n] && j == figure[figureNumber].Y[n])
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
			cout << figureSign;
			printSpaces = false;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); //change color to white
		}
	}
}

void Figure::DrawPreviousFigures(int i, int j)
{
	for (int k = 0; k < figureNumber; k++) //for previous figures
	{
		aMap.ChooseFigure(shape[k], i, j, k);
	}
}

#endif // !FigureFunctions
