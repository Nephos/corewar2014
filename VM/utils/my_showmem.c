/*
** my_showmem.c for showmem in /home/chapui_s/rendu/Piscine-C-Jour_06/ex_18
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Mon Oct  7 18:05:37 2013 chapui_s
** Last update Fri Mar 21 16:03:23 2014 chapui_s
*/

#include "../machine.h"

int		my_putnbr_base(int nbr, char *base, int is_write)
{
  int		result[40];
  int		i;

  i = 0;
  if (nbr < 0)
    nbr = -nbr;
  while (nbr > 0)
  {
    result[i] = base[nbr % 16];
    nbr = nbr / 16;
    i = i + 1;
  }
  i = i - 1;
  if (is_write == 0)
    return (i + 1);
  if (is_write == 1)
  {
    while (i >= 0)
    {
      my_putchar(result[i]);
      i = i - 1;
    }
  }
  return (0);
}

void		write_addr(int line)
{
  int		addr;
  int		nb_zeros;
  int		i;

  i = 0;
  addr = 16 * line;
  nb_zeros = my_putnbr_base(addr, "0123456789ABCDEF", 0);
  while (i < (8 - nb_zeros))
  {
    my_putchar('0');
    i = i + 1;
  }
  my_putnbr_base(addr, "0123456789ABCDEF", 1);
  my_putchar(':');
  my_putchar(' ');
}

void		write_car(char *str, int begin, int end)
{
  int		i;

  i = 0;
  my_putchar(' ');
  my_putchar(' ');
  while (i < 16 && (begin + i < end))
  {
    if (str[begin + i] >= 32 && str[begin + i] <= 126)
      my_putchar(str[begin + i]);
    else
      my_putchar('.');
    i = i + 1;
  }
}

void		write_hex(int i, int line_cur, int size, char *str)
{
  while (i < (16 * line_cur + 16) && i < size)
  {
    if (i % 2 == 0 && i != 16 * line_cur)
      my_putchar(' ');
    if (str[i] == '\0')
      my_putchar('0');
    if (str[i] == '\0')
      my_putchar('0');
    my_putnbr_base(str[i], "0123456789ABCDEF", 1);
    i = i + 1;
  }
  while (i < (16 * line_cur + 16))
  {
    if (i % 2 == 0 && i != 16 * line_cur)
      my_putchar(' ');
    my_putchar(' ');
    my_putchar(' ');
    i = i + 1;
  }
}

int		my_showmem(char *str, int size)
{
  int		nb_lines;
  int		line_cur;
  int		i;

  line_cur = 0;
  i = 0;
  nb_lines = 1 + size / 16;
  while (line_cur < nb_lines && i < size)
  {
    write_addr(line_cur);
    write_hex(i, line_cur, size, str);
    write_car(str, 16 * line_cur, size);
    my_putchar('\n');
    line_cur = line_cur + 1;
    i = 16 * line_cur;
  }
  return (0);
}
