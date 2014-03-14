/*
** my_strdup.c for  in /home/poulet_a/projets/minishell1/src
** 
** Made by poulet_a
** Login   <poulet_a@epitech.eu>
** 
** Started on  Mon Dec 16 15:30:14 2013 poulet_a
** Last update Fri Mar 14 11:28:21 2014 poulet_a
*/

#include <stdlib.h>
#include "my.h"

char		*my_strdup(const char *src)
{
  unsigned int	i;
  unsigned int	imax;
  char		*dup;

  i = 0;
  if (src == NULL)
    return (NULL);
  imax = my_strlen(src);
  if ((dup = malloc(imax + 1)) == NULL)
    return (NULL);
  while (i < imax)
    {
      dup[i] = src[i];
      i++;
    }
  dup[i] = 0;
  return (dup);
}
