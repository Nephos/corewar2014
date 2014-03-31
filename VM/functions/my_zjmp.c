/*
** my_zjmp.c for Corewar in /home/chapui_s/travaux/Corewar/VM/functions
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Mar 31 19:37:23 2014 chapui_s
** Last update Tue Apr  1 00:08:30 2014 chapui_s
*/

#include "../../op/op.h"
#include "../machine.h"

void		my_zjmp(t_corewar *core,
			t_champions *champions,
			t_instruction *instruction)
{
  int		where_to_go;

  (void)core;
  if (champions->carry == 1)
  {
    where_to_go = champions->pc + (instruction->params[0] % IDX_MOD);
    where_to_go = (where_to_go - 3) % MEM_SIZE;
    while (where_to_go < 0)
      where_to_go += MEM_SIZE;
    champions->pc = where_to_go;
  }
}
