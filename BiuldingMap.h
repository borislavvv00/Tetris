#pragma once
#ifndef BiuldingMap
#define BiuldingMap
#include "ClassMap.h"
#include "DrawFigures.h"
#include "FigureMovement.h"

void Map::TrowFigure(int i, int j)
{
	if (dropFigure == true)
	{
		figureNumber++;
		shape.push_back(rand() % 7); //randomly set a figure shape
		for (int n = 0; n < aFigure.figure[figureNumber].X.size(); n++) // used to set curent figure coordinates
		{
			aFigure.figure[figureNumber].X[n] = aFigure.figures[shape[figureNumber]][n] % 2;
			aFigure.figure[figureNumber].Y[n] = aFigure.figures[shape[figureNumber]][n] / 2 + WIDTH / 2;
		}
		dropFigure = false;
	}
	ChooseFigure(shape[figureNumber], i, j, figureNumber);
}

void Map::ChooseFigure(int shape, int i, int j, int figureNumber)
{
	switch (shape)
	{
	case 0:
		aFigure.DrawFigure(i, j, 9, figureNumber);
		break;
	case 1:
		aFigure.DrawFigure(i, j, 10, figureNumber);
		break;
	case 2:
		aFigure.DrawFigure(i, j, 11, figureNumber);
		break;
	case 3:
		aFigure.DrawFigure(i, j, 12, figureNumber);
		break;
	case 4:
		aFigure.DrawFigure(i, j, 13, figureNumber);
		break;
	case 5:
		aFigure.DrawFigure(i, j, 14, figureNumber);
		break;
	case 6:
		aFigure.DrawFigure(i, j, 15, figureNumber);
		break;
	}
}

void Map::DrawMap()
{
	for (int i = 0; i < HIHG; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			printSpaces = true;
			TrowFigure(i, j);
			aFigure.DrawPreviousFigures(i, j);
			if (j == 0 || j == WIDTH - 1 || i == HIHG - 1)
			{
				cout << wallSign;
			}
			else if (printSpaces == true)
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	cout << "Score = " << aFigure.score << endl;
}

#endif // !BiuldingMap
