/*
** disp_info_players.c for Corewar in /home/chapui_s/travaux/Corewar/VM/gui
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Mar 25 00:20:38 2014 chapui_s
** Last update Tue Mar 25 00:20:50 2014 chapui_s
*/

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <unistd.h>
#include "../machine.h"

void		disp_info_players(t_corewar *core, t_gui *gui)
{
  SDL_Rect	position;

  position.x = 10;
  position.y = 750;
  gui->my_color.r = 255;
  gui->my_color.g = 255;
  gui->my_color.b = 255;
  if ((gui->font = TTF_OpenFont("arial.ttf", 15)) == NULL)
    return (my_putstr("error: TTF_OpenFont\n", 2));
  gui->byte_arena = TTF_RenderText_Solid(gui->font,
					 "coucou",
					 gui->my_color);
  gui->byte_arena->w = my_strlen("coucou") * 8;
  gui->byte_arena->h = 14;
  if ((SDL_BlitSurface(gui->byte_arena, NULL, gui->screen, &position)) < 0)
    return (my_putstr("error :SDL_BlitSurface\n", 2));
  TTF_CloseFont(gui->font);
}
