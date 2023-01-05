#pragma once
#include "shape.h"

class LineShape : virtual public Shape
{
public:
	LineShape(void);
	Shape* copyShape();

	std::wstring getName();
	void Draw(HDC);
	void DrawRubberBand(HDC);
};