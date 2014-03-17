/*
** my_putstr.c for  in /home/poulet_a/tmp-rendu/Piscine-C-Jour_04
** 
** Made by a
** Login   <poulet_a@epitech.net>
** 
** Started on  Tue Sep  3 09:47:06 2013 poulet_a
** Last update Mon Feb  3 11:38:01 2014 poulet_a
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	my_putstr(char *str)
{
  int	i;

  if (str == NULL)
    return (-1);
  i = 0;
  while (str[i] && str)
    {
      write(1, str + i, 1);
      i = i + 1;
    }
  return (i);
}

int	my_puterr(char *str)
{
  int	i;

  if (str == NULL)
    return (-1);
  i = 0;
  while (str[i] && str)
    {
      write(2, str + i, 1);
      i = i + 1;
    }
  return (i);
}

int	my_putnstr(char *str, int n)
{
  int	i;

  if (str == NULL)
    return (-1);
  i = 0;
  while (str[i] && str && i < n)
    {
      write(1, str + i, 1);
      i = i + 1;
    }
  return (i);
}

int	my_put2str(char *s1, char *s2)
{
  return (my_putstr(s1) + my_putstr(s2));
}
int	my_put3str(char *s1, char *s2, char *s3)
{
  return (my_putstr(s1) + my_putstr(s2) + my_putstr(s3));
}
