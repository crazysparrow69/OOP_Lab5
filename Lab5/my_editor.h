#pragma once
#include "shape.h"
#include "point_shape.h"
#include "line_shape.h"
#include "rect_shape.h"
#include "ellipse_shape.h"
#include "superline_shape.h"
#include "cube_shape.h"
#include "tool_bar.h"
#include <string>

#define MY_SHAPE_ARRAY_SIZE		123

class MyEditor
{
private:
	MyEditor() {}
	MyEditor(const MyEditor& root) = delete;
	MyEditor& operator = (const MyEditor&) = delete;
	ToolBar toolbar;
	Shape** pshape = new Shape * [MY_SHAPE_ARRAY_SIZE] {};
	int i = 0;
	Shape* parentShape = NULL;
	long xstart = 0, ystart = 0, xend = 0, yend = 0;
public:
	~MyEditor();
	static MyEditor& getInstance()
	{
		static MyEditor instance;
		return instance;
	}

	void Start(Shape*, HWND, LPARAM);
	void OnLBdown(HWND);
	std::wstring OnLBup(HWND);
	void rmItem(int);
	void OnMouseMove(HWND);
	void OnPaint(HWND, int);
	void OnCreate(HWND, HINSTANCE);
	void OnNotify(HWND, WPARAM, LPARAM);
	void OnSize(HWND);
};