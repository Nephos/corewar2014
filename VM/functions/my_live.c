/*
** my_live.c for Corewar in /home/chapui_s/travaux/Corewar/VM/functions
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Fri Mar 28 17:28:36 2014 chapui_s
** Last update Wed Apr  9 16:22:43 2014 chapui_s
*/

#include "../machine.h"

int		my_live(t_corewar *core,
			t_champions *champions,
			t_instruction *instruction)
{
  if ((int)(champions->color_gui) == instruction->params[0])
  {
    printf("%s still alive !\n", champions->name);
    champions->last_live = 0;
    core->nbr_live_cur += 1;
  }
  return (0);
}
