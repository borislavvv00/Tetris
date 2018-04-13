#pragma once
#ifndef FigureMovement
#define FigureMovement
#include "GlobalVariablesAndFunctions.h"
#include "ClassFigure.h"
#include "FiguresRotations.h"

void Figure::UndoMove()
{
	switch (figureDirection[figureNumber])
	{
	case Direction::down:
		for (int n = 0; n < figure[figureNumber].X.size(); n++)
		{
			figure[figureNumber].X[n]--;
		}
		break;
	case Direction::left:
		for (int n = 0; n < figure[figureNumber].X.size(); n++)
		{
			figure[figureNumber].X[n]--;
			figure[figureNumber].Y[n]++;
		}
		break;
	case Direction::right:
		for (int n = 0; n < figure[figureNumber].X.size(); n++)
		{
			figure[figureNumber].X[n]--;
			figure[figureNumber].Y[n]--;
		}
		break;
	}
}

void Figure::DescribeFigureMovement()
{
	switch (figureDirection[figureNumber])
	{
	case Direction::down:
		for (int n = 0; n < figure[figureNumber].X.size(); n++)
		{
			figure[figureNumber].X[n]++;
		}
		break;
	case Direction::left:
		for (int n = 0; n < figure[figureNumber].X.size(); n++)
		{
			figure[figureNumber].X[n]++;
			figure[figureNumber].Y[n]--;
		}
		break;
	case Direction::right:
		for (int n = 0; n < figure[figureNumber].X.size(); n++)
		{
			figure[figureNumber].X[n]++;
			figure[figureNumber].Y[n]++;
		}
		break;
	}
}

void Figure::GetKeyboardCommands()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 's':
			figureDirection[figureNumber] = Direction::down;
			Sleep(350);
			speedUp = true;
			break;
		case 'a':
			figureDirection[figureNumber] = Direction::left;
			speedUp = false;
			break;
		case 'd':
			figureDirection[figureNumber] = Direction::right;
			speedUp = false;
			break;
		case 'p':
			if (position == 3)
			{
				position = 0;
			}
			else
			{
				position++;
			}
			FigureRotation();
			break;
		}
	}
}

#endif // !FigureMovement
