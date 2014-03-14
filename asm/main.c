/*
** main.c for  in /home/poulet_a/projets/corewar
** 
** Made by poulet_a
** Login   <poulet_a@epitech.net>
** 
** Started on  Tue Mar 11 08:22:38 2014 poulet_a
** Last update Fri Mar 14 20:53:21 2014 poulet_a
*/

#include <stdlib.h>
#include "my.h"
#include "file.h"
#include "get_cmd.h"

int     main(void)
{
  int	fd[2];
  char	*cmd;

  fd[0] = asm_open_s_file("asm.s");
  fd[1] = asm_open_cor_file("asm.cor");
  if (fd[0] < 0 || fd[1] < 0)
    return (1);
  while ((cmd = get_cmd(fd[0])) != NULL)
    {
      /* README.md */
    }
  return (0);
}
