/*
** main.c for Corewar in /home/chapui_s/travaux/Corewar/VM
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Thu Mar 20 14:45:46 2014 chapui_s
** Last update Thu Mar 20 20:18:50 2014 chapui_s
*/

#include <stdlib.h>
#include "machine.h"

void		disp_args(t_args *arguments)
{
  t_champions	*tmp;

  tmp = arguments->champions;
  printf("nb_champion = %d\n\n", arguments->nb_champions);
  while (tmp)
  {
    printf("filename = %s\n", tmp->filename);
    printf("prog_number = %d\n", tmp->prog_number);
    printf("load_address = %d\n", tmp->load_address);
    printf("\n");
    tmp = tmp->next;
  }
}

int		main(int argc, char **argv)
{
  t_args	arguments;

  arguments.champions = NULL;
  if ((get_args(argc, argv, &arguments)) == -1)
    return (-1);
  disp_args(&arguments);
  return (0);
}
