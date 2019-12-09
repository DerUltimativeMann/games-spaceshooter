#include <stdio.h>
#include "gfx/oglhandler.h"

#define WND_REGISTRYNAME_MAIN "SeN_oglBasic_main"

LRESULT CALLBACK mainWndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR szCmdLine, int iCmdShow)
{
    WNDCLASS wndc;

    wndc.cbClsExtra = 0;
    wndc.cbWndExtra = 0;
    wndc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wndc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndc.hInstance = hInst;
    wndc.lpfnWndProc = mainWndProc;
    wndc.lpszClassName = WND_REGISTRYNAME_MAIN;
    wndc.lpszMenuName = NULL;
    wndc.style = CS_OWNDC;
    if(!RegisterClass(&wndc))
    {
        printf("ERR - registration failed!\n");
        return 0;
    }
    else
    {
        HWND hwnd = CreateWindow(WND_REGISTRYNAME_MAIN, "OpenGL Basics", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 256, 256, NULL, NULL, hInst, NULL);
        HDC hdc;
        HGLRC hrc;
        MSG msg;
        BOOL quit = FALSE;

        ShowWindow(hwnd, iCmdShow);
        enableOpenGl(hwnd, &hdc, &hrc);
        UpdateWindow(hwnd);

        while(!quit)
        {
            if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
            {
                switch(msg.message)
                {
                    case WM_QUIT:
                    quit = TRUE;
                    break;

                    default:
                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                }
            }
            else
            {
                glClearColor(0.3, 0.3, 0.3, 1.0);
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                glPushMatrix();
                glPopMatrix();
                SwapBuffers(hdc);
            }
        }

        disableOpenGl(hwnd, hdc, hrc);
        DestroyWindow(hwnd);
    }

    return 0;
}

LRESULT CALLBACK mainWndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch(msg)
    {
        case WM_CLOSE:
        PostQuitMessage(0);
        case WM_DESTROY:
        return 0;

        case WM_KEYDOWN:
        if(wp == VK_ESCAPE)
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, msg, wp, lp);
}
