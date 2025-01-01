#include <Windows.h>

// DEF
HWND hMain_Menu;
// Window Code
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR args, int nCmdShow) {
	WNDCLASSW WndClassConfig = { 0 };

	WndClassConfig.hbrBackground = (HBRUSH)COLOR_WINDOW;
	WndClassConfig.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClassConfig.hInstance = hInstance;
	WndClassConfig.lpszClassName = L"TEST";
	WndClassConfig.lpfnWndProc = WndProc;

	if (!RegisterClassW(&WndClassConfig)) {
		return -1;
	}

	hMain_Menu = CreateWindowW(L"TEST", L"MineNovelCraft", WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_SYSMENU, 200, 100, 200, 100, NULL, NULL, hInstance, NULL);
	if (hMain_Menu == NULL) {
		return -1;
	}

	MSG msg = { 0 };
	while (GetMessageW(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_DESTROY: {
		PostQuitMessage(0);
	} break;
	default: {
		return DefWindowProcW(hWnd, msg, wParam, lParam);
	}
	}
}