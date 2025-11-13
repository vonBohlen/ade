#include <stdio.h>
#include <wayland-server.h>
#include <wlr/backend.h>

struct server {
    struct wl_display *wl_display;
    struct wl_event_loop *wl_event_loop;

    struct wlr_backend *wlr_backend;

    struct wl_listener *new_output;

    struct wl_list outputs;
};

int main() {
    struct server server;

    server.wl_display = wl_display_create();
    if (!server.wl_display) {
        return 1;
    }

    server.wl_event_loop = wl_display_get_event_loop(server.wl_display);
    if (!server.wl_event_loop) {
        return 1;
    }

    server.wlr_backend = wlr_backend_autocreate(server.wl_event_loop, NULL);
    if (!server.wlr_backend) {
        return 1;
    }

    wl_list_init(&server.outputs);
    server.new_output.notify = new_output_notify;

    if (!wlr_backend_start(server.wlr_backend)) {
        printf("Backend konnte nicht gestartet werden!");
        wl_display_destroy(server.wl_display);
        return 1;
    }

    wl_display_run(server.wl_display);
    wl_display_destroy(server.wl_display);

    return 0;
}