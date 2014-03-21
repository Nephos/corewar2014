/*
** load_arena.c for Corewar in /home/chapui_s/travaux/Corewar/VM
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Fri Mar 21 15:35:36 2014 chapui_s
** Last update Fri Mar 21 22:44:37 2014 chapui_s
*/

#include <stdlib.h>
#include "machine.h"
#include "../op/op.h"

int		load_arena(t_corewar *arguments)
{
  unsigned char	*arena;

  if ((arena = (unsigned char*)malloc(MEM_SIZE)) == NULL)
    return (my_putstr(ALLOC_FAILED, 2));
  init_arena(arena, MEM_SIZE, 0);
  if ((load_champions_in_arena(arena, arguments)) == -1)
    return (-1);
  my_showmem(arena, MEM_SIZE);
  return (0);
}
