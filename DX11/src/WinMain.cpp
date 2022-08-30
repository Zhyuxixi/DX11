#include <Windows.h>
#include "WindowsMessageMap.h"

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static WindowsMessageMap mm;
	OutputDebugString(mm(uMsg, lParam, wParam).c_str());

	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(69);
		break;
	case WM_KEYDOWN:
		if (wParam == 'F') SetWindowText(hWnd, "Respects");
		break;
	case WM_KEYUP:
		if (wParam == 'F') SetWindowText(hWnd, "Dangerfield");
		break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int CALLBACK WinMain(
	HINSTANCE	hInstance,
	HINSTANCE	hPreInstance,
	LPSTR		IpCmdLine,
	int			nCmdShow)
{

	//register window class

	const auto pClassName = "DX11butts";
	//const wchar_t pClassName[] = L"DX11butts";
	WNDCLASSEX wc = {0};
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;

	RegisterClassEx(&wc);

	HWND hWnd = CreateWindowEx(
		0,													// Optional window styles.
		pClassName,											// Window class
		"Happy Hard Window",								// Window text
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,           // Window style

		// Size and position
		//CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		200, 200, 640, 480,

		nullptr,       // Parent window    
		nullptr,       // Menu
		hInstance,  // Instance handle
		nullptr        // Additional application data
	);

	if (hWnd == nullptr)
	{
		return 0;
	}

	// Show the window

	ShowWindow(hWnd, SW_SHOW);

	// Run the message loop.

	MSG msg = { };
	BOOL gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (gResult == -1)	return -1;
	else		return msg.wParam;
}