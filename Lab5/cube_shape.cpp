#include "cube_shape.h"

CubeShape::CubeShape() {}

Shape* CubeShape::copyShape()
{
	return new CubeShape;
}

std::wstring CubeShape::getName()
{
	return L" Û·";
}

void CubeShape::Draw(HDC hdc)
{
	long x1 = xstart, y1 = ystart, x2 = xend, y2 = yend;
	long xd = (x2 - x1) / 3, yd = (y2 - y1) / 3;

	Set(x1, y1, x2 - xd, y2 - yd);
	RectShape::DrawRubberBand(hdc);

	Set(x1 + xd, y1 + yd, x2, y2);
	RectShape::DrawRubberBand(hdc);

	Set(x1, y1, x1 + xd, y1 + yd);
	LineShape::Draw(hdc);

	Set(x2, y2, x2 - xd, y2 - yd);
	LineShape::Draw(hdc);

	Set(x1, y2 - yd, x1 + xd, y2);
	LineShape::Draw(hdc);

	Set(x2 - xd, y1, x2, y1 + yd);
	LineShape::Draw(hdc);

	Set(x1, y1, x2, y2);
}

void CubeShape::DrawRubberBand(HDC hdc)
{
	Draw(hdc);
}