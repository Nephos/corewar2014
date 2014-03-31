/*
** my_add.c for Corewar in /home/chapui_s/travaux/Corewar/VM/functions
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Fri Mar 28 21:20:28 2014 chapui_s
** Last update Mon Mar 31 23:13:05 2014 chapui_s
*/

#include "../machine.h"

void		my_add(t_corewar *core,
		       t_champions *champions,
		       t_instruction *instruction)
{
  int		value1;
  int		value2;

  (void)core;
  value1 = 0;
  value2 = 0;
  if (is_good_register(instruction->params[0]) == 1)
    value1 = champions->reg[instruction->params[0]];
  if (is_good_register(instruction->params[1]) == 1)
    value2 = champions->reg[instruction->params[1]];
  if (is_good_register(instruction->params[2]) == 1)
    champions->reg[instruction->params[2]] = value1 + value2;
  printf("reg[%d] = %d\n", instruction->params[2], value2 + value1);
  champions->carry = (value1 + value2) ? (0) : (1);
}
