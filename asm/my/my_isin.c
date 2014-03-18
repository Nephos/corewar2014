/*
** my_isin.c<2> for  in /home/poulet_a/projets/corewar/asm
** 
** Made by poulet_a
** Login   <poulet_a@epitech.net>
** 
** Started on  Tue Mar 18 13:51:32 2014 poulet_a
** Last update Tue Mar 18 13:51:54 2014 poulet_a
*/

int	my_isin(const char c, const char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == c)
	return (i);
      i++;
    }
  return (-1);
}
