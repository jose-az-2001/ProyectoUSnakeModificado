#include <iostream>
#include <string>
#include "Alimento.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
using namespace std;

int main() {
	//variables
	bool salir = false, menuprincipal = true;
	int x = 0, y = 0, botonmenu = 0, direccion = 0, xserpiente = 0, yserpiente = 0 ;
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
	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_DISPLAY* Menu = al_create_display(400, 700);
	al_set_window_title(Menu, "MENU SNAKE");
	ALLEGRO_DISPLAY* Tablero;
	ALLEGRO_BITMAP* Imamenu = al_load_bitmap("Imagenes/Snake Principal.png");
	ALLEGRO_COLOR map = al_map_rgb(120, 51, 36);
	ALLEGRO_COLOR colorserpiente = al_map_rgb(40, 255, 13);
	ALLEGRO_FONT* Gameplay = al_load_font("Gameplay.ttf", 50, 0);
	ALLEGRO_TIMER* segundoTimer = al_create_timer(0.1);
	ALLEGRO_EVENT_QUEUE* eventoqueue = al_create_event_queue();
	ALLEGRO_EVENT Evento;
	al_register_event_source(eventoqueue, al_get_timer_event_source(segundoTimer));
	al_register_event_source(eventoqueue, al_get_mouse_event_source());
	al_register_event_source(eventoqueue, al_get_keyboard_event_source());
	al_start_timer(segundoTimer);
	int seg = 0;
	while (salir == false) {
		al_wait_for_event(eventoqueue, &Evento);
		if (Evento.type == ALLEGRO_EVENT_TIMER) {
			if (Evento.timer.source == segundoTimer) {
				seg++;
			}
		}
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

		if (menuprincipal == false) {
			al_clear_to_color(map);
			al_draw_filled_rectangle(xserpiente, yserpiente, xserpiente + 40, yserpiente + 40, colorserpiente);
			al_draw_text(Gameplay, colorserpiente, 200, 475, NULL, ("Segundo: " + to_string(seg)).c_str());
		}

		if (Evento.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (Evento.keyboard.keycode)
			{
			case ALLEGRO_KEY_DOWN:
				cout << "tecla abajo" << endl;
				direccion = 3;
				seg = 1;
				break;
			case ALLEGRO_KEY_UP:
				cout << "tecla arriba" << endl;
				direccion = 1;
				seg = 1;
				break;
			case ALLEGRO_KEY_LEFT:
				cout<<"tecla izquierda" << endl;
				direccion = 4;
				seg = 1;
				break;
			case ALLEGRO_KEY_RIGHT:
				cout << "tecla derecha" << endl;
				direccion = 2;
				break;
				seg = 1;
			default:
				break;
			}
		}

		if (direccion == 3) {
			if (seg % 10 == 0) {
				yserpiente = yserpiente + 40;
			}
		}
		if (direccion == 1) {
			if (seg % 10 == 0) {
				yserpiente = yserpiente - 40;
			}
		}
		if (direccion == 4) {
			if (seg % 10 == 0) {
				xserpiente = xserpiente - 40;
			}
		}
		if (direccion == 2) {
			if (seg % 10 == 0) {
				xserpiente = xserpiente + 40;
			}
		}



		al_flip_display();
	}


	return 0;
}