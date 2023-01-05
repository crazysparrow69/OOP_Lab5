#include "superline_shape.h"

SuperlineShape::SuperlineShape() {}

Shape* SuperlineShape::copyShape()
{
	return new SuperlineShape;
}

std::wstring SuperlineShape::getName()
{
	return L"Ρσοεπλ³ν³ÿ";
}

void SuperlineShape::Draw(HDC hdc)
{
	long x1 = xstart, y1 = ystart, x2 = xend, y2 = yend;

	LineShape::Draw(hdc);

	Set(x1, y1, x1 + 10, y1 + 10);
	EllipseShape::Draw(hdc);

	Set(x2, y2, x2 + 10, y2 + 10);
	EllipseShape::Draw(hdc);

	Set(x1, y1, x2, y2);
}

void SuperlineShape::DrawRubberBand(HDC hdc)
{
	Draw(hdc);
}