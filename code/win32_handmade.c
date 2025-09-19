#pragma warning(disable: 4668)

#include <windows.h>


LRESULT CALLBACK MainWindowCallback(HWND, UINT, WPARAM, LPARAM);


int APIENTRY
WinMain(HINSTANCE hInst,
	HINSTANCE hInstPrev,
	PSTR cmdline,
	int cmdshow)
{
  UNREFERENCED_PARAMETER(hInst);
  UNREFERENCED_PARAMETER(hInstPrev);
  UNREFERENCED_PARAMETER(cmdline);
  UNREFERENCED_PARAMETER(cmdshow);
  
  // hello world this is a test.
  
  OutputDebugString("Hello world");
  
  // __debugbreak();  // this will breakpoint if running in a debugger.
  
  WNDCLASSA wc = {0};
  wc.style = CS_OWNDC | CS_VREDRAW | CS_HREDRAW;
  wc.lpfnWndProc = MainWindowCallback;
  wc.hInstance = hInst;
  wc.lpszClassName = "HandmadeHeroWindowClass";
  
  if (RegisterClassA(&wc))
  {
    HWND WindowHandle =
      CreateWindowEx(0,
		     wc.lpszClassName,
		     "Handmade Hero",
		     WS_OVERLAPPEDWINDOW|WS_VISIBLE,
		     CW_USEDEFAULT, CW_USEDEFAULT,
		     CW_USEDEFAULT, CW_USEDEFAULT,
		     0,
		     0,
		     hInst,
		     0);

    if (WindowHandle)
    {
      MSG Message;
      for(;;)
      {
	BOOL MessageResult = GetMessage(&Message, 0, 0, 0);
	if (MessageResult > 0) {
	  TranslateMessage(&Message);
	  DispatchMessage(&Message);
	}
	else
	{
	  break;
	}
      }
    }
    else
    {
      ;  // TODO - failed
    }
  }
  else
  {
    ; // TODO - failed
  }

  return 0;
}


LRESULT CALLBACK
MainWindowCallback(
  HWND Window,
  UINT Message,
  WPARAM WParam,
  LPARAM LParam)
{
  LRESULT returnValue = 0;
  
  switch (Message){ 
  case WM_CREATE:
    {
      // Initialize the window.
      OutputDebugString("WM_CREATE");
      
    } break;
     
  case WM_PAINT:
    {
      // Paint the window's client area. 
      OutputDebugString("WM_PAINT");
      
    } break;
    
 
  case WM_SIZE:
    {
      // Set the size and position of the window. 
      OutputDebugString("WM_SIZE");
      
    } break;
 
  case WM_DESTROY:
    {
      // Clean up window-specific data objects.
      OutputDebugString("WM_DESTORY");
      
    } break;

    // 
    // Process other messages. 
    // 
 
  default:
    {
      returnValue = DefWindowProc(Window, Message, WParam, LParam);
    } break;
  } 

  return returnValue;
}

