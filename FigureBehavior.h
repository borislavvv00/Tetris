#pragma once 
#ifndef FigureBehavior
#define FigureBehavior
#include "FigureMovement.h"
#include "DrawFigures.h"
#include "ClassMap.h"

void Figure::FigureReachTheBottom()
{
	for (int m = 0; m < figure[figureNumber].X.size(); m++)
	{
		if (figure[figureNumber].X[m] == HIHG - 1) //if one of the figure's parts touch the bottom border
		{
			//--------------------------------------------------------------
			for (int n = 0; n < figure[figureNumber].X.size(); n++) 
			{
				figure[figureNumber].X[n]--; //all parts go one up
				for (int r = 0; r < HIHG; r++)
				{
					if (figure[figureNumber].X[n] == r)
					{
						aMap.row[r].numberOfElements++;
					}
				}
			}
			//---------------------------------------------------------------
			dropFigure = true;
			position = 0;
		}
	}
}

void Figure::FigureTouchTheWall()
{
	for (int n = 0; n < figure[figureNumber].Y.size(); n++)
	{
		if (figure[figureNumber].Y[n] == WIDTH - 2) //rigth border
		{
			figureDirection[figureNumber] = Direction::down;
		}
		else if (figure[figureNumber].Y[n] == 1) //left border
		{
			figureDirection[figureNumber] = Direction::down;
		}
	}
}

void Figure::FigureTouchOtherFigure()
{
	for (int k = 0; k < figureNumber; k++) //for previous figures
	{
		for (int n = 0; n < figure[figureNumber].Y.size(); n++) //the current figure parts
		{
			for (int m = 0; m < figure[k].Y.size(); m++) //the previous figures parts
			{
				if (figure[k].Y[m] == figure[figureNumber].Y[n] && figure[k].X[m] == figure[figureNumber].X[n])
				{
					UndoMove();
					if (figure[figureNumber].X[n] + 1 == figure[k].X[m] && figure[k].Y[m] == figure[figureNumber].Y[n])
					{
						dropFigure = true;
						position = 0; // set start position for the new figure
						speedUp = false;
					}
					else
					{
						figureDirection[figureNumber] = Direction::down;
					}
				}
			}
		}
	}
}

void Figure::GameOver()
{
	for (int k = 0; k < figureNumber; k++)
	{
		for (int n = 0; n < figure[k].X.size(); n++)
		{
			if (figure[k].X[n] < 0)
			{
				gameOver = true;
				cout << "Game Over" << endl;
			}
		}
	}
}

void Figure::MoveFiguresDown(int figureNumber)
{
	for (int n = 0; n < figure[figureNumber].X.size(); n++)
	{
		figure[figureNumber].X[n]++;
		for (int r = 0; r < HIHG; r++)
		{
			if (figure[figureNumber].X[n] == r)
			{
				aMap.row[r].numberOfElements++;
			}
		}
	}
}

void Figure::DestroyFigures(int figureNumber, int row)
{
	for (int n = 0; n < figure[figureNumber].X.size(); n++)
	{
		if (figure[figureNumber].X[n] == row)//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
		{
			figure[figureNumber].X.erase(figure[figureNumber].X.begin() + n);
			figure[figureNumber].Y.erase(figure[figureNumber].Y.begin() + n);
			n = -1;
		}
	}
}

void Figure::GetPoints()
{
	for (int r = 0; r < HIHG; r++)
	{
		if (aMap.row[r].numberOfElements == 8 /*WIDTH - 2*/)
		{
			score++;
			aMap.row[r].numberOfElements = 0;
			for (int k = 0; k < figureNumber; k++)
			{
				DestroyFigures(k, aMap.row[r].numberOfElements);//!!!!!!!!!!!!!!!!!!!!
				DestroyFigures(figureNumber, aMap.row[r].numberOfElements);//!!!!!!!!!!!!
				MoveFiguresDown(k);
			}
			MoveFiguresDown(figureNumber);
		}
	}
}

void  Figure::Rules()
{
	GameOver();
	GetPoints();
}

#endif // !FigureBehavior
