/*
** load_arena.c for Corewar in /home/chapui_s/travaux/Corewar/VM
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Fri Mar 21 15:35:36 2014 chapui_s
** Last update Mon Mar 24 18:55:02 2014 chapui_s
*/

#include <stdlib.h>
#include "machine.h"
#include "../op/op.h"

int		load_arena(t_corewar *core)
{
  if ((core->arena = (unsigned char*)malloc(MEM_SIZE)) == NULL)
    return (my_putstr(ALLOC_FAILED, 2));
  if ((core->info_arena = (unsigned char*)malloc(MEM_SIZE)) == NULL)
    return (my_putstr(ALLOC_FAILED, 2));
  init_arena(core->arena, MEM_SIZE, 0);
  if ((load_champions_in_arena(core->arena, core->info_arena, core)) == -1)
    return (-1);
  my_gui(core, MEM_SIZE);
  my_showmem(core->arena, MEM_SIZE);
  return (0);
}
