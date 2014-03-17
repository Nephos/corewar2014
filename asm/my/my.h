/*
** my.h for  in /home/poulet_a/projets/corewar/Asm
** 
** Made by poulet_a
** Login   <poulet_a@epitech.net>
** 
** Started on  Thu Mar 13 20:34:51 2014 poulet_a
** Last update Mon Mar 17 13:26:16 2014 poulet_a
*/

#ifndef MY_H_
# define MY_H_

int	my_match(char *s1, char *s2);
char	**my_strsplit(char *str);
char	*my_strdup(const char *src);
int     my_strlen(const char *str);
long	my_getnbr(char *str);
char	*get_next_line(const int fd);

#endif /* !MY_H_ */
