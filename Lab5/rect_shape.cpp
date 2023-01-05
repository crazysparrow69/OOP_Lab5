#include "rect_shape.h"

RectShape::RectShape() {}

Shape* RectShape::copyShape()
{
	return new RectShape;
}

std::wstring RectShape::getName()
{
	return L"Прямокутник";
}

void RectShape::Draw(HDC hdc)
{
	HBRUSH hBrush = (HBRUSH)CreateSolidBrush(RGB(220, 220, 220));
	HBRUSH hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

	Rectangle(hdc, xstart, ystart, xend, yend);

	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
}

void RectShape::DrawRubberBand(HDC hdc)
{
	MoveToEx(hdc, xstart, ystart, NULL);
	LineTo(hdc, xstart, yend);
	LineTo(hdc, xend, yend);
	LineTo(hdc, xend, ystart);
	LineTo(hdc, xstart, ystart);
}