#include "line_shape.h"

LineShape::LineShape() {}

Shape* LineShape::copyShape()
{
	return new LineShape;
}

std::wstring LineShape::getName()
{
	return L"Ë³í³ÿ";
}

void LineShape::Draw(HDC hdc)
{
	MoveToEx(hdc, xstart, ystart, NULL);
	LineTo(hdc, xend, yend);
}

void LineShape::DrawRubberBand(HDC hdc)
{
	Draw(hdc);
}