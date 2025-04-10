#include "wm.h"
#include <stddef.h>

void WM_CreateWM(WM* new) {
    new->count = 0;
    new->idx_focused = -1;
    for (int i = 0; i < WM_MAX_WINDOWS; ++i) {
        new->windows[i] = NULL;
        new->decoration[i] = WM_WINDOW_DECORATION_NONE;
        new->state[i] = WINDOW_STATE_NONE;
    }

    Window greet_box;
    WINDOW_CreateWindow(&greet_box, 30, 30, 250, 90, NULL, NULL);
    WM_AddWindow(new, &greet_box, WM_WINDOW_DECORATION_TITLEBAR_BORDER);
}

void WM_DestroyWM(WM* self) {
    for (int i = 0; i < self->count; ++i)
        if (self->windows[i])
            self->windows[i] = NULL;

    self->count = 0;
}

void WM_AddWindow(WM* self, Window* new, enum WM_WDECORATION decoration) {
    if (self->count < WM_MAX_WINDOWS) {
        self->windows[self->count] = new;
        self->decoration[self->count] = decoration;
        self->state[self->count] = WINDOW_STATE_VISIBLE;
        ++self->count;
    }
}

void WM_RemoveWindow(WM* self, Window* window) {
    if (self->windows[self->count - 1] == window) {
        self->windows[self->count - 1] = NULL;
        --self->count;
        return;
    }

    for (int i = 0; i < self->count; ++i)
        if (self->windows[i] == window) {

            for (int j = i; j < self->count - 1; ++j) {
                self->windows[j] = self->windows[j + 1];
                self->decoration[j] = self->decoration[j + 1];
                self->state[j] = self->state[j + 1];
            }
            
            self->windows[self->count - 1] = NULL;
            --self->count;
            break;
        }
}

void WM_SetWindowState(WM* self, Window* window, enum WM_WSTATE state) {
    if (state == WINDOW_STATE_FOCUSED)
        WM_FocusWindow(self, window);

    else
        for (int i = 0; i < self->count; ++i)
            if (self->windows[i] == window) {
                self->state[i] = state;
                break;
            }
}

void WM_SetWindowDecoration(WM* self, Window* window, enum WM_WDECORATION decoration) {
    for (int i = 0; i < self->count; ++i)
        if (self->windows[i] == window) {
            self->decoration[i] = decoration;
            break;
        }
}

void WM_FocusWindow(WM* self, Window* window) {
    if (self->idx_focused != -1 && self->windows[self->idx_focused] == window)
        return;

    Window* to_focus_window = NULL;
    enum WM_WDECORATION to_focus_decoration = WM_WINDOW_DECORATION_NONE;

    if (self->idx_focused != -1)
        self->state[self->idx_focused] = WINDOW_STATE_VISIBLE;

    if (self->windows[self->count - 1] == window) {
        self->idx_focused = self->count - 1;
        self->state[self->idx_focused] = WINDOW_STATE_FOCUSED;
        return;
    }

    for (int i = 0; i < self->count - 1; ++i) {
        if (self->windows[i] == window) {
            to_focus_window = self->windows[i];
            to_focus_decoration = self->decoration[i];
            
            for (int j = i; j < self->count - 1; ++j) {
                self->windows[j] = self->windows[j + 1];
                self->decoration[j] = self->decoration[j + 1];
                self->state[j] = self->state[j + 1];
            }
            
            self->windows[self->count - 1] = to_focus_window;
            self->decoration[self->count - 1] = to_focus_decoration;
            self->state[self->count - 1] = WINDOW_STATE_FOCUSED;
            self->idx_focused = self->count - 1;
            break;
        }
    }
}

void WM_UnfocusWindow(WM* self) {
    if (self->idx_focused != -1)
        self->state[self->idx_focused] = WINDOW_STATE_VISIBLE;
    
    self->idx_focused = -1;
}

Window** WM_GetWindowArray(WM* self) { return self->windows; }
int WM_GetWindowCount(WM* self) { return self->count; }

Window* WM_GetWindowAt(WM* self, int x, int y) {
    for (int i = 0; i < self->count; ++i)
        if (self->windows[i] && self->state[i] != WINDOW_STATE_NONE) {
            int gx = self->windows[i]->x;
            int gy = self->windows[i]->y;
            int gw = self->windows[i]->w;
            int gh = self->windows[i]->h;

            if (x >= gx && x < gx + gw && y >= gy && y < gy + gh)
                return self->windows[i];
        }

    return NULL;
}