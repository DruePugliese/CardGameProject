#include "displayManager.h"
#include "deck.h"


//Global Vars



/*
HDC         imageDC;        // the DC to hold our image
HBITMAP     imageBmp;       // the actual bitmap which contains the image (will be put in the DC)
HBITMAP     imageBmpOld;    // the DC's old bitmap (for cleanup)

const int   screenSize_X = 1000;
const int   screenSize_Y = 500;

//main window name
static TCHAR szWindowClass[] = _T("win32app");

//main window title bar text
static TCHAR szTitle[] = _T("Win32 Guided Tour Application");

HINSTANCE hInst;

//Function declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void loadImage(const char* pathname);
void cleanUpImage();
void drawImage(HDC screen);
HWND createWindow(HINSTANCE inst);*/

int WINAPI WinMain(HINSTANCE hInstance, 
					HINSTANCE hPrevInstance, 
					LPSTR lpCmdLine, 
					int nCmdShow){

	vector<card> deckOfCards;

	srand(time(NULL));

	for (int i = 0; i < 30;i++){
		card card1 = card();
		card1.setAttack(rand() % 10);
		card1.setHealth(rand() % 15);
		card1.setSpell(false);
		deckOfCards.push_back(card1);
	}

	deck(3.0, deckOfCards, "stuff");



	// create our window
	displayManager().createWindow(hInstance);

	// Do the message pump!  keep polling for messages (and respond to them)
	//  until the user closes the window.
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0)) // while we are getting non-WM_QUIT messages...
	{
		TranslateMessage(&msg);     // translate them
		DispatchMessage(&msg);      // and dispatch them (our wndProc will process them)
	}

	// once the user quits....
	cleanUpImage();
}



/*////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
// Function to load the image into our DC so we can draw it to the screen
void loadImage(const char* pathname)
{
	imageDC = CreateCompatibleDC(NULL);     // create an offscreen DC

	imageBmp = (HBITMAP)LoadImageA(         // load the bitmap from a file
		NULL,                           // not loading from a module, so this is NULL
		pathname,                       // the path we're loading from
		IMAGE_BITMAP,                   // we are loading a bitmap
		0, 0,                            // don't need to specify width/height
		LR_DEFAULTSIZE | LR_LOADFROMFILE// use the default bitmap size (whatever the file is), and load it from a file
		);

	imageBmpOld = (HBITMAP)SelectObject(imageDC, imageBmp);  // put the loaded image into our DC
}


///////////////////////////////
// Function to clean up
void cleanUpImage()
{
	SelectObject(imageDC, imageBmpOld);      // put the old bmp back in our DC
	DeleteObject(imageBmp);                 // delete the bmp we loaded
	DeleteDC(imageDC);                      // delete the DC we created
}

///////////////////////////////
///////////////////////////////
// The function to draw our image to the display (the given DC is the screen DC)
void drawImage(HDC screen)
{
	BitBlt(
		screen,         // tell it we want to draw to the screen
		100, 0,            // as position 0,0 (upper-left corner)
		screenSize_X,   // width of the rect to draw
		screenSize_Y,   // height of the rect
		imageDC,        // the DC to get the rect from (our image DC)
		0, 0,            // take it from position 0,0 in the image DC
		SRCCOPY         // tell it to do a pixel-by-pixel copy
		);
}


///////////////////////////////
///////////////////////////////
// A callback to handle Windows messages as they happen
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC screen;
	TCHAR greeting[] = _T("Hello, World!");

	// what kind of message is this?
	switch (message)
	{

	// we are interested in WM_PAINT, as that is how we draw
	case WM_PAINT:
		
		screen = BeginPaint(hWnd, &ps);   // Get the screen DC
		TextOut(screen, 5, 5, greeting, _tcslen(greeting));
		drawImage(screen);                  // draw our image to our screen DC
		EndPaint(hWnd, &ps);                  // clean up
		break;

	// we are also interested in the WM_DESTROY message, as that lets us know when to close the window
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;
}

///////////////////////////////
///////////////////////////////
// A function to create the window and get it set up
HWND createWindow(HINSTANCE inst)
{
	WNDCLASSEX wc = { 0 };        // create a WNDCLASSEX struct and zero it
	wc.cbSize = sizeof(WNDCLASSEX);     // tell windows the size of this struct
	wc.hCursor = LoadCursor(NULL, MAKEINTRESOURCE(IDC_ARROW));        // tell it to use the normal arrow cursor for this window
	wc.hInstance = inst;                   // give it our program instance
	wc.lpfnWndProc = WndProc;                // tell it to use our wndProc function to handle messages
	wc.lpszClassName = TEXT("DisplayImage");   // give this window class a name.

	RegisterClassEx(&wc);           // register our window class with Windows

	// the style of the window we want... we want a normal window but do not want it resizable.
	int style = WS_OVERLAPPED WS_CAPTION | WS_SYSMENU;    // normal overlapped window with a caption and a system menu (the X to close)

	// Figure out how big we need to make the window so that the CLIENT area (the part we will be drawing to) is
	//  the desired size
	RECT rc = { 0, 0, screenSize_X, screenSize_Y };      // desired rect
	AdjustWindowRect(&rc, style, FALSE);              // adjust the rect with the given style, FALSE because there is no menu

	return CreateWindow(            // create the window
		TEXT("DisplayImage"),       // the name of the window class to use for this window (the one we just registered)
		TEXT("Display an Image"),   // the text to appear on the title of the window
		style | WS_VISIBLE,         // the style of this window (OR it with WS_VISIBLE so it actually becomes visible immediately)
		100, 100,                    // create it at position 100,100
		rc.right - rc.left,         // width of the window we want
		rc.bottom - rc.top,         // height of the window
		NULL, NULL,                  // no parent window, no menu
		inst,                       // our program instance
		NULL);                      // no extra parameter

}*/