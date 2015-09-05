#ifndef MURO_H
#define MURO_H 

#include "gadget.h"
#include "jugador.h"

class Muro: public Gadget{
public:
	virtual void colisionConJugador(Jugador* j);
	virtual void dibujar();
	virtual bool colisiona(_2D::Objeto * o);
	virtual bool colisiona(const _2D::Rectangulo<double>& r);
	Muro(const _2D::Rectangulo<double>& r):Gadget(r,nullptr, fondo_renders){
	}
};




void Muro::colisionConJugador(Jugador* j){
	double dif = 0;
	auto ruta = j->desplazamiento();
	auto ruta2 = j->desplazamientoSuperior();
	int caso = ladoColision(j, this->posicion);
	switch(caso){
		case 1:
			dif = ruta.fin.y - this->posicion.fin.y;
			j->posicion -= _2D::Punto<double>(0,dif);
			j->velocidad.y = 0; 
		break;
		case 2:
			dif = this->posicion.fin.x - ruta.fin.x;
			j->posicion += _2D::Punto<double>(dif,0);
			j->velocidad.x = 0; 
		break;
		case 3:
			dif = ruta2.fin.y - this->posicion.inicio.y;
			j->posicion -= _2D::Punto<double>(0,dif);
			j->velocidad.y = j->aceleracion.y; 
		break;
		case 4:
			dif = ruta2.fin.x - this->posicion.inicio.x;
			j->posicion -= _2D::Punto<double>(dif,0);
			j->velocidad.x = 0; 

		break;
		default:
		break;
	}	
}

void Muro::dibujar(){
	glColor(ColorMuros);
	glDraw(this->posicion,true);
}


bool Muro::colisiona(_2D::Objeto * o){
	return  Gadget::colisiona(o);
}

bool Muro::colisiona(const _2D::Rectangulo<double>& r){
	return  Gadget::colisiona(r);
}


#endif
