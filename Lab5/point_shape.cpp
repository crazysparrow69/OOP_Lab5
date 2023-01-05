#include "point_shape.h"
#include "framework.h"

PointShape::PointShape() {}

Shape* PointShape::copyShape()
{
	return new PointShape;
}

std::wstring PointShape::getName()
{
	xstart = xend;
	ystart = yend;
	xend = 0;
	yend = 0;
	return L"Крапка";
}

void PointShape::Draw(HDC hdc)
{
	Rectangle(hdc, xstart - 1, ystart - 1, xstart + 1, ystart + 1);
}

void PointShape::DrawRubberBand(HDC hdc) {}