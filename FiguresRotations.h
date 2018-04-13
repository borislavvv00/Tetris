#pragma once
#ifndef FiguresRotations
#define FiguresRotations
#include "GlobalVariablesAndFunctions.h"
#include "ClassFigure.h"

void Figure::FigureRotation()
{
	switch (shape[figureNumber])
	{
	case 1:
		if (position == 0 || position == 2)
		{
			figure[figureNumber].X[0] -= 2; //##
			figure[figureNumber].Y[3] += 2; // ##
		}
		else if (position == 1 || position == 3)
		{					// #
			figure[figureNumber].X[0] += 2; //##
			figure[figureNumber].Y[3] -= 2; //#
		}
		break;
	case 2:
		if (position == 0 || position == 2)
		{
			figure[figureNumber].X[1]--;
			figure[figureNumber].X[2] -= 2; //####
			figure[figureNumber].X[3] -= 3;
			figure[figureNumber].Y[1]++;
			figure[figureNumber].Y[2] += 2;
			figure[figureNumber].Y[3] += 3;
		}
		else if (position == 1 || position == 3)
		{
			figure[figureNumber].X[1]++;
			figure[figureNumber].X[2] += 2;
			figure[figureNumber].X[3] += 3;	 //#
			figure[figureNumber].Y[1]--;	 //#
			figure[figureNumber].Y[2] -= 2;	 //#
			figure[figureNumber].Y[3] -= 3;	 //#
		}
		break;
	case 3:
		if (position == 0 || position == 2)
		{
			figure[figureNumber].X[0] += 2;// ##
			figure[figureNumber].Y[3] += 2;//##
		}
		else if (position == 1 || position == 3)
		{					//#
			figure[figureNumber].X[0] -= 2; //##
			figure[figureNumber].Y[3] -= 2; // #
		}
		break;
	case 4:
		if (position == 0)
		{
			figure[figureNumber].X[0] --;
			figure[figureNumber].Y[0] -= 3;   //  #
			figure[figureNumber].Y[1] --;     //###
			figure[figureNumber].X[1] --;
		}
		else if (position == 1)
		{
			figure[figureNumber].X[0] --;//##
			figure[figureNumber].Y[0] ++;// #
			figure[figureNumber].X[1] ++;// #
			figure[figureNumber].Y[1] ++;
		}
		else if (position == 2)
		{
			figure[figureNumber].Y[0] += 2;
			figure[figureNumber].X[1] -= 2;//###
			figure[figureNumber].Y[1] += 2;//#
		}
		else if (position == 3)
		{
			figure[figureNumber].X[0] += 2;//#
			figure[figureNumber].X[1] += 2;//#
			figure[figureNumber].Y[1] -= 2;//##
		}
		break;
	case 5:
		if (position == 0)
		{
			figure[figureNumber].X[0] ++;  // #
			figure[figureNumber].X[3] += 2;//###
			figure[figureNumber].Y[3] ++;
		}
		else if (position == 1)
		{
			figure[figureNumber].Y[0] ++;//#
			figure[figureNumber].X[0] ++;//##
		}				     //#
		else if (position == 2)
		{
			figure[figureNumber].X[3] --;//###
			figure[figureNumber].Y[0] --;// #
			figure[figureNumber].X[0] -= 2;
		}
		else if (position == 3)
		{				     // #
			figure[figureNumber].X[3] --;//##
			figure[figureNumber].Y[3] --;// #
		}
		break;
	case 6:
		if (position == 0)
		{
			figure[figureNumber].X[2] ++;//#
			figure[figureNumber].X[3] --;//###
			figure[figureNumber].Y[3] += 2;
		}
		else if (position == 1)
		{
			figure[figureNumber].Y[2] -= 2;// #
			figure[figureNumber].X[3] -= 2;// #
			figure[figureNumber].Y[3] -= 2;//##
		}
		else if (position == 2)
		{
			figure[figureNumber].X[2] --;  //###
			figure[figureNumber].X[3] ++;  //  #
			figure[figureNumber].Y[3] -= 2;
		}
		else if (position == 3)
		{
			figure[figureNumber].Y[2] += 2;//##
			figure[figureNumber].X[3] += 2;//#
			figure[figureNumber].Y[3] += 2;//#
		}
		break;
	}
}

#endif // !FiguresRotations
