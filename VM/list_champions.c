/*
** list_champions.c for Corewar in /home/chapui_s/travaux/Corewar/VM
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Thu Mar 20 19:29:58 2014 chapui_s
** Last update Thu Mar 20 20:19:27 2014 chapui_s
*/

#include <stdlib.h>
#include "machine.h"

static t_champions	*create_champion(char *filename,
					 unsigned int prog_number,
					 unsigned int load_address)
{
  t_champions		*new;

  if ((new = (t_champions*)malloc(sizeof(*new))) != NULL)
  {
    new->filename = filename;
    new->prog_number = prog_number;
    new->load_address = load_address;
    new->next = NULL;
  }
  else
    my_putstr(ALLOC_FAILED, 2);
  return (new);
}

int		push_champion(t_champions **list_champion,
			      char *filename,
			      unsigned int prog_number,
			      unsigned int load_address)
{
  t_champions	*tmp;

  tmp = *list_champion;
  if (tmp)
  {
    while (tmp->next)
      tmp = tmp->next;
    if ((tmp->next = create_champion(filename,
				     prog_number,
				     load_address)) == NULL)
      return (-1);
  }
  else
    if ((*list_champion = create_champion(filename,
					  prog_number,
					  load_address)) == NULL)
      return (-1);
  return (0);
}
