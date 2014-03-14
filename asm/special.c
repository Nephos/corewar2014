/*
** special.c for  in /home/poulet_a/projets/corewar/asm
** 
** Made by poulet_a
** Login   <poulet_a@epitech.net>
** 
** Started on  Fri Mar 14 13:03:39 2014 poulet_a
** Last update Fri Mar 14 17:17:21 2014 poulet_a
*/

#include <stdlib.h>
#include "my.h"
#include "special.h"

int	spe_is_comment(char *str)
{
  return (my_match(str, "#*"));
}
