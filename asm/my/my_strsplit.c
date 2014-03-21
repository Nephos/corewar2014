/*
** my_strsplit.c for  in /home/poulet_a/projets/minishell1/src
** 
** Made by poulet_a
** Login   <poulet_a@epitech.eu>
** 
** Started on  Wed Dec 18 09:05:09 2013 poulet_a
** Last update Fri Mar 14 18:36:49 2014 poulet_a
*/

#include <stdlib.h>
#include "my.h"

static char	my_split_issep(char c)
{
  if (c == ' ' || c == '\t' || c == ',')
    return (c);
  return (0);
}

static unsigned int	my_strsplit_count(char *str)
{
  unsigned int		i;
  unsigned int		n;

  if (str == NULL || str[0] == 0)
    return (0);
  n = 1;
  i = 0;
  while (str[i])
    {
      if (my_split_issep(str[i])
	  && str[i + 1] && !my_split_issep(str[i + 1]))
	n++;
      i++;
    }
  return (n);
}

char		**my_strsplit(char *str)
{
  char		**out;
  char		*str_cpy;
  unsigned int	i;
  unsigned int	n;

  if (str == NULL || str[0] == 0)
    return (NULL);
  if ((out = malloc(sizeof(char*) * (my_strsplit_count(str) + 1))) == NULL)
    return (NULL);
  str_cpy = my_strdup(str);
  n = 1;
  i = 0;
  out[0] = str_cpy;
  while (str[i])
    {
      if (my_split_issep(str[i]))
	{
	  str_cpy[i] = 0;
	  if (str[i + 1] && !my_split_issep(str[i + 1]))
	    out[n++] = str_cpy + i + 1;
	}
      i++;
    }
  out[n] = 0;
  return (out);
}
