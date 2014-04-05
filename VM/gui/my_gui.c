/*
** my_gui.c for Corewar in /home/chapui_s/travaux/Corewar/VM/gui
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Mar 24 16:31:07 2014 chapui_s
** Last update Sat Apr  5 14:13:14 2014 chapui_s
*/

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <unistd.h>
#include "../machine.h"

int		get_arena(t_corewar *core,
			  int size,
			  t_gui *gui)
{
  SDL_Event	event;
  SDL_Rect	position;
  int		i;
  int		j;
  int		cycle_no_print;

  i = 0;
  j = 0;
  cycle_no_print = 0;
  core->screen_update = 1;
  while (1)
  {
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT)
    {
      TTF_CloseFont(gui->font);
      SDL_Quit();
      TTF_Quit();
      return (0);
    }

    if ((manage_instructions(core, core->champions)) == 1)
      return (0);
    if (core->screen_update != 0 || cycle_no_print > 5)
   {
    SDL_FillRect(gui->screen, NULL, SDL_MapRGB(gui->screen->format, 0, 0, 0));
    i = 0;

     position.x = 0;
     position.y = 0;
     if ((SDL_BlitSurface(gui->background, NULL, gui->screen, &(gui->pos_background))) < 0)
       return (my_putstr("error: SDL_BlitSurface\n", 2));
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
       SDL_FreeSurface(gui->byte_arena);
       i += 1;
       cycle_no_print = 0;
     }
     SDL_Flip(gui->screen);
     }
     core->screen_update = 0;
     cycle_no_print += 1;
     j += 1;
  }
  TTF_CloseFont(gui->font);
  SDL_Quit();
  TTF_Quit();
  return (0);
}

int		put_background(t_corewar *core, t_gui *gui)
{

  gui->pos_background.x = 0;
  gui->pos_background.y = 705;
  if ((gui->background = SDL_LoadBMP("Corewar.bmp")) == NULL)
    return (my_putstr("error: SDL_LoadBMP\n", 2));
  return (0);
}

int		my_gui(t_corewar *core,
		       int size)
{
  t_gui		*gui;

  if ((gui = (t_gui*)malloc(sizeof(*gui))) == NULL)
    return (my_putstr("error: malloc\n", 2));
  gui->screen = NULL;
  gui->byte_arena = NULL;
  gui->font = NULL;
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (my_putstr("error: SDL_Init\n", 2));
  if ((gui->screen = SDL_SetVideoMode(WIN_X, WIN_Y, 32, SDL_HWSURFACE)) == NULL)
    return (my_putstr("error: SDL_SetVideoMode\n", 2));
  SDL_WM_SetCaption("Corewar", NULL);
  if ((put_background(core, gui)) == -1)
    return (-1);
  if ((TTF_Init()) == -1)
    return (my_putstr("error: TTF_Init\n", 2));
  if ((gui->font = TTF_OpenFont("arial.ttf", 11)) == NULL)
    return (my_putstr("error: TTF_OpenFont\n", 2));
  if ((get_arena(core, size, gui)) == -1)
    return (-1);
  return (0);
}
