

#include <windows.h>

int APIENTRY
WinMain(HINSTANCE hInst,
	HINSTANCE hInstPrev,
	PSTR cmdline,
	int cmdshow)
{
  // hello world this is a test.
  
  OutputDebugString("Hello world");
  
  // __debugbreak();
  
  MessageBox(NULL, "Hello, world", "Hello", MB_OK|MB_ICONINFORMATION);

  return 0;
}
