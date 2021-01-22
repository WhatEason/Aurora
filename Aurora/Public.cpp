#include "pch.h"
#include "framework.h"
#include "Aurora.h"
#include "AuroraDlg.h"
#include "afxdialogex.h"
#include "Public.h"

//��������̨ printf���
void OpenConsole()
{
	//����֮ǰ�ȹر�һ�� ��ֹ���������
	CloseConsole();
	AllocConsole();
	freopen("CONOUT$", "w+t", stdout);

	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hStdin, &mode);
	mode &= ~ENABLE_QUICK_EDIT_MODE;  //�Ƴ����ٱ༭ģʽ
	mode &= ~ENABLE_INSERT_MODE;      //�Ƴ�����ģʽ
	mode &= ~ENABLE_MOUSE_INPUT;
	SetConsoleMode(hStdin, mode);
}

void CloseConsole()
{
	//fclose(stdout);
	FreeConsole();
}