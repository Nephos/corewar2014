/*
** files.c for  in /home/poulet_a/projets/corewar/Asm
** 
** Made by poulet_a
** Login   <poulet_a@epitech.net>
** 
** Started on  Thu Mar 13 15:55:28 2014 poulet_a
** Last update Mon Mar 17 19:44:34 2014 poulet_a
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "my/my.h"
#include "file.h"

void	asm_open_files(char *name, int fd[2])
{
  fd[0] = asm_open_s_file(name);
  if ((name = asm_name_s_to_cor(name)) == NULL)
    return ;
  fd[1] = asm_open_cor_file(name);
}

char	*asm_name_s_to_cor(char *name)
{
  char	*out;
  int	len;
  int	i;

  len = my_strlen(name);
  if (len < -1)
    return (NULL);
  out = malloc(len + 5);
  i = 0;
  while (i < len && my_match(name + i, ".s") == 0)
    {
      out[i] = name[i];
      i++;
    }
  out[i + 0] = '.';
  out[i + 1] = 'c';
  out[i + 2] = 'o';
  out[i + 3] = 'r';
  out[i + 4] = '\0';
  return (out);
}

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
