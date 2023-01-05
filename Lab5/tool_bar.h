#pragma once
#pragma comment(lib, "comctl32.lib")
class ToolBar	{
protected:
	HWND hwndToolBar;
	LPARAM oldlParam;
public:
public:
	static ToolBar& getInstance()
	{
		static ToolBar instance;
		return instance;
	}
	ToolBar(void);
	void OnCreate(HWND, HINSTANCE);
	void OnSize(HWND);
	void OnNotify(HWND, WPARAM, LPARAM);
	void OnToolMove(HWND, LPARAM);
};;