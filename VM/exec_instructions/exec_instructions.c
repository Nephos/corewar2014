/*
** exec_instructions.c for Corewar in /home/chapui_s/travaux/Corewar/VM
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Mar 25 15:13:41 2014 chapui_s
** Last update Tue Mar 25 15:37:45 2014 chapui_s
*/

#include "../machine.h"

int		exec_instructions(t_corewar *core, t_champions *champions)
{
  t_instruction	instruction;

  while (champions)
  {
    get_instruction(core, champions, &instruction);
    champions = champions->next;
  }
  return (0);
}
