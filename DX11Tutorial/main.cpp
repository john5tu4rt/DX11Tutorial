#include <Windows.h>
#include <windowsx.h>

// The WindowProc function prototype
LRESULT CALLBACK WindowProc(HWND hWnd,
							UINT message,
							WPARAM wParam,
							LPARAM lParam);

// The entry point for any Windows program.
int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE hPrevInstance,
				   LPSTR lpCmdLine,
				   int nCmdShow) {
						

	// the handle for the window, filled by a function
	HWND hWnd;
	// this struct holds information for the window class
	WNDCLASSEX wc;

	// clear out the window class for use
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	// fill in the struct with needed information
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = "WindowClass1";

	// register the window class
	RegisterClassEx(&wc);

	// rectangle for AdjustWindowRect that deals with distortions between client and visible window
	RECT wr{ 0,0, 500, 400 }; // set the size, but not the position
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE); // adjust the size.


	// create the window and use the result as the handle
	hWnd = CreateWindowEx(NULL,		// The extended window style of the window being created - unneeded extension of the 4th param (window style)
						  "WindowClass1",		// name of the window class
						  "Our first Windowed program",		// window title
						  WS_OVERLAPPEDWINDOW,		// window style
						  300,		// x pos of window
						  300,		// y pos of window
						  wr.right - wr.left,		// window width
						  wr.bottom - wr.top,		// window height
						  NULL,		// we have no parent window
						  NULL,		// we aren't using menus
						  hInstance,		// application handle
						  NULL);	// used with multiple windows

	// display the window on screen
	ShowWindow(hWnd, nCmdShow);

	// enter the main loop:

	// this struct holds Windows event messages
	MSG msg;

	// wait for the next message in the queue, store the result
	while (GetMessage(&msg, NULL, 0, 0)) {

		// translates keystrokes into right format
		TranslateMessage(&msg);

		// send the message to the WindowProc function
		DispatchMessage(&msg);
	}

	// return this part of WM_QUIT message to Windows

	return msg.wParam;
}

// this is the main message handler for the program
LRESULT CALLBACK WindowProc(HWND hWnd,
							UINT message,
							WPARAM wParam,
							LPARAM lParam) {

	// sort through and find what code to run for the message given
	switch (message) {

		// this message is read when the window is closed
	case WM_DESTROY: {
			// close the application entirely (and by default)
			PostQuitMessage(0);
			return 0;
		} break;
	}

	// Handle any message the switch statement didn't
	return DefWindowProc(hWnd, message, wParam, lParam);
}