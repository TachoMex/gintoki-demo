#ifndef JUEGO_H
#define JUEGO_H

#include "../gaming/temporizador.h"
#include "../gaming/scroll.hpp"
#include "jugador.h"
#include "muro.h"
#include "nieve.h"
#include <vector>
#include <SDL/SDL_mixer.h>

class Juego{
public:
  Mix_Music * musica;
  Jugador * jugador;
  Gaming::Scroll * scroll;
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
    // std::cout<<jugador->posicion.toString()<<"::"<<jugador->velocidad.toString()<<std::endl;
    jugador->iterar();
    jugador->limitar(scroll->area);
    jugador->aplicarFriccion(v_friccion);

    for(Gadget* g : gadgets){
      if(g->colisiona(jugador)){
        g->colisionConJugador(jugador);
      }
    }


    glFlush();
    SDL_GL_SwapBuffers();
    scroll->colocaCamaraOGL();
    cronometro.reiniciar();
  }
}

void Juego::inicializaJuego(int mapax, int mapay){
  scroll = new Gaming::Scroll(mapax, mapay, SCREEN_X, SCREEN_Y);
  jugador = new Jugador(_2D::Rectangulo<double>(_2D::Punto<double>(0,30), jugador_x, jugador_y), fondo_renders, _2D::Punto<double>(),v_grav );
  gadgets.push_back(new Muro(_2D::Rectangulo<double>(_2D::Punto<double>(0,0),4*SCREEN_X,30)));
  gadgets.push_back(new Muro(_2D::Rectangulo<double>(_2D::Punto<double>(0,40+jugador_y),SCREEN_X,30)));
  gadgets.push_back(new Muro(_2D::Rectangulo<double>(_2D::Punto<double>(2*SCREEN_X,40+jugador_y),SCREEN_X,30)));
  gadgets.push_back(new Muro(_2D::Rectangulo<double>(_2D::Punto<double>(2*SCREEN_X-50,30),30,30)));

  gadgets.push_back(new Nieve(_2D::Punto<double>(450, 40)));
  gadgets.push_back(new Nieve(_2D::Punto<double>(650, 40)));
  musica = Mix_LoadMUS(MUSIC_GAME);
}

#endif


