#pragma once
#include "shape.h"

class PointShape : virtual public Shape
{
public:
	PointShape(void);
	Shape* copyShape();

	std::wstring getName();
	void Draw(HDC);
	void DrawRubberBand(HDC);
};;