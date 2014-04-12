/*
** get_img.c for  in /home/broggi_t/projets/corewar/VM/gui
** 
** Made by broggi_t
** Login   <broggi_t@epitech.eu>
** 
** Started on  Sat Apr 12 16:27:35 2014 broggi_t
** Last update Sat Apr 12 16:27:35 2014 broggi_t
*/

#include <stdlib.h>
#include "../machine.h"

char	*get_image_path(char *exec_path)
{
  int	i;
  char	*img;

  i = my_strlen(exec_path) - 1;
  while (i >=0 && exec_path[i] != '/')
    --i;
  if ((img = malloc(sizeof(char) * (i + my_strlen("Corewar.bmp")))) == NULL)
    return (NULL);
  exec_path[i] = 0;
  img = my_strcat(exec_path, "Corewar.bmp");
  my_putstr(img, 1);
  return (img);
}
