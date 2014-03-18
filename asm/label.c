/*
** label.c for  in /home/poulet_a/projets/corewar/asm
** 
** Made by poulet_a
** Login   <poulet_a@epitech.net>
** 
** Started on  Fri Mar 14 13:08:15 2014 poulet_a
** Last update Tue Mar 18 14:00:43 2014 poulet_a
*/

#include <stdlib.h>
#include "../op/op.h"
#include "my.h"
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

t_label		*lab_init()
{
  t_label	*labels;
  int		i;

  if ((labels = malloc(sizeof(t_label) * MEM_SIZE)) == NULL)
    return (NULL);
  i = 0;
  while (i < MEM_SIZE)
    {
      labels[i].name = NULL;
      labels[i].addr = -1;
      i++;
    }
  return (labels);
}

/*
** Choose a str or an id. (NULL/-1 if not used)
*/
t_label			*lab_list()
{
  static t_label	*labels = NULL;

  if (labels == NULL)
    labels = lab_init();
  return (labels);
}

int		lab_get_addr(char *str)
{
  int		i;
  t_label	*labels;

  if ((labels = lab_list()) == NULL)
    return (-1);
  i = 0;
  while (i < MEM_SIZE)
    {
      if (labels[i].name != NULL && my_match(labels[i].name, str))
	return (labels[i].addr);
      i++;
    }
  return (-1);
}
