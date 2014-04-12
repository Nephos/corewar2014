/*
** my_strcmp.c for strcmp in /home/chapui_s/rendu/Piscine-C-Jour_06/ex_05
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Mon Oct  7 10:26:21 2013 chapui_s
** Last update Thu Apr 10 22:25:15 2014 chapui_s
*/

#include <stdlib.h>

int	my_strcmp(char *s1, char *s2)
{
  return ((*s1 == *s2 && *s1) ? (my_strcmp(++s1, ++s2)) : (*s1 - *s2));
}
