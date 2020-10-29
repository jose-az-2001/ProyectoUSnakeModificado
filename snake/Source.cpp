#include <iostream>
#include "Alimento.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
using namespace std;

int main() {
	//variables
	bool salir = false, menuprincipal = true;
	int x = 0, y = 0, botonmenu = 0, direccion = 0;
	Alimento Manzana = Alimento(1);
	Alimento Fresa = Alimento(2);
	Alimento Banano = Alimento(3);
	Alimento Pera = Alimento(-1);
	Alimento Piña = Alimento(-5);
	//iniciacion Allegro
	al_init();
	al_install_mouse();
	al_install_keyboard();
	al_init_image_addon();
	al_init_primitives_addon();

	ALLEGRO_DISPLAY* Menu = al_create_display(400, 700);
	al_set_window_title(Menu, "MENU SNAKE");
	ALLEGRO_DISPLAY* Tablero;
	ALLEGRO_BITMAP* Imamenu = al_load_bitmap("Imagenes/Snake Principal.png");
	ALLEGRO_COLOR map = al_map_rgb(120, 51, 36);
	ALLEGRO_COLOR colorserpiente = al_map_rgb(40, 255, 13);
	ALLEGRO_EVENT_QUEUE* eventoqueue = al_create_event_queue();
	al_register_event_source(eventoqueue, al_get_mouse_event_source());
	al_register_event_source(eventoqueue, al_get_keyboard_event_source());
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
				al_set_window_title(Tablero, "SNAKE");
				al_clear_to_color(map);
				menuprincipal = false;
				al_draw_filled_rectangle(0, 0, 40, 40, colorserpiente);
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

		if (Evento.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (Evento.keyboard.keycode)
			{
			case ALLEGRO_KEY_DOWN:
				cout << "tecla abajo" << endl;
				direccion = 3;
				break;
			case ALLEGRO_KEY_UP:
				cout << "tecla arriba" << endl;
				direccion = 1;
				break;
			case ALLEGRO_KEY_LEFT:
				cout<<"tecla izquierda" << endl;
				direccion = 4;
				break;
			case ALLEGRO_KEY_RIGHT:
				cout << "tecla derecha" << endl;
				direccion = 2;
				break;
			default:
				break;
			}
		}





		al_flip_display();
	}


	return 0;
}