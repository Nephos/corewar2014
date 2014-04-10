/*
** my_gui.c for Corewar in /home/chapui_s/travaux/Corewar/VM/gui
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Mar 24 16:31:07 2014 chapui_s
** Last update Thu Apr 10 02:18:41 2014 chapui_s
*/

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <unistd.h>
#include "../../op/op.h"
#include "../machine.h"

int		print_bytes(t_corewar *core,
			    t_gui *gui)
{
  SDL_Rect	position;
  int		i;

  i = 0;
  position.x = 0;
  position.y = 0;
  while (i < MEM_SIZE)
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
  }
  return (0);
}

int		disp_arena(t_corewar *core,
			   t_gui *gui,
			   unsigned long long j,
			   int pause)
{
  if ((j % 5) == 0 || pause == 1)
  {
    if ((SDL_FillRect(gui->screen, NULL, 0)) < 0)
      return (my_putstr("error: SDL_FillRect\n", 2));
    if ((SDL_BlitSurface(gui->background, NULL, gui->screen,
			 &(gui->pos_background))) < 0)
      return (my_putstr("error: SDL_BlitSurface\n", 2));
    if ((disp_info_players(core, gui, j, pause)) == -1)
      return (-1);
    get_list_pc(core, gui);
    if ((print_bytes(core, gui)) == -1)
      return (-1);
    if ((SDL_Flip(gui->screen)) == -1)
      return (my_putstr("error: SDL_Flip\n", 2));
  }
  return (0);
}

int		get_arena(t_corewar *core,
			  t_gui *gui)
{
  int			pause;
  unsigned long long	j;

  j = 0;
  pause = 0;
  while (1)
  {
    if ((pause = manage_event(core, gui, &pause)) == -1)
      return (0);
    if (pause == 0)
    {
      if ((manage_instructions(core)) == 1)
	return (0);
      if ((disp_arena(core, gui, j, 0)) == -1)
	return (-1);
      j += 1;
    }
    else
      if ((disp_arena(core, gui, j, 1)) == -1)
	return (-1);
    if (j == core->nbr_cycle_dump)
      return (my_showmem(core->arena, MEM_SIZE));
  }
  return (0);
}

int		put_background(t_corewar *core, t_gui *gui)
{
  gui->pos_background.x = 0;
  gui->pos_background.y = 705;
  if ((gui->background = SDL_LoadBMP("Corewar.bmp")) == NULL)
    return (my_putstr("error: SDL_LoadBMP\n", 2));
  if ((gui->font_info = TTF_OpenFont("arial.ttf", 13)) == NULL)
    return (my_putstr("error: TTF_OpenFont\n", 2));
  if ((load_players_name(core, gui)) == -1)
    return (-1);
  return (0);
}

int		my_gui(t_corewar *core)
{
  t_gui		*gui;

  if ((gui = (t_gui*)malloc(sizeof(*gui))) == NULL)
    return (my_putstr("error: malloc\n", 2));
  gui->screen = NULL;
  gui->byte_arena = NULL;
  gui->font = NULL;
  gui->font_info = NULL;
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (my_putstr("error: SDL_Init\n", 2));
  if ((gui->screen = SDL_SetVideoMode(WIN_X, WIN_Y, 32, SDL_HWSURFACE))
      == NULL)
    return (my_putstr("error: SDL_SetVideoMode\n", 2));
  SDL_WM_SetCaption("Corewar", NULL);
  if ((TTF_Init()) == -1)
    return (my_putstr("error: TTF_Init\n", 2));
  if ((put_background(core, gui)) == -1)
    return (-1);
  if ((gui->font = TTF_OpenFont("arial.ttf", 11)) == NULL)
    return (my_putstr("error: TTF_OpenFont\n", 2));
  if ((gui->list_pc = (int*)malloc(sizeof(int) * (MAX_PC * 2))) == NULL)
    return (my_putstr("error: malloc\n", 2));
  if ((get_arena(core, gui)) == -1)
    return (-1);
  return (0);
}
