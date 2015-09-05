#ifndef JUEGO_H
#define JUEGO_H 

#include "temporizador.h"
#include "jugador.h"
#include "muro.h"
#include <vector>

#include <SFML/Audio.hpp>




class Juego{
public:
	Jugador * jugador;
	_2D::Scroll * scroll;
	sf::Music music;
	Temporizador cronometro;
	std::vector<Gadget*> gadgets;
	void evento(unsigned char);
	void iterar();
	void inicializaJuego(int , int );
};


void Juego::evento(unsigned char e){
	switch(e){
		case 'w':
			jugador->salto();
			break;
		case 'a':
			jugador->izquierda();
			break;
		case 'd':
			jugador->derecha();
			break;
		case ' ':
			jugador->golpe();
			break;
	} 
	scroll->ponerEn(_2D::Punto<double>(jugador->posicion.inicio.x-SCREEN_X/2, jugador->posicion.inicio.y-SCREEN_Y/2));
}

void Juego::iterar(){
	if(cronometro.msegundos() >= delay){	
		glClear(GL_COLOR_BUFFER_BIT); 
		for(Gadget* g:gadgets){
			if(scroll->enPantalla(g)){
				g->dibujar();
			}
		}
		jugador->dibujar();
		jugador->iterar();
		jugador->limitar(scroll->area);
		jugador->aplicarFriccion(v_friccion);

		for(Gadget* g : gadgets){
			if(g->colisiona(jugador)){
				g->colisionConJugador(jugador);
			}
		}


		glFlush();
		glutSwapBuffers();
		scroll->colocaCamaraOGL(); 
		cronometro.reiniciar();
	}
}

void Juego::inicializaJuego(int mapax, int mapay){
	scroll = new _2D::Scroll(mapax, mapay, SCREEN_X, SCREEN_Y);
	jugador = new Jugador(_2D::Rectangulo<double>(_2D::Punto<double>(0,30), jugador_x, jugador_y), fondo_renders, _2D::Punto<double>(),v_grav );
	gadgets.push_back(new Muro(_2D::Rectangulo<double>(_2D::Punto<double>(0,0),4*SCREEN_X,30)));
	gadgets.push_back(new Muro(_2D::Rectangulo<double>(_2D::Punto<double>(0,40+jugador_y),SCREEN_X,30)));
	music.openFromFile("music.ogg");
	music.setLoop(true);
	music.play();
}

#endif


 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* ----------------
 * LEGAL NOTICE
 * ----------------
 *
 * This game is NOT related to Gintama in any way. Also,
 * this game characters are property of Hideaki Sorachi.
 *
 * The new SDL code is written by Gatuno, and is released under
 * the term of the GNU General Public License.
 */