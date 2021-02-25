// utf8-test.cpp : ���ɮץ]�t 'main' �禡�C�{���|��ӳB�}�l����ε�������C
//

#include <iostream>
#include<stdio.h>

#include <windows.h>
using namespace std;
int main()
{
	HANDLE std_out;
	DWORD i;
	char* error_msg;
	setlocale(LC_ALL, "zh_CN.UTF-8"); //https://blog.csdn.net/u010003835/article/details/48544747
									  //�@�̩� linux�U����p("%s"/"%ls"): https://www.itread01.com/content/1546726324.html
	std_out = GetStdHandle(STD_OUTPUT_HANDLE); 
	//AttachConsole(ATTACH_PARENT_PROCESS);

	wchar_t wbuf[] = L"AAA�j�a!!!\n";
	char16_t u16buf[] = u"AAA�j�a�n!!!\n";
	char buf[] = "AAA�j�a�n!!!\n";
	//L,u �o��prefix �|�N�ݨ쪺�r���ഫ���X�I https://www.ithome.com.tw/voice/135711

	WriteConsoleW(std_out, wbuf, sizeof(wbuf)/2, &i, NULL); // WriteConsoleW �Ϊk�ѷ� https://stackoverflow.com/questions/9794764/console-output-with-winapi-writeconsole
	WriteConsoleW(std_out, u16buf, sizeof(u16buf) / 2, &i, NULL);
	wcout << wbuf; // ���hcall WideCharToMultiByte http://demon.tw/programming/wprintf-unicode.html
	cout << buf;
	// �n�bcmd �����`��ܡA�O�o�n��codepage http://fatting10.blogspot.com/2015/08/solved-window.html


	// code pages https://docs.microsoft.com/en-us/windows/win32/intl/code-pages
	// unicode https://docs.microsoft.com/en-us/windows/win32/intl/unicode
	// convention for function prototypes https://docs.microsoft.com/en-us/windows/win32/intl/conventions-for-function-prototypes

	return 0;

}

// ����{��: Ctrl + F5 �� [����] > [�Ұʦ�������] �\���
// �����{��: F5 �� [����] > [�Ұʰ���] �\���

// �}�l�ϥΪ�����: 
//   1. �ϥ� [����`��] �����A�s�W/�޲z�ɮ�
//   2. �ϥ� [Team Explorer] �����A�s�u���l�ɱ���
//   3. �ϥ� [��X] �����A�Ѿ\�իؿ�X�P��L�T��
//   4. �ϥ� [���~�M��] �����A�˵����~
//   5. �e�� [�M��] > [�s�W����]�A�إ߷s���{���X�ɮסA�άO�e�� [�M��] > [�s�W�{������]�A�N�{���{���X�ɮ׷s�W�ܱM��
//   6. ����n�A���}�Ҧ��M�׮ɡA�Ыe�� [�ɮ�] > [�}��] > [�M��]�A�M���� .sln �ɮ�
