#ifndef CONSTANTES_H
#define CONSTANTES_H 
#include "geometria.h"
#include "gl2.h"
#include <string>
#include "imagen/gestor.h"

#define MUSIC_GAME8b "music8b.ogg"
#define MUSIC_GAME "music.ogg"

const int jugador_x = 25;
const int jugador_y = 57;

Color fondo_renders;

const _2D::Punto<double> v_mov(8,0);
const _2D::Punto<double> v_salto(0,30);
const _2D::Punto<double> v_grav(0,-2);
const _2D::Punto<double> v_friccion(0.7,0.7);

const Color ColorMuros = Color::blanco;

const int delay = 40;
const int IZQUIERDA  = 0;
const int DERECHA = 1;

const int SCREEN_X = 400;
const int SCREEN_Y = 300;
const char * WINDOW_NAME = "Gintama";

GestorImagenes renders = GestorImagenes();

Imagen* GINTOKI_STAND1 = new Imagen();
Imagen* GINTOKI_STAND2 = new Imagen();
Imagen* GINTOKI_STAND3 = new Imagen();
Imagen* GINTOKI_STAND4 = new Imagen();

Imagen* GINTOKI_PASO1 = new Imagen();
Imagen* GINTOKI_PASO2 = new Imagen();
Imagen* GINTOKI_PASO3 = new Imagen();
Imagen* GINTOKI_PASO4 = new Imagen();
Imagen* GINTOKI_PASO5 = new Imagen();
Imagen* GINTOKI_PASO6 = new Imagen();
Imagen* GINTOKI_PASO7 = new Imagen();
Imagen* GINTOKI_PASO8 = new Imagen();

Imagen* GINTOKI_SALTO1 = new Imagen();
Imagen* GINTOKI_SALTO2 = new Imagen();
Imagen* GINTOKI_SALTO3 = new Imagen();

Imagen* GINTOKI_AIRE1 = new Imagen();
Imagen* GINTOKI_AIRE2 = new Imagen();

Imagen* GINTOKI_SUELO1 = new Imagen();
Imagen* GINTOKI_SUELO2 = new Imagen();
Imagen* GINTOKI_SUELO3 = new Imagen();

Imagen* GINTOKI_GOLPE1 = new Imagen();
Imagen* GINTOKI_GOLPE2 = new Imagen();
Imagen* GINTOKI_GOLPE3 = new Imagen();
Imagen* GINTOKI_GOLPE4 = new Imagen();
Imagen* GINTOKI_GOLPE5 = new Imagen();
Imagen* GINTOKI_GOLPE6 = new Imagen();
Imagen* GINTOKI_GOLPE7 = new Imagen();




void cargaRenders(){
	fondo_renders = renders["Gintoki.bmp"]->en(0,0);
	renders["Gintoki.bmp"]->region(8,2498,jugador_x,jugador_y,GINTOKI_STAND1);
	renders["Gintoki.bmp"]->region(39,2498,jugador_x,jugador_y,GINTOKI_STAND2);
	renders["Gintoki.bmp"]->region(72,2498,jugador_x,jugador_y,GINTOKI_STAND3);
	renders["Gintoki.bmp"]->region(106,2498,jugador_x,jugador_y,GINTOKI_STAND4);

	renders["Gintoki.bmp"]->region(195,2498,jugador_x+15,jugador_y,GINTOKI_PASO1);
	renders["Gintoki.bmp"]->region(242,2498,jugador_x+10,jugador_y,GINTOKI_PASO2);
	renders["Gintoki.bmp"]->region(282,2498,jugador_x+10,jugador_y,GINTOKI_PASO3);
	renders["Gintoki.bmp"]->region(323,2498,jugador_x+10,jugador_y,GINTOKI_PASO4);
	renders["Gintoki.bmp"]->region(364,2498,jugador_x+13,jugador_y,GINTOKI_PASO5);
	renders["Gintoki.bmp"]->region(410,2498,jugador_x+8,jugador_y,GINTOKI_PASO6);
	renders["Gintoki.bmp"]->region(448,2498,jugador_x+8,jugador_y,GINTOKI_PASO7);
	renders["Gintoki.bmp"]->region(485,2498,jugador_x+12,jugador_y,GINTOKI_PASO8);
	
	renders["Gintoki.bmp"]->region(304,2390,jugador_x+10,jugador_y,GINTOKI_SALTO1);
	renders["Gintoki.bmp"]->region(346,2400,jugador_x+12,jugador_y,GINTOKI_SALTO2);
	renders["Gintoki.bmp"]->region(388,2408,jugador_x+16,jugador_y,GINTOKI_SALTO3);

	renders["Gintoki.bmp"]->region(438,2408,jugador_x+22,jugador_y,GINTOKI_AIRE1);
	renders["Gintoki.bmp"]->region(491,2400,jugador_x+22,jugador_y,GINTOKI_AIRE2);
	
	renders["Gintoki.bmp"]->region(546,2390,jugador_x+10,jugador_y,GINTOKI_SUELO1);
	renders["Gintoki.bmp"]->region(586,2390,jugador_x+14,jugador_y,GINTOKI_SUELO2);
	renders["Gintoki.bmp"]->region(631,2390,jugador_x+10,jugador_y,GINTOKI_SUELO3);
	
	renders["Gintoki.bmp"]->region(293,1845,jugador_x+16,jugador_y,GINTOKI_GOLPE1);
	renders["Gintoki.bmp"]->region(340,1845,jugador_x+16,jugador_y,GINTOKI_GOLPE2);
	renders["Gintoki.bmp"]->region(386,1845,jugador_x+43,jugador_y,GINTOKI_GOLPE3);
	renders["Gintoki.bmp"]->region(458,1845,jugador_x+22,jugador_y,GINTOKI_GOLPE4);
	renders["Gintoki.bmp"]->region(512,1845,jugador_x+30,jugador_y,GINTOKI_GOLPE5);
	renders["Gintoki.bmp"]->region(574,1845,jugador_x+2,jugador_y,GINTOKI_GOLPE6);
	renders["Gintoki.bmp"]->region(609,1845,jugador_x,jugador_y,GINTOKI_GOLPE7);
	GINTOKI_GOLPE1->guardaBMP("paso1.bmp");
	GINTOKI_GOLPE2->guardaBMP("paso2.bmp");
	GINTOKI_GOLPE3->guardaBMP("paso3.bmp");
	GINTOKI_GOLPE4->guardaBMP("paso4.bmp");
	GINTOKI_GOLPE5->guardaBMP("paso5.bmp");
	GINTOKI_GOLPE6->guardaBMP("paso6.bmp");
	GINTOKI_GOLPE7->guardaBMP("paso7.bmp");

	delete renders["Gintoki.bmp"];
}


#endif