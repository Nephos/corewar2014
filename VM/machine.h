/*
** machine.h for Corewar in /home/chapui_s/travaux/Corewar/VM
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Thu Mar 20 15:06:25 2014 chapui_s
** Last update Thu Mar 20 20:40:18 2014 chapui_s
*/

#ifndef MACHINE_H_
# define MACHINE_H_

typedef struct		s_champions
{
  char			*filename;
  unsigned int		prog_number;
  unsigned int		load_address;
  struct s_champions	*next;
}			t_champions;

typedef struct		s_args
{
  unsigned int		nbr_cycle_dump;
  unsigned int		nb_champions;
  t_champions		*champions;
}			t_args;

# define ALLOC_FAILED	"error: could not alloc\n"

int			usage(void);
int			my_putstr(char *s, int fd);
int			get_args(int argc, char **argv, t_args *arguments);
int			is_numbers(char *s);
int			is_options(char *s);
int			my_strcmp(char *s1, char *s2);
int			is_file_dot_cor(char *s);
int			is_one_file_cor(int argc, char **argv);
int			push_champion(t_champions **list_champions,
				      char *filename,
				      unsigned int prog_number,
				      unsigned int load_address);
unsigned int		my_unsigned_atoi(char *str);
int			attribute_prog_number(t_champions *list_champions,
					      unsigned int nb_champions);

#endif /* !MACHINE_H_ */
