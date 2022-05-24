#include <stdlib.h>
#include <string.h>

#include <xcb/xcb.h>

int main(void)
{
    xcb_connection_t *p_conn;
    xcb_screen_t *p_screen;
    xcb_window_t window;
    xcb_gcontext_t foreground;
    xcb_gcontext_t background;
    xcb_generic_event_t *p_event;
    uint32_t mask = 0;
    uint32_t values[2];
    uint8_t is_quit = 0;

    char title[] = "Hello, Engine!";
    char title_icon[] = "Hello, Engine! (iconified)";

    // establish connection to X server
    p_conn = xcb_connect(0, 0);

    // get the first screen
    p_screen = xcb_setup_roots_iterator(xcb_get_setup(p_conn)).data;

    // get the root window
    window = p_screen->root;

    // create black (foreground) graphic context
    foreground = xcb_generate_id(p_conn);
    mask = XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES;
    values[0] = p_screen->black_pixel;
    values[1] = 0;
    xcb_create_gc(p_conn, foreground, window, mask, values);

    /* create white (background) graphic context */
    background = xcb_generate_id(p_conn);
    mask = XCB_GC_BACKGROUND | XCB_GC_GRAPHICS_EXPOSURES;
    values[0] = p_screen->white_pixel;
    values[1] = 0;
    xcb_create_gc(p_conn, background, window, mask, values);

    /* create window */
    window = xcb_generate_id(p_conn);
    mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
    values[0] = p_screen->white_pixel;
    values[1] = XCB_EVENT_MASK_EXPOSURE | XCB_EVENT_MASK_KEY_PRESS;
    xcb_create_window(p_conn,                                       /* connection */
                      XCB_COPY_FROM_PARENT,        /* depth */
                      window,                                      /* window ID */
                      p_screen->root,                       /* parent window */
                      20, 20,                                      /* x, y */
                      640, 480,                            /* width, height */
                      10,                                          /* boarder width */
                      XCB_WINDOW_CLASS_INPUT_OUTPUT, /* class */
                      p_screen->root_visual,        /* visual */
                      mask, values);                       /* masks */

    /* set the title of the window */
    xcb_change_property(p_conn, XCB_PROP_MODE_REPLACE, window,
                        XCB_ATOM_WM_NAME, XCB_ATOM_STRING, 8,
                        strlen(title), title);

    /* set the title of the window icon */
    xcb_change_property(p_conn, XCB_PROP_MODE_REPLACE, window,
                        XCB_ATOM_WM_ICON_NAME, XCB_ATOM_STRING, 8,
                        strlen(title_icon), title_icon);

    /* map the window on the screen */
    xcb_map_window(p_conn, window);

    xcb_flush(p_conn);

    while ((p_event = xcb_wait_for_event(p_conn)) && !is_quit) {
        switch (p_event->response_type & ~0x80) {
            case XCB_EXPOSE:
                break;
            case XCB_KEY_PRESS:
                is_quit = 1;
                break;
        }
        free(p_event);
    }

    return 0;
}
