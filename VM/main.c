/*
** main.c for Corewar in /home/chapui_s/travaux/Corewar/VM
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Thu Mar 20 14:45:46 2014 chapui_s
** Last update Fri Mar 21 22:44:02 2014 chapui_s
*/

#include <stdlib.h>
#include "../op/op.h"
#include "machine.h"

#include <stdio.h>

void		disp_args(t_corewar *arguments)
{
  t_champions	*tmp;
  int		i;

  tmp = arguments->champions;
  printf("nb_champion = %d\n\n", arguments->nb_champions);
  while (tmp)
  {
    i = 1;
    printf("filename = %s\n", tmp->filename);
    printf("prog_number = %d\n", tmp->prog_number);
    printf("load_address = %d\n", tmp->load_address);
    printf("is_dead = %d\n", tmp->is_dead);
    printf("pc = %d\n", tmp->pc);
    printf("carry = %d\n", tmp->carry);
    printf("last_live = %d\n", tmp->last_live);
    printf("cycle_to_wait = %d\n", tmp->cycle_to_wait);
    printf("next_instruction = %d\n", tmp->next_instruction);
    /* while (i < REG_NUMBER + 1) */
    /* { */
    /*   printf("reg[%d] = %d\n", i, tmp->reg[i]); */
    /*   i += 1; */
    /* } */
    printf("\n");
    tmp = tmp->next;
    i += 1;
  }
}

int		main(int argc, char **argv)
{
  t_corewar	arguments;

  arguments.champions = NULL;
  if ((get_args(argc, argv, &arguments)) == -1)
    return (-1);
  if ((load_arena(&arguments)) == -1)
    return (-1);
  disp_args(&arguments);
  return (0);
}
