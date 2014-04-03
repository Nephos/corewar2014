/*
** get_color.c for Corewar in /home/chapui_s/travaux/Corewar/VM/gui
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Mar 24 18:49:25 2014 chapui_s
** Last update Wed Apr  2 23:33:19 2014 chapui_s
*/

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "../machine.h"

static int	is_pc(t_champions *champions, int i)
{
  while (champions)
  {
    if (champions->pc == (unsigned int)i)
    {
      return (1);
    }
    champions = champions->next;
  }
  return (0);
}

static void	get_color_champions(t_gui *gui,
				    unsigned char c)
{
  gui->my_color.r = 30;
  gui->my_color.g = 30;
  gui->my_color.b = 30;
  (c == 1) ? (gui->my_color.r = 0) : (0);
  (c == 1) ? (gui->my_color.g = 255) : (0);
  (c == 1) ? (gui->my_color.b = 0) : (0);
  (c == 2) ? (gui->my_color.r = 0) : (0);
  (c == 2) ? (gui->my_color.g = 0) : (0);
  (c == 2) ? (gui->my_color.b = 255) : (0);
  (c == 3) ? (gui->my_color.r = 255) : (0);
  (c == 3) ? (gui->my_color.g = 255) : (0);
  (c == 3) ? (gui->my_color.b = 0) : (0);
  (c == 4) ? (gui->my_color.r = 66) : (0);
  (c == 4) ? (gui->my_color.g = 0) : (0);
  (c == 4) ? (gui->my_color.b = 66) : (0);
}

static int	set_color_with_pc(t_gui *gui,
				  t_corewar *core,
				  int i)
{
  SDL_Color	fg_color;
  char		str[3];

  fg_color.r = 0;
  fg_color.g = 0;
  fg_color.b = 0;
  fg_color.unused = 0;
  /* if ((str = (char*)malloc(3)) == NULL) */
  /*   return (my_putstr("error: malloc\n", 2)); */
  if (is_pc(core->champions, i) == 1)
    gui->byte_arena = TTF_RenderText_Shaded(gui->font,
					    hex_to_str(core->arena[i], &str[0]),
					    fg_color,
					    gui->my_color);
  else
    gui->byte_arena = TTF_RenderText_Solid(gui->font,
  					   hex_to_str(core->arena[i], &str[0]),
  					   gui->my_color);
  /* free(str); */
  if (gui->byte_arena == NULL)
    return (my_putstr("error: TTF_RenderText\n", 2));
  return (0);
}
/* static int	set_color_with_pc(t_gui *gui, */
/* 				  t_corewar *core, */
/* 				  int i) */
/* { */
/*   SDL_Color	fg_color; */
/*   char		*str; */

/*   fg_color.r = 0; */
/*   fg_color.g = 0; */
/*   fg_color.b = 0; */
/*   fg_color.unused = 0; */
/*   if ((str = (char*)malloc(3)) == NULL) */
/*     return (my_putstr("error: malloc\n", 2)); */
/*   if (is_pc(core->champions, i) == 1) */
/*     gui->byte_arena = TTF_RenderText_Shaded(gui->font, */
/* 					    hex_to_str(core->arena[i], str), */
/* 					    fg_color, */
/* 					    gui->my_color); */
/*   else */
/*     gui->byte_arena = TTF_RenderText_Solid(gui->font, */
/*   					   hex_to_str(core->arena[i], str), */
/*   					   gui->my_color); */
/*   free(str); */
/*   if (gui->byte_arena == NULL) */
/*     return (my_putstr("error: TTF_RenderText\n", 2)); */
/*   return (0); */
/* } */

int		get_color(t_gui *gui,
			  t_corewar *core,
			  int i)
{
  get_color_champions(gui, core->info_arena[i]);
  if ((set_color_with_pc(gui, core, i)) == -1)
    return (-1);
  gui->byte_arena->w = 12;
  gui->byte_arena->h = 11;
  return (0);
}
