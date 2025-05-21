#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    ALLEGRO_DISPLAY* display = NULL;

    if (!al_init()) {
        fprintf(stderr, "Allegro Initialization Failed\n");
        return(-1);
    }

    display = al_create_display(800, 600);
    if (!display) {
        fprintf(stderr, "Display Creation Failed\n");
        return(-1);
    }

    ALLEGRO_EVENT_QUEUE *EventQueue = NULL;
    ALLEGRO_EVENT Event;

    EventQueue = al_create_event_queue();
    if (!EventQueue) {
        fprintf(stderr, "Event Queue Creation Failed\n");
        return(-1);
    }

    al_clear_to_color(al_map_rgb(0, 0, 0));

    al_flip_display();

    al_rest(5.0);

    al_destroy_display(display);

    return 0;
}

