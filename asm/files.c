/*
** files.c for  in /home/poulet_a/projets/corewar/Asm
** 
** Made by poulet_a
** Login   <poulet_a@epitech.net>
** 
** Started on  Thu Mar 13 15:55:28 2014 poulet_a
** Last update Thu Mar 13 20:25:19 2014 poulet_a
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	asm_open_s_file(char *name)
{
  int	flags;
  int	fd;

  if (name == NULL)
    return (-1);
  flags = O_RDONLY;
  if ((fd = open(name, flags)) < 0)
    return (-1);
  return (fd);
}

int	asm_open_cor_file(char *name)
{
  int	flags;
  int	rights;
  int	fd;

  if (name == NULL)
    return (-1);
  flags = O_RDONLY;
  rights = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
  if ((fd = open(name, flags, rights)) < 0)
    return (-1);
  return (fd);
}
