#ifndef _OGLHANDLER_H
#define _OGLHANDLER_H

#include <GL/gl.h>
#include <windows.h>

void enableOpenGl(HWND, HDC*, HGLRC*);
void disableOpenGl(HWND, HDC, HGLRC);

#endif
