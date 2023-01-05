#include "my_editor.h"

MyEditor::~MyEditor()
{
	delete[] pshape;
}

void MyEditor::Start(Shape *shape, HWND hWnd, LPARAM lParam)
{
	parentShape = shape;
	toolbar.OnToolMove(hWnd, lParam);
}

void MyEditor::OnLBdown(HWND hWnd)
{
	if (parentShape)
	{
		POINT pt;

		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);

		xstart = pt.x;
		ystart = pt.y;

		pshape[i] = parentShape->copyShape();
		pshape[i]->Set(xstart, ystart, xend, yend);
	}
}

std::wstring MyEditor::OnLBup(HWND hWnd)
{
	std::wstring properties = L"";

	if (xstart)
	{
		POINT pt;

		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);

		xend = pt.x;
		yend = pt.y;

		pshape[i]->Set(xstart, ystart, xend, yend);
		properties = pshape[i]->getProperties();
		if (i < MY_SHAPE_ARRAY_SIZE - 1) i++;
		else i = 0;

		xstart = 0, ystart = 0, xend = 0, yend = 0;

		InvalidateRect(hWnd, NULL, TRUE);	
	}

	return properties;
}

void MyEditor::OnMouseMove(HWND hWnd)
{
	if (xstart)
	{
		POINT pt;
		HPEN hPen = CreatePen(PS_DOT, 1, 0);
		HDC hdc = GetDC(hWnd);
		HPEN hPenOld = (HPEN)SelectObject(hdc, hPen);

		SetROP2(hdc, R2_NOTXORPEN);

		if (xend) pshape[i]->DrawRubberBand(hdc);

		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		xend = pt.x;
		yend = pt.y;

		pshape[i]->Set(xstart, ystart, xend, yend);
		pshape[i]->DrawRubberBand(hdc);

		SelectObject(hdc, hPenOld);
		DeleteObject(hPen);
		ReleaseDC(hWnd, hdc);
	}
}

void MyEditor::OnPaint(HWND hWnd, int selectedItem)
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	for (int i = 0; i < MY_SHAPE_ARRAY_SIZE; i++)
		if (pshape[i])
		{
			bool isSelected = selectedItem == i ? true : false;
			pshape[i]->Show(hdc, isSelected);
		}
	EndPaint(hWnd, &ps);
}


void MyEditor::rmItem(int selectedItem)
{
	if (selectedItem >= 0)
	{
		for (int i = 0; i < MY_SHAPE_ARRAY_SIZE; i++)
			if (i >= selectedItem)
			{
				Shape* next = pshape[i + 1];
				if (next)
					pshape[i] = next;
				else
				{
					pshape[i] = NULL;
					break;
				}
			}
		i--;
	}
}

void MyEditor::OnCreate(HWND hWnd, HINSTANCE hInst)
{
	toolbar.OnCreate(hWnd, hInst);
}

void MyEditor::OnNotify(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	toolbar.OnNotify(hWnd, wParam, lParam);
}

void MyEditor::OnSize(HWND hWnd)
{
	toolbar.OnSize(hWnd);
}