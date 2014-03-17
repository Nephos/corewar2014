/*
** get_cmd.c for  in /home/poulet_a/projets/corewar/asm
** 
** Made by poulet_a
** Login   <poulet_a@epitech.net>
** 
** Started on  Fri Mar 14 18:41:59 2014 poulet_a
** Last update Mon Mar 17 14:03:13 2014 poulet_a
*/

#include <stdlib.h>
#include "my/my.h"

static int	spe_is_comment(char *str)
{
  return (my_match(str, "#*"));
}

char	*asm_get_next_cmd(int fd)
{
  char	*cmd;

  cmd = get_next_line(fd);
  while (cmd != NULL && spe_is_comment(cmd))
    cmd = get_next_line(fd);
  return (cmd);
}
