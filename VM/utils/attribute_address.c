/*
** attribute_address.c for Corewar in /home/chapui_s/travaux/Corewar/VM/utils
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Fri Mar 21 19:15:12 2014 chapui_s
** Last update Fri Mar 21 21:01:39 2014 chapui_s
*/

#include "../machine.h"
#include "../../op/op.h"

int		attribute_address(t_champions *champions,
				  unsigned int nb_champions)
{
  unsigned int	cur;
  unsigned int	place_after;

  cur = 0;
  place_after = MEM_SIZE / nb_champions;
  while (champions)
  {
    champions->load_address = cur;
    cur += place_after;
    champions = champions->next;
  }
  return (0);
}
