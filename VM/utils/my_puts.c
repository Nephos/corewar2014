/*
** my_puts.c for Corewar in /home/chapui_s/travaux/Corewar/VM/utils
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Thu Mar 20 17:04:58 2014 chapui_s
** Last update Fri Mar 21 15:57:18 2014 chapui_s
*/

#include <unistd.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_putstr(char *s, int fd)
{
  while (s && *s)
    write(fd, s++, 1);
  return ((fd == 2) ? (-1) : (0));
}
