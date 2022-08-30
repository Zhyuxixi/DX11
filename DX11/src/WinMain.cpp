#include <Windows.h>


int CALLBACK WinMain(
	HINSTANCE	hInstance,
	HINSTANCE	hPreInstance,
	LPSTR		IpCmdLine,
	int			nCmdShow)
{
	const wchar_t pClassName[] = L"DX11butts";
	//register window class
	WNDCLASSEX wc = {0};
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = DefWindowProc;
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
		L"Happy Hard Window",								// Window text
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,           // Window style

		// Size and position
		//CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		200, 200, 640, 480,

		NULL,       // Parent window    
		NULL,       // Menu
		hInstance,  // Instance handle
		NULL        // Additional application data
	);

	if (hWnd == NULL)
	{
		return 0;
	}

	ShowWindow(hWnd, SW_SHOW);

	while (true)
	{

	}
	return 0;
}