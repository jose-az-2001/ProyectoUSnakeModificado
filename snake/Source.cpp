#include <iostream>
#include <string>
#include <time.h>
#include "Alimento.h"
#include "Lista.h"
#include "Cola.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
using namespace std;

int main() {
	//variables
	srand(time(NULL));
	bool salir = false, menuprincipal = true, alimentoactivo = false, difactivada = false, juego = false, puntajes = false, agregarpunt = false, bandera = false;
	int x = 0, y = 0, botonmenu = 0, direccion = 0, xserpiente = 0, yserpiente = 0, velocidad = 10;
	int probalim = 0, posxalim = 0, posyalim = 0, cascrece = 0;
	int lad1x = 0, lad1y = 0, lad2x = 0, lad2y = 0, col1x = 0, col1y = 0, col2x = 0, col2y = 0, paredx = 0, paredy = 0;
	Alimento Manzana = Alimento(1);
	Alimento Fresa = Alimento(2);
	Alimento Banano = Alimento(3);
	Alimento Pera = Alimento(-1);
	Alimento Pinia = Alimento(-5);
	Cola Serpiente = Cola();
	Lista Puntos = Lista();
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
	ALLEGRO_BITMAP* TabPunt = al_load_bitmap("Imagenes/Puntajes.png");
	ALLEGRO_COLOR map = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR ladrillo = al_map_rgb(153, 10, 10);
	ALLEGRO_COLOR White = al_map_rgb(255, 255, 255);
	ALLEGRO_FONT* Gameplay = al_load_font("Gameplay.ttf", 30, 0);
	ALLEGRO_TIMER* segundoTimer = al_create_timer(0.1);
	ALLEGRO_EVENT_QUEUE* eventoqueue = al_create_event_queue();
	ALLEGRO_EVENT Evento;
	al_register_event_source(eventoqueue, al_get_timer_event_source(segundoTimer));
	al_register_event_source(eventoqueue, al_get_mouse_event_source());
	al_register_event_source(eventoqueue, al_get_keyboard_event_source());
	al_start_timer(segundoTimer);
	int seg = 0, seguvelo = 0;
	while (salir == false) {
		//Eventos
		al_wait_for_event(eventoqueue, &Evento);
		if (Evento.type == ALLEGRO_EVENT_TIMER) {
			if (Evento.timer.source == segundoTimer) {
				seg++;
				seguvelo++;
			}
		}
		if (Evento.type == ALLEGRO_EVENT_MOUSE_AXES) {
			x = Evento.mouse.x;
			y = Evento.mouse.y;
		}
		if (Evento.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (Evento.keyboard.keycode)
			{
			case ALLEGRO_KEY_DOWN:
				direccion = 3;
				seg = 1;
				break;
			case ALLEGRO_KEY_UP:
				direccion = 1;
				seg = 1;
				break;
			case ALLEGRO_KEY_LEFT:
				direccion = 4;
				seg = 1;
				break;
			case ALLEGRO_KEY_RIGHT:
				direccion = 2;
				seg = 1;
				break;
			default:
				break;
			}
		}
		//Menu principal
		if (menuprincipal == true) {
			if (botonmenu == 0) {
				al_draw_bitmap(Imamenu, 0, 0, 0);
			}
			if (botonmenu != 0) {
				Tablero = al_create_display(1000, 1000);
				al_set_window_title(Tablero, "SNAKE");
				al_clear_to_color(map);
				Serpiente.Agregar(xserpiente, yserpiente);
				Serpiente.Agregar(xserpiente, yserpiente);
				Serpiente.Agregar(xserpiente, yserpiente);
				Serpiente.Agregar(xserpiente, yserpiente);
				if (Serpiente.ObtenerTamanio() < 4) {
					juego = false;
					puntajes = true;
				}
				menuprincipal = false;
				juego = true;
			}
			if (Evento.mouse.button & 1) {
				if (x >= 85 && x <= 324 && y >= 190 && y <= 254) {
					botonmenu = 1;
					velocidad = 10;
				}
				if (x >= 85 && x <= 324 && y >= 304 && y <= 365) {
					botonmenu = 2;
					velocidad = 5;
					difactivada = true;
				}
				if (x >= 85 && x <= 324 && y >= 415 && y <= 483) {
					botonmenu = 3;
					velocidad = 3;
					difactivada = true;
				}
				if (x >= 85 && x <= 324 && y >= 529 && y <= 594) {
					botonmenu = 4;
					if (velocidad > 0) {
						if (seguvelo == 300) {
							velocidad--;
						}
					}
					difactivada = true;
				}
			}
		}
		//durante el juego
		if (juego == true) {
			
			al_clear_to_color(map);
			Serpiente.Recorrer();
			al_draw_text(Gameplay, ladrillo, 750, 960, NULL, ("Punteo: " + to_string(Serpiente.ObtenerTamanio()-4)).c_str());
			if (probalim <= 40) {
				al_draw_filled_circle(((posxalim * 40) + 20), ((posyalim * 40) + 20), 20, al_map_rgb(255, 0, 0));
			}
			if (probalim >= 41 && probalim <= 65) {
				al_draw_filled_ellipse(((posxalim * 40) + 20), ((posyalim * 40) + 20), 10, 20, al_map_rgb(249, 82, 130));
			}
			if (probalim >= 66 && probalim <= 85) {
				al_draw_filled_ellipse(((posxalim * 40) + 20), ((posyalim * 40) + 20), 20, 5, al_map_rgb(255, 255, 0));
			}
			if (probalim >= 86 && probalim <= 90) {
				al_draw_filled_ellipse(((posxalim * 40) + 20), ((posyalim * 40) + 20), 15, 20, al_map_rgb(255, 255, 0));
			}
			if (probalim >= 91 && probalim <= 100) {
				al_draw_filled_circle(((posxalim * 40) + 20), ((posyalim * 40) + 20), 20, al_map_rgb(52, 180, 11));
			}
			if (posxalim * 40 == xserpiente && posyalim * 40 == yserpiente) {
				if (probalim <= 40) {
					cascrece=Manzana.ObtenerValor();
				}
				if (probalim >= 41 && probalim <= 65) {
					cascrece = Fresa.ObtenerValor();
				}
				if (probalim >= 66 && probalim <= 85) {
					cascrece = Banano.ObtenerValor();
				}
				if (probalim >= 86 && probalim <= 90) {
					cascrece = Pinia.ObtenerValor();
				}
				if (probalim >= 91 && probalim <= 100) {
					cascrece = Pera.ObtenerValor();
				}
				if (cascrece < 0) {
					for (int a = 0; a > cascrece; a--) {
						Serpiente.Eliminar();
						alimentoactivo = false;
					}
				}
				if (cascrece > 0) {
					for (int a = 0; a < cascrece; a++) {
						Serpiente.Agregar(xserpiente, yserpiente);
						alimentoactivo = false;
					}
				}
			}
			if (direccion == 3) {
				if (seg % velocidad == 0) {
					yserpiente = yserpiente + 40;
					Serpiente.Eliminar();
					Serpiente.Agregar(xserpiente, yserpiente);
				}
			}
			if (direccion == 1) {
				if (seg % velocidad == 0) {
					yserpiente = yserpiente - 40;
					Serpiente.Eliminar();
					Serpiente.Agregar(xserpiente, yserpiente);
				}
			}
			if (direccion == 4) {
				if (seg % velocidad == 0) {
					xserpiente = xserpiente - 40;
					Serpiente.Eliminar();
					Serpiente.Agregar(xserpiente, yserpiente);
				}
			}
			if (direccion == 2) {
				if (seg % velocidad == 0) {
					xserpiente = xserpiente + 40;
					Serpiente.Eliminar();
					Serpiente.Agregar(xserpiente, yserpiente);
				}
			}
			if (alimentoactivo == false) {
				probalim = 1 + rand() % (101 - 1);
				posxalim = rand() % 25;
				posyalim = rand() % 25;
				alimentoactivo = true;
			}
			//terminar juego
			if (xserpiente < -1 || xserpiente >= 1000 || yserpiente < -1 || yserpiente >= 1000) {
				juego = false;
				puntajes = true;
				agregarpunt = true;
			}
			//Obstaculos por dificultad
			if (difactivada == true) {
				lad1x = (rand() % 25) * 40;
				lad1y = (rand() % 25) * 40;
				lad2x = (rand() % 25) * 40;
				lad2y = (rand() % 25) * 40;
				col1x = (rand() % 24) * 40;
				col1y = (rand() % 24) * 40;
				col2x = (rand() % 24) * 40;
				col2y = (rand() % 24) * 40;
				paredx = (rand() % 25) * 40;
				paredy = (rand() % 19) * 40;
				difactivada = false;
			}
			if (botonmenu == 2) {
				al_draw_filled_rectangle(lad1x, lad1y, lad1x + 40, lad1y + 40, ladrillo);
				al_draw_filled_rectangle(lad2x, lad2y, lad2x + 40, lad2y + 40, ladrillo);
				al_draw_filled_rectangle(col1x, col1y, col1x + 80, col1y + 80, ladrillo);
				if (xserpiente == lad1x && lad1y == yserpiente) {
					juego = false;
					puntajes = true;
					agregarpunt = true;
				}
				if (xserpiente == lad2x && lad2y == yserpiente) {
					juego = false;
					puntajes = true;
					agregarpunt = true;
				}
				if (xserpiente >= col1x && yserpiente >= col1y && xserpiente <= col1x + 45 && yserpiente <= col1y + 45) {
					juego = false;
					puntajes = true;
					agregarpunt = true;
				}
			}
			if (botonmenu == 3 || botonmenu == 4) {
				al_draw_filled_rectangle(lad1x, lad1y, lad1x + 40, lad1y + 40, ladrillo);
				al_draw_filled_rectangle(lad2x, lad2y, lad2x + 40, lad2y + 40, ladrillo);
				al_draw_filled_rectangle(col1x, col1y, col1x + 80, col1y + 80, ladrillo);
				al_draw_filled_rectangle(col2x, col2y, col2x + 80, col2y + 80, ladrillo);
				al_draw_filled_rectangle(paredx, paredy, paredx + 40, paredy + 240, ladrillo);
				if (xserpiente == lad1x && lad1y == yserpiente) {
					juego = false;
					puntajes = true;
					agregarpunt = true;
				}
				if (xserpiente == lad2x && lad2y == yserpiente) {
					juego = false;
					puntajes = true;
					agregarpunt = true;
				}
				if (xserpiente >= col1x && yserpiente >= col1y && xserpiente <= col1x + 45 && yserpiente <= col1y + 45) {
					juego = false;
					puntajes = true;
					agregarpunt = true;
				}
				if (xserpiente >= col2x && yserpiente >= col2y && xserpiente <= col2x + 45 && yserpiente <= col2y + 45) {
					juego = false;
					puntajes = true;
					agregarpunt = true;
				}
				if (xserpiente >= paredx && yserpiente >= paredy && xserpiente <= paredx + 20 && yserpiente <= paredy + 245) {
					juego = false;
					puntajes = true;
					agregarpunt = true;
				}
			}
			if (agregarpunt == true) {
				if (Puntos.ObtenerTamanio() == 0) {
					Puntos.InsertarInicio(Serpiente.ObtenerTamanio() - 4);
				}
				else {
					for (int i = 0; i < Puntos.ObtenerTamanio(); i++) {
						if (Puntos.BuscarPosicion(i)->ObtenerNumero() < (Serpiente.ObtenerTamanio() - 4)) {
							Puntos.InsertarAntes((Serpiente.ObtenerTamanio() - 4), Puntos.BuscarPosicion(i)->ObtenerNumero());
							bandera = true;
							break;
						}

					}
					if (bandera == false) {
						Puntos.InsertarFinal(Serpiente.ObtenerTamanio() - 4);
					}
					bandera = false;
				}
				agregarpunt = false;
			}
		}
		
		//Pantalla de puntajes
		
		if (puntajes == true) {
			al_draw_bitmap(TabPunt, 0, 0, 0);
			int cantidad;
			if (Puntos.ObtenerTamanio() < 5) {
				cantidad = Puntos.ObtenerTamanio();
			}
			else {
				cantidad = 5;
			}
			int altletras = 364;
			for (int j = 0; j < cantidad; j++) {
				string pun = "Puntos: "+to_string(Puntos.BuscarPosicion(j)->ObtenerNumero());
				al_draw_text(Gameplay, White, 420,altletras,NULL, (pun.c_str()));
				altletras = altletras + 100;
			}


			if (Evento.type == ALLEGRO_EVENT_KEY_DOWN) {
				switch (Evento.keyboard.keycode)
				{
				case ALLEGRO_KEY_ENTER:
					puntajes = false;
					juego = true;
					for (int i = Serpiente.ObtenerTamanio(); i > 0; i--) {
						Serpiente.Eliminar();
					}
					xserpiente = 0;
					yserpiente = 0;
					Serpiente.Agregar(xserpiente, yserpiente);
					Serpiente.Agregar(xserpiente, yserpiente);
					Serpiente.Agregar(xserpiente, yserpiente);
					Serpiente.Agregar(xserpiente, yserpiente);
					alimentoactivo = false;
					direccion = 0;
					break;
				case ALLEGRO_KEY_ESCAPE:
					salir = true;
					break;
				default:
					break;
				}
			}

		}
		al_flip_display();
	}
	return 0;
}