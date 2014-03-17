/*
** get_next_line.h for gnl in /home/chapui_s/travaux/get_next_line
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Tue Nov 19 16:54:01 2013 chapui_s
** Last update Mon Mar 17 13:26:04 2014 poulet_a
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

#define BUF_SIZE	42

typedef struct	s_fd
{
  char		*str;
  int		fd;
  struct s_fd	*next;
}		t_fd;

#endif
