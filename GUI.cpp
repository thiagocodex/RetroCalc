#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <list>
#include "operations.h"

using namespace std;

HWND buttonequal;
HWND buttonsum;
HWND buttonsubt;
HWND buttondiv;
HWND buttonmult;
HWND buttonclear;

HWND buttonplusminus;
HWND buttonumbarraxis;
HWND buttonperc;
HWND buttoncomma;
HWND buttonsqrt;

HWND buttonerase;
HWND buttonce;


HWND buttonmc;
HWND buttonmr;
HWND buttonms;
HWND buttonmplus;
HWND buttonmminus;

HWND button0;
HWND button1;
HWND button2;
HWND button3;
HWND button4;
HWND button5;
HWND button6;
HWND button8;
HWND button7;
HWND button9;
HWND text;
HWND textaux;


double multipling = 1;
double summing = 0;
double res;



bool firstequal;

const char* equalbuf;

HFONT hFont = CreateFont(36, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
	CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Consolas"));

HFONT hTextFieldFont = CreateFont(20, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
	CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Consolas"));

COLORREF color = 0x00623f31;

HBRUSH cr = CreateSolidBrush(color);

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow) {
	const wchar_t CLASS_NAME[] = L"Janela Simples";
	WNDCLASS wc = {};
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName =  CLASS_NAME;

	RegisterClass(&wc);

	RECT rt = { 0, 0, 280, 390 };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, FALSE);

	HWND hwnd = CreateWindowExW(0, L"Janela Simples", L"RetroCalc 1.0", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, rt.right - rt.left, rt.bottom - rt.top, NULL, NULL, hInstance, NULL);

	if (hwnd == NULL) {
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);

	MSG msg{ };

	while (GetMessage(&msg, NULL, 0, 0)) {

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}



LRESULT CALLBACK WindowProc(HWND hwnd, UINT  uMsg, WPARAM wParam, LPARAM lParam) {

	switch (uMsg) {

		case WM_COMMAND:

			switch (LOWORD(wParam)) {

				case 0:
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
				case 6:
				case 7:
				case 8:
				case 9:
					typeToTextField(text, wParam);
				break;

				case 10:
					setop(text, 1);
					break;
				case 11:
					setop(text, 2);
					break;
				case 12:
					setop(text, 3);
					break;
				case 13:
					setop(text, 4);
					break;
				case 14:
				{
					_snwprintf_s(buf2, 31, L"%.16lg", final);
					SetWindowTextW(text, LPWSTR(buf2));
					break;
				}
				case 15:
					SetWindowTextW(text, LPWSTR(L"0"));
					operating = FALSE;
					operation = 0;
					
					final = 0;

					_snwprintf_s(buf2, 31, L"%.16lg", final);
				break;
			}
		break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		FillRect(hdc, &ps.rcPaint, cr);
		EndPaint(hwnd, &ps);
		break;
	}

	case WM_CREATE:
		button0 = CreateWindowA("BUTTON", "0", WS_VISIBLE | WS_CHILD, 20, 330, 90, 40, hwnd, (HMENU)0, NULL, NULL);
		button1 = CreateWindowA("BUTTON", "1", WS_VISIBLE | WS_CHILD, 20, 280, 40, 40, hwnd, (HMENU)1, NULL, NULL);
		button2 = CreateWindowA("BUTTON", "2", WS_VISIBLE | WS_CHILD, 70, 280, 40, 40, hwnd, (HMENU)2, NULL, NULL);
		button3 = CreateWindowA("BUTTON", "3", WS_VISIBLE | WS_CHILD, 120, 280, 40, 40, hwnd, (HMENU)3, NULL, NULL);
		button4 = CreateWindowA("BUTTON", "4", WS_VISIBLE | WS_CHILD, 20, 230, 40, 40, hwnd, (HMENU)4, NULL, NULL);
		button5 = CreateWindowA("BUTTON", "5", WS_VISIBLE | WS_CHILD, 70, 230, 40, 40, hwnd, (HMENU)5, NULL, NULL);
		button6 = CreateWindowA("BUTTON", "6", WS_VISIBLE | WS_CHILD, 120, 230, 40, 40, hwnd, (HMENU)6, NULL, NULL);
		button7 = CreateWindowA("BUTTON", "7", WS_VISIBLE | WS_CHILD, 20, 180, 40, 40, hwnd, (HMENU)7, NULL, NULL);
		button8 = CreateWindowA("BUTTON", "8", WS_VISIBLE | WS_CHILD, 70, 180, 40, 40, hwnd, (HMENU)8, NULL, NULL);
		button9 = CreateWindowA("BUTTON", "9", WS_VISIBLE | WS_CHILD, 120, 180, 40, 40, hwnd, (HMENU)9, NULL, NULL);
		buttonmult = CreateWindowA("BUTTON", "*", WS_VISIBLE | WS_CHILD, 170, 230, 40, 40, hwnd, (HMENU)10, NULL, NULL);
		buttondiv = CreateWindowA("BUTTON", "/", WS_VISIBLE | WS_CHILD, 170, 180, 40, 40, hwnd, (HMENU)11, NULL, NULL);
		buttonsum = CreateWindowA("BUTTON", "+", WS_VISIBLE | WS_CHILD, 170, 330, 40, 40, hwnd, (HMENU)12, NULL, NULL);
		buttonsubt = CreateWindowA("BUTTON", "-", WS_VISIBLE | WS_CHILD, 170, 280, 40, 40, hwnd, (HMENU)13, NULL, NULL);
		buttonequal = CreateWindowA("BUTTON", "=", WS_VISIBLE | WS_CHILD, 220, 280, 40, 90, hwnd, (HMENU)14, NULL, NULL);

		buttonclear = CreateWindowA("BUTTON", "C", WS_VISIBLE | WS_CHILD, 120, 130, 40, 40, hwnd, (HMENU)15, NULL, NULL);


		buttonerase = CreateWindowExW(0, L"BUTTON", L"⇤", WS_VISIBLE | WS_CHILD, 20, 130, 40, 40, hwnd, (HMENU)20, NULL, NULL);
		buttonplusminus = CreateWindowExW(0, L"BUTTON", L"±", WS_VISIBLE | WS_CHILD, 170, 130, 40, 40, hwnd, (HMENU)20, NULL, NULL);
		buttonsqrt = CreateWindowExW(0, L"BUTTON", L"√", WS_VISIBLE | WS_CHILD, 220, 130, 40, 40, hwnd, (HMENU)20, NULL, NULL);
		buttonperc = CreateWindowExW(0, L"BUTTON", L"%", WS_VISIBLE | WS_CHILD, 220, 180, 40, 40, hwnd, (HMENU)20, NULL, NULL);
		buttoncomma = CreateWindowExW(0, L"BUTTON", L",", WS_VISIBLE | WS_CHILD, 120, 330, 40, 40, hwnd, (HMENU)20, NULL, NULL);

		buttonmc = CreateWindowA("BUTTON", "MC", WS_VISIBLE | WS_CHILD, 70, 80, 40, 40, hwnd, (HMENU)16, NULL, NULL);
		buttonmr = CreateWindowA("BUTTON", "MR", WS_VISIBLE | WS_CHILD, 20, 80, 40, 40, hwnd, (HMENU)17, NULL, NULL);
		buttonms = CreateWindowA("BUTTON", "MS", WS_VISIBLE | WS_CHILD, 120, 80, 40, 40, hwnd, (HMENU)18, NULL, NULL);
		buttonmplus = CreateWindowA("BUTTON", "M+", WS_VISIBLE | WS_CHILD, 170, 80, 40, 40, hwnd, (HMENU)19, NULL, NULL);
		buttonmminus = CreateWindowA("BUTTON", "M-", WS_VISIBLE | WS_CHILD, 220, 80, 40, 40, hwnd, (HMENU)20, NULL, NULL);
		buttonce = CreateWindowA("BUTTON", "CE", WS_VISIBLE | WS_CHILD, 70, 130, 40, 40, hwnd, (HMENU)25, NULL, NULL);
		buttonumbarraxis = CreateWindowExW(0, L"BUTTON", L"1/x", WS_VISIBLE | WS_CHILD, 220, 230, 40, 40, hwnd, (HMENU)20, NULL, NULL);

		{
			std::list<HWND> hDigitButtons =
		
			{ button0, button1, button2, button3, button4, button5, button6, button7, button8, button9, buttonmult, buttondiv, buttonsum, buttonsubt, buttonequal, text, buttonclear, buttonerase, buttonplusminus, buttonsqrt, buttonperc, buttoncomma };

			for (auto it = hDigitButtons.begin(); it != hDigitButtons.end(); it++) {
				SendMessage(*it, WM_SETFONT, WPARAM(hFont), TRUE);
			}
		}
		text = CreateWindowExW(0, L"EDIT", L"0", WS_VISIBLE | WS_CHILD | SS_RIGHT | WS_EX_LEFT, 20, 40, 240, 20, hwnd, (HMENU)16, 0, 0);
		textaux = CreateWindowExW(0, L"EDIT", L"", WS_VISIBLE | WS_CHILD | SS_RIGHT | WS_EX_LEFT, 20, 20, 240, 20, hwnd, (HMENU)30, 0, 0);
		SendMessage(text, WM_SETFONT, WPARAM(hTextFieldFont), TRUE);
		SendMessage(textaux, WM_SETFONT, WPARAM(hTextFieldFont), TRUE);

	break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

