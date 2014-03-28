/*
** my_st.c for Corewar in /home/chapui_s/travaux/Corewar/VM/functions
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Fri Mar 28 18:45:40 2014 chapui_s
** Last update Fri Mar 28 21:19:54 2014 chapui_s
*/

#include "../machine.h"

void		my_st(t_corewar *core,
		      t_champions *champions,
		      t_instruction *instruction)
{
  int		value_to_store;

  (void)core;
  value_to_store = 0;
  if (is_good_register(instruction->params[0]) == 1)
    value_to_store = champions->reg[instruction->params[0]];
  if (is_register(instruction->type, 2) == 1)
  {
    if (is_good_register(instruction->params[1]) == 1)
      champions->reg[instruction->params[1]] = value_to_store;
  }
  else if (is_indirect(instruction->type, 2) == 1)
    write_arena_four(core, champions, value_to_store, instruction->params[1]);
}
