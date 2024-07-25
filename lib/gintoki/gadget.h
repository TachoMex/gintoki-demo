#ifndef GADGET_H
#define GADGET_H

#include "../gaming/static_object.hpp"
#include "jugador.h"
#include "constantes.h"

class Gadget: public Gaming::StaticObject{
public:
  virtual void colisionConJugador(Jugador * g) = 0;
  Gadget(const _2D::Rectangulo<double>& pos, Image * r, Color f = Color::black):Gaming::StaticObject(pos,r,f){

  }
  virtual void dibujar(){
    Gaming::StaticObject::dibujar();
  }
  virtual bool colisiona(const _2D::Rectangulo<double>& r){
    return Gaming::StaticObject::colisiona(r);
  }
  virtual bool colisiona(Gaming::Object* o){
    return Gaming::StaticObject::colisiona(o);
  }
};

#endif
