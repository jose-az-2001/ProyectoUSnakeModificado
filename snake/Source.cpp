#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
using namespace std;

int main() {
	//variables
	bool salir = false;
	int x = 0, y = 0;
	al_init();
	al_install_mouse();
	al_install_keyboard();
	al_init_image_addon();

	ALLEGRO_DISPLAY* Menu = al_create_display(400, 700);
	ALLEGRO_BITMAP* Imamenu = al_load_bitmap("Imagenes/Snake Principal.png");
	ALLEGRO_BITMAP* Imamenufa = al_load_bitmap("Imagenes/Snake Facil.png");
	ALLEGRO_BITMAP* Imamenuint = al_load_bitmap("Imagenes/Snake Intermedio.png");
	ALLEGRO_BITMAP* Imamenudif = al_load_bitmap("Imagenes/Snake Dificil.png");
	ALLEGRO_BITMAP* Imamenudin = al_load_bitmap("Imagenes/Snake Dinamico.png");

	while (salir == false) {
		al_draw_bitmap(Imamenu, 0, 0, 0);
		al_flip_display();
	}


	return 0;
}