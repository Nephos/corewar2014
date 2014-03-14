/*
** register.c for  in /home/poulet_a/projets/corewar/Asm
** 
** Made by poulet_a
** Login   <poulet_a@epitech.net>
** 
** Started on  Thu Mar 13 16:28:20 2014 poulet_a
** Last update Fri Mar 14 11:30:20 2014 poulet_a
*/

#include <stdlib.h>
#include "register.h"
#include "my.h"

int	reg_get_from_str(char *reg_name)
{
  int	len;
  int	n;

  if (reg_name == NULL)
    return (-1);
  len = my_strlen(reg_name);
  if (my_match(reg_name, "r*"))
    {
      n = my_getnbr(reg_name + 1);
      if (n < 1 || n > 16)
	return (REG_ERR_NOTINRANGE);
      if (n < 10 && len > 2)
	return (REG_ERR_NOTVALID);
      return (n);
    }
  return (REG_ERR_NOTVALID);
}
