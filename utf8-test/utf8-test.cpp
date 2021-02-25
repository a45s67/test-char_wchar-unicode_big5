// utf8-test.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
									  //作者於 linux下的踩雷("%s"/"%ls"): https://www.itread01.com/content/1546726324.html
	std_out = GetStdHandle(STD_OUTPUT_HANDLE); 
	//AttachConsole(ATTACH_PARENT_PROCESS);

	wchar_t wbuf[] = L"AAA大家!!!\n";
	char16_t u16buf[] = u"AAA大家好!!!\n";
	char buf[] = "AAA大家好!!!\n";
	//L,u 這些prefix 會將看到的字元轉換成碼點 https://www.ithome.com.tw/voice/135711

	WriteConsoleW(std_out, wbuf, sizeof(wbuf)/2, &i, NULL); // WriteConsoleW 用法參照 https://stackoverflow.com/questions/9794764/console-output-with-winapi-writeconsole
	WriteConsoleW(std_out, u16buf, sizeof(u16buf) / 2, &i, NULL);
	wcout << wbuf; // 底層call WideCharToMultiByte http://demon.tw/programming/wprintf-unicode.html
	cout << buf;
	// 要在cmd 中正常顯示，記得要改codepage http://fatting10.blogspot.com/2015/08/solved-window.html


	// code pages https://docs.microsoft.com/en-us/windows/win32/intl/code-pages
	// unicode https://docs.microsoft.com/en-us/windows/win32/intl/unicode
	// convention for function prototypes https://docs.microsoft.com/en-us/windows/win32/intl/conventions-for-function-prototypes

	return 0;

}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
