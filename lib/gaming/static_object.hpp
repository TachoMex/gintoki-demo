#ifndef GAMING__STATIC_OBJECT_H
#define GAMING__STATIC_OBJECT_H

#include "./object.hpp"
#include "../paint/image.h"
#include "../gaming/gl2.h"

namespace Gaming{
  class StaticObject : public Object
  {
  public:
    _2D::Rectangulo<double> posicion;
    Image *render;
    Color fondo;

    StaticObject(const _2D::Rectangulo<double> &pos, Image *r, Color f = Color::black) : posicion(pos), fondo(f)
    {
      render = r;
    }

    virtual bool colisiona(const _2D::Rectangulo<double> &r) const
    {
      return posicion.colision(r);
    }

    virtual bool colisiona(Object *o) const
    {
      return o->colisiona(posicion);
    }

    virtual void dibujar(bool flip = false) const
    {
      if (flip)
      {
        glDrawPixels(render, posicion.fin - _2D::Punto<double>(render->cols(), render->rows()), fondo, flip);
      }
      else
      {
        glDrawPixels(render, posicion.inicio, fondo, flip);
      }
    }

    virtual void moverA(const _2D::Punto<double> &pos)
    {
      posicion = _2D::Rectangulo<double>(pos, posicion.base(), posicion.altura());
    }
  };
}

#endif // !GAMING__STATIC_OBJECT_H
