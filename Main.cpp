#include <GL/freeglut.h>
#include <GL/gl.h>

#include "lib/gaming/gestor.h"
#include "lib/gintoki/juego.h"
#include "lib/gintoki/constantes.h"
#include <vector>
#include "lib/gaming/temporizador.h"
#include "lib/stacktrace.hpp"

using namespace std;
using namespace _2D;

Juego *juego;

bool upIsPressed;
bool leftIsPressed;
bool rightIsPressed;
bool downIsPressed;

bool resuelve_evento(const SDL_Event &evento)
{
  SDLKey tecla;
  switch (evento.type)
  {
  case SDL_QUIT:
    return true;
    break;
  case SDL_KEYDOWN:
    tecla = evento.key.keysym.sym;
    switch (tecla)
    {
    case SDLK_SPACE:
      juego->evento(' ');
      break;
    case SDLK_LEFT:
      leftIsPressed = true;
      break;
    case SDLK_RIGHT:
      rightIsPressed = true;
      break;
    case SDLK_UP:
      upIsPressed = true;
      break;
    case SDLK_DOWN:
      break;
    }
    break;
  case SDL_KEYUP:
    tecla = evento.key.keysym.sym;
    switch (tecla)
    {
    case SDLK_SPACE:
      break;
    case SDLK_LEFT:
      leftIsPressed = false;
      break;
    case SDLK_RIGHT:
      rightIsPressed = false;
      break;
    case SDLK_UP:
      upIsPressed = false;
      break;
    case SDLK_DOWN:
      break;
    }
    break;
  }
  return false;
}

int main(int argc, char **argv)
{
  Teuchos::print_stack_on_segfault();

  cargaRenders();
  juego = new Juego();
  SDL_Event evento;
  if (SDL_SetVideoMode(SCREEN_X, SCREEN_Y, 16, SDL_OPENGL) == NULL)
  {
    cout << "Error al inicializar el modo de video" << endl;
    return 1;
  }
  juego->inicializaJuego(SCREEN_X * 4, SCREEN_Y);
  bool salir = false;
  Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
  while (not salir)
  {
    if (not Mix_PlayingMusic())
      Mix_PlayMusic(juego->musica, -1);

    while (SDL_PollEvent(&evento))
    {
      salir = resuelve_evento(evento);
    }
    if (upIsPressed)
    {
      juego->evento('w');
    }
    if (leftIsPressed)
    {
      juego->evento('a');
    }
    if (rightIsPressed)
    {
      juego->evento('d');
    }
    juego->iterar();
  }

  return 0;
}
