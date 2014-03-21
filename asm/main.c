/*
** main.c for  in /home/poulet_a/projets/corewar
** 
** Made by poulet_a
** Login   <poulet_a@epitech.net>
** 
** Started on  Tue Mar 11 08:22:38 2014 poulet_a
** Last update Thu Mar 20 18:05:40 2014 poulet_a
*/

#include <stdlib.h>
#include "my/my.h"
#include "list.h"
#include "file.h"
#include "get_cmd.h"
#include "translate.h"

int	main_convert(char *name)
{
  char	*cmd;
  int	fd[2];
  t_op	*op_l;
  t_lab	*lab_l;

  asm_open_files(name, fd);
  if (fd[0] < 0 || fd[1] < 0)
    return (121);
  while ((cmd = asm_get_next_cmd(fd[0])) != NULL)
    {
      ;
    }
  return (0);
}

int     main(int ac, char **av)
{
  int	i;

  if (ac == 1)
    return (my_putstr("Error : no input file\n"));
  i = 1;
  while (i < ac)
    main_convert(av[i++]);
  return (0);
}
