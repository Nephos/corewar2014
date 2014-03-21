/*
** init_arena.c for Corewar in /home/chapui_s/travaux/Corewar/VM/utils
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Fri Mar 21 15:46:53 2014 chapui_s
** Last update Fri Mar 21 18:22:00 2014 chapui_s
*/

void		init_arena(unsigned char *ptr, unsigned int size, int value)
{
  unsigned int	i;


  i = 0;
  while (i < size)
  {
    ptr[i] = value;
    i += 1;
  }
}
