#ifndef WINDOW_H_
#define WINDOW_H_

enum WINDOW_EVENT_TYPE {
    WINDOW_EVENT_NONE,
    WINDOW_EVENT_MOUSEMOVE,
    WINDOW_EVENT_MOUSEBUTTONDOWN,
    WINDOW_EVENT_MOUSEBUTTONUP,
    WINDOW_EVENT_KEYDOWN,
    WINDOW_EVENT_KEYUP,
    WINDOW_EVENT_QUIT
};

typedef struct {
    enum WINDOW_EVENT_TYPE type;
    int x, y;
    union {
        struct { int button; int state; } mouse;
        struct { int key; int state; } keyboard;
    };
} WindowEvent;

typedef struct {
    int x, y, w, h;
    void (*draw)(struct Window* self);
    void (*give)(struct Window* self, WindowEvent* evt);
} Window;

void WINDOW_CreateWindow(Window* new, int x, int y, int w, int h, void (*draw)(Window* self), void (*handle)(Window* self, WindowEvent* evt));
void WINDOW_DestroyWindow(Window* window);

#endif