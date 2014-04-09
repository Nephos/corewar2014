/*
** events.c for Corewar in /home/chapui_s/travaux/Corewar/VM/gui
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Thu Apr 10 00:54:12 2014 chapui_s
** Last update Thu Apr 10 01:24:26 2014 chapui_s
*/

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "../machine.h"

int		manage_event(t_gui *gui,
			     int *pause)
{
  SDL_Event	event;

  while (SDL_PollEvent(&event))
  {
    if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
    {
      TTF_CloseFont(gui->font);
      SDL_Quit();
      TTF_Quit();
      return (-1);
    }
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
      *pause = !(*pause);
  }
  return (*pause);
}
