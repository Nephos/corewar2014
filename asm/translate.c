/*
** translate.c for  in /home/poulet_a/projets/corewar/asm
** 
** Made by poulet_a
** Login   <poulet_a@epitech.net>
** 
** Started on  Wed Mar 19 14:13:27 2014 poulet_a
** Last update Thu Mar 20 18:02:52 2014 poulet_a
*/

#include <stdlib.h>
#include "my/my.h"
#include "translate.h"
#include "label.h"

/* => add at the end of lab_l */
int	tra_line_new_undefined_label(char *cmd, t_lab *lab_l)
{
  lab_create_defined_label(cmd, op_l->size);
  return (0);
}

/*
** => not a label, eval the line
** if a label is selected, lab_create_undefined(name);
*/
int	tra_line_opcode(char *cmd, t_op *op_l, t_lab *lab_l)
{
}

int	tra_line(char *cmd, t_op *op_l, t_lab *lab_l)
{
  if (lab_str_valid(cmd))
    tra_line_new_undefined_label(cmd, lab_l);
  else
    tra_line_opcode(cmd, op_l, lab_l);
  return (0);
}
