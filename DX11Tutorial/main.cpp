#include <Windows.h>

// The entry point for any Windows program.
int WINAPI WinMain (HINSTANCE hInstance,
					HINSTANCE hPrevInstance,
					LPSTR lpCmdLine,
					int nShowCmd) {

	// create a "Hello, World" message usionmg MessageBox()
	MessageBox (nullptr,
				"Hello, World",
				"Hello world app",
				MB_ICONEXCLAMATION | MB_OK);
	
	return 0;
}