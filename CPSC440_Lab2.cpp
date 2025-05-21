#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>
#include <stdlib.h>

//Draws a turtle
void makeTurtle(int x, int y);

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

    if (!al_install_keyboard()) {
        fprintf(stderr, "Event Queue Creation Failed\n");
        return(-1);
    }

    //Get events from keyboard
    al_register_event_source(EventQueue, al_get_keyboard_event_source());

    al_init_primitives_addon();
    al_register_event_source(EventQueue, al_get_display_event_source(display));

    bool exit = false;
    int x = 400;
    int y = 300;

    while (!exit) {
        al_clear_to_color(al_map_rgb(0, 0, 0));

        makeTurtle(x, y);

        al_flip_display();

        al_wait_for_event(EventQueue, &Event);

        if (Event.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (Event.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                    y -= 20;
                    break;
                case ALLEGRO_KEY_DOWN:
                    y += 20;
                    break;
                case ALLEGRO_KEY_LEFT:
                    x -= 20;
                    break;
                case ALLEGRO_KEY_RIGHT:
                    x += 20;
                    break;
                case ALLEGRO_KEY_ESCAPE:
                    exit = true;
                    break;
            }
        }

        if (Event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            exit = true;
        }
    }

    al_destroy_display(display);

    return 0;
}

void makeTurtle(int x, int y) {
    //Color Palette
    ALLEGRO_COLOR light_green = al_map_rgb(90, 145, 59);
    ALLEGRO_COLOR green = al_map_rgb(43, 70, 28);
    ALLEGRO_COLOR dark_green = al_map_rgb(25, 41, 16);
    ALLEGRO_COLOR white = al_map_rgb(245, 245, 245);
    ALLEGRO_COLOR black = al_map_rgb(10, 10, 10);

    //Make Head
    al_draw_filled_circle(x + 45, y, 18, light_green);

    //Make Eyes
    al_draw_filled_ellipse(x + 47, y + 12, 5, 3, white);
    al_draw_filled_ellipse(x + 47, y - 12, 5, 3, white); //might need to change 3 to 4

    al_draw_filled_ellipse(x + 47, y - 12, 4, 3, black);
    al_draw_filled_ellipse(x + 47, y + 12, 4, 3, black);

    //Make Tail
    al_draw_filled_triangle(x - 56, y + 5, x - 56, y - 5, x - 71, y, light_green);

    //Make Legs
    al_draw_filled_circle(x - 50, y - 25, 12, light_green);
    al_draw_filled_circle(x - 50, y + 25, 12, light_green);
    al_draw_filled_circle(x + 25, y - 25, 12, light_green);
    al_draw_filled_circle(x + 25, y + 25, 12, light_green);

    //Make Shell
    al_draw_filled_ellipse(x - 12, y, 50, 37, green);

    //Make Shell Lines
    al_draw_ellipse(x - 12, y, 50, 37, dark_green, 3);
    al_draw_line(x - 12, y, x - 50, y - 25, dark_green, 3);
    al_draw_line(x - 12, y, x - 50, y + 25, dark_green, 3);
    al_draw_line(x - 12, y, x + 25, y - 25, dark_green, 3);
    al_draw_line(x - 12, y, x + 25, y + 25, dark_green, 3);
    al_draw_line(x - 62, y, x + 37, y, dark_green, 3);
    al_draw_line(x - 12, y - 37, x - 12, y + 37, dark_green, 3);

    al_draw_filled_ellipse(x - 12, y, 20, 15, green);
    al_draw_ellipse(x - 12, y, 20, 15, dark_green, 3);
}

