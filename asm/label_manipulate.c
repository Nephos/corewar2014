/*
** label_manipulate.c for  in /home/poulet_a/projets/corewar/asm
** 
** Made by poulet_a
** Login   <poulet_a@epitech.net>
** 
** Started on  Wed Mar 19 14:50:23 2014 poulet_a
** Last update Wed Mar 19 15:08:14 2014 poulet_a
*/

#include "label.h"

int	lab_valid(char *name)
{
  int	len;
  int	i;

  if ((len = my_strlen(name) - 1) < 0)
    return (0);
  i = 0;
  while (i < len)
    if (my_isin(name[i++], LABEL_CHARS) == -1)
      return (0);
  return (my_match(name, "*:"));
}

int	lab_get_addr(char *str)
{
  t_lab	*labels;

  if ((labels = lab_list()) == NULL)
    return (-1);
  while (label->next != NULL)
    {
      if (labels->name != NULL && my_match(labels->name, str))
	return (labels->addr);
      i++;
    }
  return (-1);
}
