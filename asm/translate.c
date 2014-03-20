/*
** translate.c for  in /home/poulet_a/projets/corewar/asm
** 
** Made by poulet_a
** Login   <poulet_a@epitech.net>
** 
** Started on  Wed Mar 19 14:13:27 2014 poulet_a
** Last update Thu Mar 20 15:01:32 2014 poulet_a
*/

#include <stdlib.h>
#include "my/my.h"
#include "translate.h"
#include "label.h"

int	tra_line(char *cmd, t_op *op_l, t_lab *lab_l)
{
  if (lab_str_valid(cmd))
    {
      //add at the end of lab_l
      lab_create(lab_l, tmp, op_l->size);
    }
  else
    {
      //not a label, eval the line
    }
  return (0);
}
