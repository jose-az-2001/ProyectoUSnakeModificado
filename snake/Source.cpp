#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
using namespace std;

int main() {
	//variables
	bool salir = false, menuprincipal = true;
	int x = 0, y = 0, botonmenu = 0;
	al_init();
	al_install_mouse();
	al_install_keyboard();
	al_init_image_addon();

	ALLEGRO_DISPLAY* Menu = al_create_display(400, 700);
	ALLEGRO_DISPLAY* Tablero;
	ALLEGRO_BITMAP* Imamenu = al_load_bitmap("Imagenes/Snake Principal.png");
	ALLEGRO_COLOR map = al_map_rgb(120, 51, 36);
	ALLEGRO_EVENT_QUEUE* eventoqueue = al_create_event_queue();
	al_register_event_source(eventoqueue, al_get_mouse_event_source());
	ALLEGRO_EVENT Evento;
	

	while (salir == false) {
		al_wait_for_event(eventoqueue, &Evento);
		if (Evento.type == ALLEGRO_EVENT_MOUSE_AXES) {
			x = Evento.mouse.x;
			y = Evento.mouse.y;
		}
		
		if (menuprincipal == true) {
			if (botonmenu == 0) {
				al_draw_bitmap(Imamenu, 0, 0, 0);
			}
			if (botonmenu != 0) {
				Tablero = al_create_display(1000, 1000);
				al_clear_to_color(map);
				menuprincipal = false;
			}
			if (Evento.mouse.button & 1) {
				if (x >= 85 && x <= 324 && y >= 190 && y <= 254) {
					botonmenu = 1;
				}
				if (x >= 85 && x <= 324 && y >= 304 && y <= 365) {
					botonmenu = 2;
				}
				if (x >= 85 && x <= 324 && y >= 415 && y <= 483) {
					botonmenu = 3;
				}
				if (x >= 85 && x <= 324 && y >= 529 && y <= 594) {
					botonmenu = 4;
				}
			}
		}
		





		al_flip_display();
	}


	return 0;
}