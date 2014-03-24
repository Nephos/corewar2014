/*
** my_gui.c for Corewar in /home/chapui_s/travaux/Corewar/VM/gui
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Mar 24 16:31:07 2014 chapui_s
** Last update Mon Mar 24 20:24:37 2014 chapui_s
*/

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <unistd.h>
#include "../machine.h"

void		sdl_loop(t_gui *gui)
{
  int		stop;
  SDL_Event	event;

  stop = 0;
  while (stop == 0)
  {
    SDL_Flip(gui->screen);
    SDL_WaitEvent(&event);
    if (event.type == SDL_QUIT)
    {
      TTF_CloseFont(gui->font);
      SDL_Quit();
      TTF_Quit();
      stop = 1;
    }
  }
}

int		get_arena(t_corewar *core,
			  int size,
			  t_gui *gui)
{
  SDL_Rect	position;
  int		i;

  i = 0;
  position.x = 0;
  position.y = 0;
  while (i < size)
  {
    if ((get_color(gui, core, i)) == -1)
      return (-1);
    if ((SDL_BlitSurface(gui->byte_arena, NULL, gui->screen, &position)) < 0)
      return (my_putstr("error :SDL_BlitSurface\n", 2));
    position.x += 14;
    if (i > 0 && (i + 1) % 96 == 0)
    {
      position.x = 0;
      position.y += 11;
    }
    i += 1;
  }
  sdl_loop(gui);
  return (0);
}

int		my_gui(t_corewar *core,
		       int size)
{
  static t_gui	*gui;

  if (gui == NULL)
  {
    if ((gui = (t_gui*)malloc(sizeof(*gui))) == NULL)
      return (my_putstr("error: malloc\n", 2));
    gui->screen = NULL;
    gui->byte_arena = NULL;
    gui->font = NULL;
    if (SDL_Init(SDL_INIT_VIDEO) == -1)
      return (my_putstr("error: SDL_Init\n", 2));
    if ((gui->screen = SDL_SetVideoMode(1345, 710, 32, SDL_HWSURFACE)) == NULL)
      return (my_putstr("error: SDL_SetVideoMode\n", 2));
    SDL_WM_SetCaption("Corewar", NULL);
    if ((TTF_Init()) == -1)
      return (my_putstr("error: TTF_Init\n", 2));
    if ((gui->font = TTF_OpenFont("arial.ttf", 11)) == NULL)
      return (my_putstr("error: TTF_OpenFont\n", 2));
  }
  if ((get_arena(core, size, gui)) == -1)
    return (-1);
  return (0);
}
