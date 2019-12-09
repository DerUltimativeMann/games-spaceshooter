#include "oglhandler.h"


void enableOpenGl(HWND hwnd, HDC *hdc, HGLRC *hrc)
{
    PIXELFORMATDESCRIPTOR pfd;
    //int i;

    *hdc = GetDC(hwnd);
    ZeroMemory(&pfd, sizeof(pfd));

    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    //i = ChoosePixelFormat(*hdc, &pfd);
    SetPixelFormat(*hdc, ChoosePixelFormat(*hdc, &pfd), &pfd);
    *hrc = wglCreateContext(*hdc);
    wglMakeCurrent(*hdc, *hrc);
}


void disableOpenGl(HWND hwnd, HDC hdc, HGLRC hrc)
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hrc);
    ReleaseDC(hwnd, hdc);
}
