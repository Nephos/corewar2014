/*
** main.c for  in /home/poulet_a/projets/corewar
** 
** Made by poulet_a
** Login   <poulet_a@epitech.net>
** 
** Started on  Tue Mar 11 08:22:38 2014 poulet_a
** Last update Fri Mar 14 19:26:03 2014 poulet_a
*/

#include <stdlib.h>
#include "my.h"
#include "file.h"

int     main(void)
{
  int	fd[2];

  fd[0] = asm_open_s_file("asm.s");
  fd[1] = asm_open_cor_file("asm.cor");
  return (0);
}
