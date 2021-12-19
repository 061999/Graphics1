#include <Windows.h>
#include "Single.h"
#include "MyTimer.h"

LRESULT CALLBACK WndPorc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	if (msg==WM_CLOSE)
	{
		PostQuitMessage(0);
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpComLine, int nComShow) {

	const auto pClassName = "hw3dbutts";
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndPorc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hCursor = nullptr;
	wc.hIcon = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;
	RegisterClassEx(&wc);

	HWND hWnd = CreateWindowEx(0, pClassName, "Happy Hard Window", WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, 200, 200, 640, 480, nullptr, nullptr, hInstance, nullptr);
	Single* single = new Single(hWnd);
	MyTimer t;

	ShowWindow(hWnd, SW_SHOW);
	MSG msg;
	while (true)
	{
		if (PeekMessage(&msg,nullptr,0,0,PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			single->draw(cos(t.Peek()), 0.5f, sin(t.Peek()));
		}
		if (msg.message==WM_QUIT)
		{
			return 0;
		}
	}
	return 0;
}
