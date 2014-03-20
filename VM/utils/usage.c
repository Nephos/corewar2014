/*
** usage.c for Corewar in /home/chapui_s/travaux/Corewar/VM/utils
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Thu Mar 20 17:04:23 2014 chapui_s
** Last update Thu Mar 20 20:11:21 2014 chapui_s
*/

#include "../machine.h"

int		usage(void)
{
  my_putstr("usage: ./corewar [-dump nbr_cycle] [[-n prog_number] ", 1);
  my_putstr("[-a load_address ] prog_name] ...\n", 1);
  return (-1);
}
