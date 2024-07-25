#ifndef GAMING_SCROLL_HPP
#define GAMING_SCROLL_HPP

#include "object.hpp"

namespace Gaming {
  class Scroll
  {
  public:
    _2D::Rectangulo<double> area;
    _2D::Rectangulo<double> posicion;

    Scroll(double mx, double my, double px, double py) : area(_2D::Punto<double>(), mx, my), posicion(_2D::Punto<double>(), px, py)
    {
    }

    void limitar()
    {
      _2D::Punto<double> ajuste;
      if (posicion.inicio.x < area.inicio.x)
      {
        ajuste.x -= posicion.inicio.x - area.inicio.x;
      }
      if (posicion.inicio.y < area.inicio.y)
      {
        ajuste.y -= posicion.inicio.y - area.inicio.y;
      }
      if (posicion.fin.x > area.fin.x)
      {
        ajuste.x -= posicion.fin.x - area.fin.x;
      }
      if (posicion.fin.y > area.fin.y)
      {
        ajuste.y -= posicion.fin.y - area.fin.y;
      }
      posicion += ajuste;
    }

    bool enPantalla(Object *o)
    {
      return o->colisiona(posicion);
    }

    void moverX(double x)
    {
      posicion.inicio.x += x;
      posicion.fin.x += x;
      limitar();
    }

    void moverY(double y)
    {
      posicion.inicio.y += y;
      posicion.fin.y += y;
      limitar();
    }

    void ponerEn(const _2D::Punto<double> &p)
    {
      double h = posicion.altura();
      double b = posicion.base();
      posicion.inicio = posicion.fin = p;
      posicion.fin.x += b;
      posicion.fin.y += h;
      limitar();
    }

    void colocaCamaraOGL()
    {
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(posicion.inicio.x, posicion.fin.x, posicion.inicio.y, posicion.fin.y);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
    }
  };
};
#endif // !GAMING_SCROLL_HPP
