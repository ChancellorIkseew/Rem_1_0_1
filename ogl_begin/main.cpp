#include <windows.h>
#include <gl/gl.h>

#include "graphics/base_gl/base_gl.h"
#include "system/callback.h"

#include "test_game/test_game.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	STARTUPINFOA si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	char aa = 'a';
	LPSTR cmdExe = &aa;
	CreateProcessA(NULL, cmdExe, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);


	WNDCLASSEX wcex;
	HWND hwnd;
	HDC hDC;
	HGLRC hRC;
	MSG msg;
	BOOL bQuit = FALSE;

	/* register window class */
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_OWNDC;
	wcex.lpfnWndProc = WindowProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = "GLSample";
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);;

	if (!RegisterClassEx(&wcex))
		return 0;

	/* create main window */
	hwnd = CreateWindowEx(0, "GLSample", "Rem_0.0.1", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 720, 720, NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, nCmdShow);
	EnableOpenGL(hwnd, &hDC, &hRC);

	glOrtho(-2,2, -2,2, -2,0);
	glTranslatef(0, 0, 2);

	testInitSprite();

	while (!bQuit)
	{
		if (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				bQuit = TRUE;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessageA(&msg);
			}
		}
		else
		{
			glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glPushMatrix();
			testDrawBlock();
			glPopMatrix();

			SwapBuffers(hDC);
			Sleep(16);
		}
	}

	DisableOpenGL(hwnd, hDC, hRC);
	DestroyWindow(hwnd);

	return msg.wParam;
}

