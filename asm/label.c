/*
** label.c for  in /home/poulet_a/projets/corewar/asm
** 
** Made by poulet_a
** Login   <poulet_a@epitech.net>
** 
** Started on  Fri Mar 14 13:08:15 2014 poulet_a
** Last update Wed Mar 19 15:00:36 2014 poulet_a
*/

#include <stdlib.h>
#include "../op/op.h"
#include "my.h"
#include "label.h"

int	lab_size(t_lab *list)
{
  int	size;

  if (list == NULL)
    return (-1);
  size = 0;
  while (list != NULL)
    {
      size++;
      list = list->next;
    }
  return (size);
}

t_lab	*lab_new(char *name, int addr, t_lab *next)
{
  t_lab	*list;

  list = malloc(sizeof(t_lab));
  RET_NULL_NULL(list);
  list->name = name;
  list->addr = addr;
  list->next = next;
  return (list);
}

t_lab	*lab_create(t_lab *list, char *name, int addr)
{
  list = lab_last(list);
  if (list == NULL)
    return (list = lab_new(name, addr, NULL));
  list->next = lab_new(name, addr, list);
  return (list);
}

t_lab	*lab_create_at_begin(t_lab *list, char *name, int addr)
{
  if (list == NULL)
    return (list = lab_new(name, addr, NULL));
  list = lab_new(name, addr, list);
  return (list);
}

t_lab	*lab_last(t_lab *list)
{
  if (list == NULL)
    return (NULL);
  while (list->next != NULL)
    {
      list = list->next;
    }
  return (list);
}
