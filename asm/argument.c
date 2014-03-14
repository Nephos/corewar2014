/*
** arguments.c for  in /home/poulet_a/projets/corewar/Asm
** 
** Made by poulet_a
** Login   <poulet_a@epitech.net>
** 
** Started on  Thu Mar 13 16:20:11 2014 poulet_a
** Last update Fri Mar 14 11:28:26 2014 poulet_a
*/

#include "../op/op.h"
#include "my.h"

int     arg_op_exists(char *op_name)
{
  int	i;

  i = 0;
  while (op_tab[i].mnemonique != 0)
    {
      if (my_match(op_name, op_tab[i].mnemonique))
	return (i);
      i++;
    }
  return (-1);
}
