/*
** main.c for  in /home/poulet_a/projets/corewar
** 
** Made by poulet_a
** Login   <poulet_a@epitech.net>
** 
** Started on  Tue Mar 11 08:22:38 2014 poulet_a
** Last update Mon Mar 17 18:03:01 2014 poulet_a
*/

#include <stdlib.h>
#include "my.h"
#include "file.h"
#include "get_cmd.h"

int     main(int ac, char **av)
{
  int	fd[2];
  char	*cmd;
  int	i;

  if (ac < 2)
    return (my_putstr("Error : no input file\n"));
  i = 1;
  while (i < ac)
    {
      fd[0] = asm_open_s_file(av[i]);
      if ((av[i] = asm_name_s_to_cor(av[i])) == NULL)
	return (2);
      fd[1] = asm_open_cor_file(av[i]);
      if (fd[0] < 0 || fd[1] < 0)
	return (121);
      while ((cmd = asm_get_next_cmd(fd[0])) != NULL)
	{
	  /* README.md */
	}
      i++;
    }
  return (0);
}
