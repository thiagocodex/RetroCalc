#pragma once

#include <windows.h>
#include <sstream>
#include <iostream>
#include <list>
bool operating = FALSE;
byte operation;

wchar_t buf[31];
wchar_t buf2[31];

using namespace std;


double final;

double var1;
double var2;



void typeToTextField(HWND text_field, int wParam) {

	if (operating) {
		GetWindowTextW(text_field, LPWSTR(buf2), 31);
		var1 = _wtof(buf2);
		SetWindowTextW(text_field, LPWSTR(L""));
		

	}
		GetWindowTextW(text_field, LPWSTR(buf2), 31);

		_snwprintf_s(buf, 31, L"%.16lg", double(wParam));

	if (lstrlenW(buf2) < 22) {
		if (wcscmp(buf2, L"0")) {

			lstrcatW(buf2, buf);
			SetWindowTextW(text_field, LPWSTR(buf2));
			GetWindowTextW(text_field, LPWSTR(buf2), 31);
			var2 = _wtof(buf2);

			switch (operation) {

			case 1:
				final = var1 * var2;
				break;
			case 2:
				final = var1 / var2;
				break;
			case 3:
				final = var1 + var2;
				break;
			case 4:
				final = var1 - var2;
				break;

			}
		}else {
			lstrcatW(buf2, buf);
			SetWindowTextW(text_field, LPWSTR(buf));
			GetWindowTextW(text_field, LPWSTR(buf), 31);
			var2 = _wtof(buf);
		}
	}
}

void reset() {
	_snwprintf_s(buf2, 31, L"%.16lg", final);
}

void setop(HWND text_field, byte op) {

	if (operating) {
		_snwprintf_s(buf2, 31, L"%.16lg", final);
		SetWindowTextW(text_field, LPWSTR(buf2));
	}
	GetWindowTextW(text_field, LPWSTR(buf), 31);
	operating = TRUE;
	operation = op;

}