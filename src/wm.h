#ifndef WM_H_
#define WM_H_

#include "window.h"

#define WM_MAX_WINDOWS 64

enum WM_WSTATE {
    WINDOW_STATE_NONE,
    WINDOW_STATE_VISIBLE,
    WINDOW_STATE_FOCUSED
};

enum WM_WDECORATION {
    WM_WINDOW_DECORATION_NONE,
    WM_WINDOW_DECORATION_TITLEBAR,
    WM_WINDOW_DECORATION_BORDER,
    WM_WINDOW_DECORATION_TITLEBAR_BORDER,
    WM_WINDOW_DECORATION_MESSAGEBOX
};

typedef struct {
    Window* windows[WM_MAX_WINDOWS];
    enum WM_WDECORATION decoration[WM_MAX_WINDOWS];
    enum WM_WSTATE state[WM_MAX_WINDOWS];
    int count, idx_focused;
} WM;

void WM_CreateWM(WM* new);
void WM_DestroyWM(WM* self);

void WM_AddWindow(WM* self, Window* new, enum WM_WDECORATION decoration);
void WM_RemoveWindow(WM* self, Window* window);

void WM_SetWindowState(WM* self, Window* window, enum WM_WSTATE state);
void WM_SetWindowDecoration(WM* self, Window* window, enum WM_WDECORATION decoration);
void WM_FocusWindow(WM* self, Window* window);

Window** WM_GetWindowArray(WM* self);
int WM_GetWindowCount(WM* self);

Window* WM_GetWindowAt(WM* self, int x, int y);

#endif