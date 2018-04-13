#pragma once
#ifndef ClassMap
#define ClassMap
#include "GlobalVariablesAndFunctions.h"

class Map
{
private:
	char wallSign;
	void TrowFigure(int, int);
public:
	Map()
	{
		wallSign = char(219);
	}
	struct Rows
	{
		int numberOfElements;
	};
	Rows row[HIHG];
	void DrawMap();
	void ChooseFigure(int, int, int, int);
};

Map aMap;

#endif // !ClassMap
