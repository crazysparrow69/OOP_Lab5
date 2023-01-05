#pragma once
#include "line_shape.h"
#include "ellipse_shape.h"

class SuperlineShape : public LineShape, public EllipseShape
{
public:
	SuperlineShape(void);
	Shape* copyShape();

	std::wstring getName();
	void Draw(HDC);
	void DrawRubberBand(HDC);
};