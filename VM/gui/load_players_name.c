/*
** load_players_name.c for Corewar in /home/chapui_s/travaux/Corewar/VM/gui
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Mar 24 16:31:07 2014 chapui_s
** Last update Thu Apr 10 00:23:01 2014 chapui_s
*/

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <unistd.h>
#include "../machine.h"

int		load_players_name(t_corewar *core, t_gui *gui)
{
  t_champions	*tmp;
  unsigned int	cur;
  int		i;

  i = 0;
  cur = 1;
  tmp = core->champions;
  while (tmp)
  {
    if (tmp->prog_number == cur)
    {
      get_color_champions(gui, tmp->color_gui);
      if ((gui->players[i] = TTF_RenderText_Solid(gui->font_info,
						  tmp->name,
						  gui->my_color)) == NULL)
	return (my_putstr("error: TTF_RenderText\n", 2));
      i += 1;
      cur += 1;
      tmp = core->champions;
    }
    else
      tmp = tmp->next;
  }
  gui->players[i] = NULL;
  return (0);
}
