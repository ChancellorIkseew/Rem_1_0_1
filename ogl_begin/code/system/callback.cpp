
#include "callback.h"
#include "macros.h"


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;

	case WM_SIZE:
		//windowResize(LOWORD(lParam), HIWORD(lParam));
		break;

	case WM_DESTROY:
		return 0;

	case WM_SETCURSOR:
		ShowCursor(TRUE);
		//else
			//ShowCursor(TRUE);
		break;

	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_ESCAPE:
			//PostQuitMessage(0);
			break;
		}

	}
	break;

	case WM_MOUSEWHEEL:
	{
		int delta = GET_WHEEL_DELTA_WPARAM(wParam);
		mouseWhellRotation = delta / 120;
		break;
	}

	default:
		return DefWindowProcA(hwnd, uMsg, wParam, lParam);
	}

	return 0;
}
