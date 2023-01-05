#include "ellipse_shape.h"

EllipseShape::EllipseShape() {}

Shape* EllipseShape::copyShape()
{
	return new EllipseShape;
}

std::wstring EllipseShape::getName()
{
	return L"Ελ³ορ";
}

void EllipseShape::Draw(HDC hdc)
{
	HBRUSH hBrush = (HBRUSH)CreateSolidBrush(RGB(136, 8, 8));
	HBRUSH hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

	Ellipse(hdc, xstart * 2 - xend, ystart * 2 - yend, xend, yend);

	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
}

void EllipseShape::DrawRubberBand(HDC hdc)
{
	Draw(hdc);
}