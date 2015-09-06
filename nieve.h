#ifndef NIEVE_H
#define NIEVE_H 
#include "gadget.h" 

class Nieve: public Gadget{
public:
	bool comida;
	virtual void colisionConJugador(Jugador* j);
	virtual void dibujar();
	Nieve(const _2D::Punto<double>& p):Gadget(_2D::Rectangulo<double>(p,NIEVE_X, NIEVE_Y),NIEVE, fondo_renders){
		comida = false;
	}
};

void Nieve::dibujar(){
	if(not comida){
		Gadget::dibujar();
	}
}

void Nieve::colisionConJugador(Jugador* j){
	comida = true;
}


#endif