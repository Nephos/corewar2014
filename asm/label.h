/*
** label.h for  in /home/poulet_a/projets/corewar/asm
** 
** Made by poulet_a
** Login   <poulet_a@epitech.net>
** 
** Started on  Fri Mar 14 13:06:51 2014 poulet_a
** Last update Wed Mar 19 15:11:05 2014 poulet_a
*/

#ifndef LABEL_H_
# define LABEL_H_

# include "list.h"

/*
** Basic manipulating function of label
*/
int	lab_size(t_lab *list);
t_lab	*lab_new(char *name, int addr, t_lab *next, t_lab *prev);
t_lab	*lab_create(t_lab *list, char *name, int addr);
t_lab	*lab_create_at_begin(t_lab *list, char *name, int addr);
t_lab	*lab_last(t_lab *list);

/*
** Management of label str <-> label,
** research
*/
int	lab_str_valid(char *name);
int	lab_get_addr(char *str);

#endif /* !LABEL_H_ */
