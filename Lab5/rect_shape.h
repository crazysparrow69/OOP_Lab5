#pragma once
#include "shape.h"

class RectShape : virtual public Shape
{
public:
	RectShape(void);
	Shape* copyShape();

	std::wstring getName();
	void Draw(HDC);
	void DrawRubberBand(HDC);
};;