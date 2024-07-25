#ifndef GAMING__OBJECT
#define GAMING__OBJECT

#include "../geometry/2D/rectangulo.h"

namespace Gaming{
  class Object
  {
  public:
    virtual bool colisiona(Object *) const = 0;
    virtual bool colisiona(const _2D::Rectangulo<double> &) const = 0;
    virtual void dibujar(bool) const = 0;
  };
};
#endif // !GAMING__OBJECT