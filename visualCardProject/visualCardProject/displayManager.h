#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#ifndef ADD_H
#define ADD_H

class displayManager{
public:
	//Function declaration
	LRESULT ActualWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK InitialWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK StaticWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
	HWND createWindow(HINSTANCE inst);
	void loadImage(const char* pathname);
	void cleanUpImage();
	void drawImage(HDC screen);
	
	displayManager(){
		// load our image
		loadImage("C:\\Users\\student\\Documents\\GitHub\\CardGameProject\\visualCardProject\\visualCardProject\\Images\\test.bmp");
	}
};//end of class

#endif 