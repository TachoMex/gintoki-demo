#ifndef GAMING__DYNAMIC_OBJECT_HPP

#include "static_object.hpp"

namespace Gaming
{
  class DynamicObject : public StaticObject
  {
  public:
    _2D::Punto<double> aceleracion;
    _2D::Punto<double> velocidad;
    _2D::Punto<double> posicionAnterior;

    DynamicObject(const _2D::Rectangulo<double> &pos, Image *r, Color f = Color::black, const _2D::Punto<double> v = _2D::Punto<double>(),
                  const _2D::Punto<double> a = _2D::Punto<double>()) : StaticObject(pos, r, f), aceleracion(a), velocidad(v)
    {
    }

    virtual void iterar()
    {
      posicionAnterior = posicion.inicio;
      posicion += velocidad;
      velocidad += aceleracion;
    }

    virtual _2D::Linea<double> desplazamiento()
    {
      return _2D::Linea<double>(posicionAnterior, posicion.inicio);
    }

    virtual _2D::Linea<double> desplazamientoSuperior()
    {
      return _2D::Linea<double>(posicionAnterior, posicion.inicio) + (posicion.fin - posicion.inicio);
    }

    virtual void limitar(const _2D::Rectangulo<double> &limite)
    {
      _2D::Punto<double> ajuste;
      if (posicion.inicio.x < limite.inicio.x)
      {
        ajuste.x -= posicion.inicio.x - limite.inicio.x;
        velocidad.x = 0;
      }
      if (posicion.inicio.y < limite.inicio.y)
      {
        ajuste.y -= posicion.inicio.y - limite.inicio.y;
        velocidad.y = 0;
      }
      if (posicion.fin.x > limite.fin.x)
      {
        ajuste.x -= posicion.fin.x - limite.fin.x;
        velocidad.x = 0;
      }
      if (posicion.fin.y > limite.fin.y)
      {
        ajuste.y -= posicion.fin.y - limite.fin.y;
        velocidad.y = 0;
      }
      posicion += ajuste;
    }

    virtual void aplicarFriccion(const _2D::Punto<double> &f)
    {
      velocidad.x *= f.x;
      velocidad.y *= f.y;
    }

    virtual bool colisiona(const _2D::Rectangulo<double> &r)
    {
      return StaticObject::colisiona(r);
    }

    virtual bool colisiona(Object *o)
    {
      return StaticObject::colisiona(o);
    }
  };

  int ladoColision(const DynamicObject *o, const _2D::Rectangulo<double> &rec)
  {
    double prof_x = std::min(o->posicion.fin.x, rec.fin.x) - std::max(o->posicion.inicio.x, rec.inicio.x);
    double prof_y = std::min(o->posicion.fin.y, rec.fin.y) - std::max(o->posicion.inicio.y, rec.inicio.y);

    bool izquierda = o->posicion.fin.x < rec.fin.x;
    bool derecha = o->posicion.inicio.x > rec.inicio.x;
    bool abajo = o->posicion.fin.y < rec.fin.y;
    bool arriba = o->posicion.inicio.y > rec.inicio.y;

    if (prof_x < 0 or prof_y < 0)
    {
      return -1;
    }

    if (o->posicion.inicio.x >= rec.inicio.x and o->posicion.fin.x <= rec.fin.x)
    {
      return (abajo ? 3 : 1);
    }
    if (o->posicion.inicio.y >= rec.inicio.y and o->posicion.fin.y <= rec.fin.y)
    {
      return (izquierda ? 4 : 2);
    }

    if (izquierda)
    {
      if (abajo)
      {
        if (o->velocidad.x < 0)
        {
          return 3;
        }
        else if (o->velocidad.y < 0)
        {
          return 4;
        }
      }
      else if (arriba)
      {
        if (o->velocidad.x < 0)
        {
          return 1;
        }
        else if (o->velocidad.y > 0)
        {
          return 4;
        }
      }
    }
    else if (derecha)
    {
      if (abajo)
      {
        if (o->velocidad.x > 0)
        {
          return 3;
        }
        else if (o->velocidad.y < 0)
        {
          return 2;
        }
      }
      else if (arriba)
      {
        if (o->velocidad.x > 0)
        {
          return 1;
        }
        else if (o->velocidad.y > 0)
        {
          return 2;
        }
      }
    }
    _2D::Linea<double> lado;
    if (o->velocidad.x > 0)
    {
      if (o->velocidad.y > 0)
      {
        lado = _2D::Linea<double>(o->posicionAnterior, o->posicion.fin);
        return lado.colisiona(rec.lado4()) ? 4 : 3;
      }
      else if (o->velocidad.y < 0)
      {
        lado = _2D::Linea<double>(_2D::Punto<double>(o->posicionAnterior.x + o->posicion.base(), o->posicionAnterior.y), _2D::Punto<double>(o->posicion.fin.x, o->posicion.inicio.y));
        return lado.colisiona(rec.lado1()) and o->posicionAnterior.y >= rec.fin.y ? 1 : 4;
      }
    }
    else if (o->velocidad.x < 0)
    {
      if (o->velocidad.y > 0)
      {
        lado = _2D::Linea<double>(_2D::Punto<double>(o->posicionAnterior.x + o->posicion.base(), o->posicionAnterior.y), _2D::Punto<double>(o->posicion.inicio.x, o->posicion.fin.y));
        return lado.colisiona(rec.lado2()) ? 2 : 3;
      }
      else if (o->velocidad.y < 0)
      {
        lado = _2D::Linea<double>(o->posicionAnterior, o->posicion.inicio);
        return lado.colisiona(rec.lado1()) and o->posicionAnterior.y >= rec.fin.y ? 1 : 2;
      }
    }
    return -1;
  }
}

#endif // !GAMING__DYNAMIC_OBJECT_HPP
