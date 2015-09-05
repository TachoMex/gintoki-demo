#ifndef GADGET_H
#define GADGET_H 

#include "objeto.h"
#include "jugador.h"
#include "constantes.h"

class Gadget: public _2D::ObjetoInmovil{
public:
	virtual void colisionConJugador(Jugador * g) = 0;
	Gadget(const _2D::Rectangulo<double>& pos, Imagen * r, Color f = Color::negro):_2D::ObjetoInmovil(pos,r,f){

	}
	virtual void dibujar(){
		ObjetoInmovil::dibujar();
	}
	virtual bool colisiona(const _2D::Rectangulo<double>& r){
		return ObjetoInmovil::colisiona(r);
	}
	virtual bool colisiona(_2D::Objeto* o){
		return _2D::ObjetoInmovil::colisiona(o);
	}
};

#endif