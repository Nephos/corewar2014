/*
** machine.h for Corewar in /home/chapui_s/travaux/Corewar/VM
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Thu Mar 20 15:06:25 2014 chapui_s
** Last update Fri Mar 21 22:43:45 2014 chapui_s
*/

#ifndef MACHINE_H_
# define MACHINE_H_

typedef struct		s_champions
{
  char			*filename;
  unsigned int		prog_number;
  unsigned int		load_address;
  unsigned int		is_dead;
  int			*reg;
  unsigned int		pc;
  unsigned int		carry;
  unsigned int		last_live;
  unsigned int		cycle_to_wait;
  unsigned int		next_instruction;
  struct s_champions	*next;
}			t_champions;

typedef struct		s_corewar
{
  unsigned int		nbr_cycle_dump;
  unsigned int		nb_champions;
  t_champions		*champions;
}			t_corewar;

# define ALLOC_FAILED	"error: could not alloc\n"

int			usage(void);
int			my_putstr(char *s, int fd);
int			get_args(int argc, char **argv, t_corewar *arguments);
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
int			attribute_address(t_champions *list_champions,
					  unsigned int nb_champions);
int			load_arena(t_corewar *arguments);
void			init_arena(unsigned char *ptr, unsigned int size, int value);
void			my_putchar(char c);
int			load_champions_in_arena(unsigned char *arena,
						t_corewar *arguments);

int			my_showmem(unsigned char *str, int size);

#endif /* !MACHINE_H_ */