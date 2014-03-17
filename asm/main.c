/*
** main.c for  in /home/poulet_a/projets/corewar
** 
** Made by poulet_a
** Login   <poulet_a@epitech.net>
** 
** Started on  Tue Mar 11 08:22:38 2014 poulet_a
** Last update Mon Mar 17 19:42:59 2014 poulet_a
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
      asm_open_files(av[i], fd);
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
