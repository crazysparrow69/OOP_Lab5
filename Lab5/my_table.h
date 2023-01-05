#pragma once
#include "framework.h"
#include "resource1.h"
#include <fstream>
#include <string>
#include <codecvt>
//#include <locale>

class MyTable
{
private:
	MyTable() {}
	MyTable(const MyTable& root) = delete;
	MyTable& operator = (const MyTable&) = delete;
	static HWND hWndTable;
	static HWND hWndParent;
	static LPCSTR path;
	static int selectedItem;
	static int toRemove;
public:
	static MyTable& getInstance()
	{
		static MyTable instance;
		return instance;
	}
	static HWND getTable();
	static HWND getParent();
	static void setSelected(int);
	static int getSelected();
	static void setRemove(int);
	static int getRemove();
	void OnCreate(HWND, HINSTANCE);
	void Show();
	void addString(std::wstring);
	static void rmString(int);
};