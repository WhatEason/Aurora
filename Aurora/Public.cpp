#include "pch.h"
#include "framework.h"
#include "Aurora.h"
#include "AuroraDlg.h"
#include "afxdialogex.h"
#include "Public.h"

//开启控制台 printf输出
void OpenConsole()
{
	//开启之前先关闭一次 防止多次有问题
	CloseConsole();
	AllocConsole();
	freopen("CONOUT$", "w+t", stdout);

	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hStdin, &mode);
	mode &= ~ENABLE_QUICK_EDIT_MODE;  //移除快速编辑模式
	mode &= ~ENABLE_INSERT_MODE;      //移除插入模式
	mode &= ~ENABLE_MOUSE_INPUT;
	SetConsoleMode(hStdin, mode);
}

void CloseConsole()
{
	//fclose(stdout);
	FreeConsole();
}