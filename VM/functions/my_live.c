/*
** my_live.c for Corewar in /home/chapui_s/travaux/Corewar/VM/functions
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Fri Mar 28 17:28:36 2014 chapui_s
** Last update Tue Apr  8 15:30:48 2014 chapui_s
*/

#include "../machine.h"

int		get_size_list(t_corewar *core)
{
  t_champions	*tmp;
  int		size;

  size = 0;
  tmp = core->champions;
  while (tmp)
  {
    if (tmp->is_dead == 0)
      size += 1;
    tmp = tmp->next;
  }
  return (size);
}

int		my_live(t_corewar *core,
			t_champions *champions,
			t_instruction *instruction)
{
  (void)core;
  /* while (champions && instruction) */
  /* { */
    if ((int)(champions->color_gui) == instruction->params[0])
    {
      printf("%s still alive !\n", champions->name);
      champions->last_live = 0;
      core->nbr_live_cur += 1;
    }
  /*   champions = champions->next; */
  /* } */
  return (0);
}
