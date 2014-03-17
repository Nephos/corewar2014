/*
** file.h for  in /home/poulet_a/projets/corewar/asm
** 
** Made by poulet_a
** Login   <poulet_a@epitech.net>
** 
** Started on  Fri Mar 14 19:26:13 2014 poulet_a
** Last update Mon Mar 17 19:42:36 2014 poulet_a
*/

#ifndef FILE_H_
# define FILE_H_

void	asm_open_files(char *name, int fd[2]);
char	*asm_name_s_to_cor(char *name);
int	asm_open_s_file(char *name);
int	asm_open_cor_file(char *name);

#endif /* !FILE_H_ */
