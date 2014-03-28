/*
** my_live.c for Corewar in /home/chapui_s/travaux/Corewar/VM/functions
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Fri Mar 28 17:28:36 2014 chapui_s
** Last update Fri Mar 28 17:51:54 2014 chapui_s
*/

#include "../machine.h"

void		my_live(t_corewar *core,
			t_champions *champions,
			t_instruction *instruction)
{
  (void)core;
  while (champions && instruction)
  {
    if ((int)(champions->prog_number) == instruction->params[0])
      champions->last_live = 0;
    champions = champions->next;
  }
}
