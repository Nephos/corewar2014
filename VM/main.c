/*
** main.c for Corewar in /home/chapui_s/travaux/Corewar/VM
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Thu Mar 20 14:45:46 2014 chapui_s
** Last update Sat Apr 12 16:32:43 2014 poulet_a
*/

#include <stdio.h>
#include <stdlib.h>
#include "machine.h"

void		disp_args(t_corewar *core)
{
  t_champions	*tmp;
  int		i;

  tmp = core->champions;
  printf("nb_champion = %d\n\n", core->nb_champions);
  while (tmp)
  {
    i = 1;
    printf("filename = %s\n", tmp->filename);
    printf("prog_number = %d\n", tmp->prog_number);
    printf("load_address = %d\n", tmp->load_address);
    printf("pc = %d\n", tmp->pc);
    printf("carry = %d\n", tmp->carry);
    printf("last_live = %d\n", tmp->last_live);
    printf("cycle_to_wait = %d\n", tmp->cycle_to_wait);
    printf("name = %s\n", tmp->name);
    printf("comment = %s\n", tmp->comment);
    printf("color = %d\n", tmp->color_gui);
    while (i < REG_NUMBER + 1)
    {
      printf("reg[%d] = %d\n", i, tmp->reg[i]);
      i += 1;
    }
    printf("\n");
    tmp = tmp->next;
    i += 1;
  }
}

int		main(int argc, char **argv)
{
  t_corewar	core;

  core.champions = NULL;
  if ((get_args(argc, argv, &core)) == -1)
    return (-1);
  if ((load_arena(&core, argv[0])) == -1)
    return (-1);
  return (0);
}
