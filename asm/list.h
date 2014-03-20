/*
** list.h for  in /home/poulet_a/projets/corewar/asm
** 
** Made by poulet_a
** Login   <poulet_a@epitech.net>
** 
** Started on  Mon Mar 17 18:58:53 2014 poulet_a
** Last update Thu Mar 20 15:20:43 2014 poulet_a
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct	s_list_label
{
  char		*name;
  int		addr;
  s_list_label	*next;
}		t_lab;

typedef struct	s_list_op
{
  char		*datas;
  short		*types;
  int		size;
  s_list_op	*next;
}		t_op;

#endif /* !LIST_H_ */
