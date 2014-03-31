/*
** machine.h for Corewar in /home/chapui_s/travaux/Corewar/VM
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Thu Mar 20 15:06:25 2014 chapui_s
** Last update Mon Mar 31 19:42:50 2014 chapui_s
*/

#ifndef MACHINE_H_
# define MACHINE_H_

# include <SDL/SDL.h>
# include <SDL/SDL_ttf.h>

typedef struct		s_champions
{
  char			*filename;
  unsigned int		prog_number;
  unsigned int		load_address;
  char			*name;
  char			*comment;
  unsigned int		is_dead;
  int			*reg;
  unsigned int		pc;
  unsigned int		carry;
  unsigned int		last_live;
  unsigned int		cycle_to_wait;
  struct s_champions	*next;
}			t_champions;

typedef struct		s_corewar
{
  unsigned char		*arena;
  unsigned char		*info_arena;
  unsigned int		nbr_cycle_dump;
  unsigned int		nb_champions;
  t_champions		*champions;
}			t_corewar;

typedef struct		s_gui
{
  SDL_Surface		*screen;
  SDL_Surface		*byte_arena;
  TTF_Font		*font;
  SDL_Color		my_color;
}			t_gui;

typedef struct		s_instruction
{
  unsigned char		code;
  unsigned char		type;
  int			params[4];
}			t_instruction;

typedef struct		s_functions
{
  int			numero;
  void			(*function)(t_corewar *core,
				    t_champions *champions,
				    t_instruction *instruction);
}			t_functions;

# define ALLOC_FAILED	"error: could not alloc\n"
# define LIVE		1
# define LD		2
# define ST		3
# define ADD		4
# define SUB		5
# define AND		6
# define OR		7
# define XOR		8
# define ZJMP		9
# define LDI		10
# define STI		11
# define FORK		12
# define LLD		13
# define LLDI		14
# define LFORK		15
# define AFF		16

int			usage(void);
int			my_putstr(char *s, int fd);
int			get_args(int argc, char **argv, t_corewar *core);
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
int			load_arena(t_corewar *core);
void			init_arena(unsigned char *ptr, unsigned int size, int value);
void			my_putchar(char c);
int			load_champions_in_arena(unsigned char *arena,
						unsigned char *info_arena,
						t_corewar *core);

int			my_showmem(unsigned char *str, int size);
int			my_gui(t_corewar *core,
			       int size);
char			*hex_to_str(unsigned char c, char *str);
int			get_color(t_gui *gui,
				  t_corewar *core,
				  int i);
int			get_name_comment_champions(t_champions *champions,
						   int fd);
int			my_strlen(char *s);
void			get_instruction(t_corewar *core,
					t_champions *champions,
					t_instruction *instruction);
int			exec_instructions(t_corewar *core,
					  t_champions *champions);
void			my_live(t_corewar *core,
				t_champions *champions,
				t_instruction *instruction);
void			my_ld(t_corewar *core,
				t_champions *champions,
				t_instruction *instruction);
void			my_st(t_corewar *core,
			      t_champions *champions,
			      t_instruction *instruction);
void			my_add(t_corewar *core,
			       t_champions *champions,
			       t_instruction *instruction);
void			my_sub(t_corewar *core,
			       t_champions *champions,
			       t_instruction *instruction);
void			my_and(t_corewar *core,
			       t_champions *champions,
			       t_instruction *instruction);
void			my_or(t_corewar *core,
			      t_champions *champions,
			      t_instruction *instruction);
void			my_xor(t_corewar *core,
			       t_champions *champions,
			       t_instruction *instruction);
void			my_ldi(t_corewar *core,
			       t_champions *champions,
			       t_instruction *instruction);
void			my_sti(t_corewar *core,
			       t_champions *champions,
			       t_instruction *instruction);
void			my_zjmp(t_corewar *core,
				t_champions *champions,
				t_instruction *instruction);
int			read_arena(t_corewar *core, int index, int n_to_read);
void			write_arena_four(t_corewar *core,
					 t_champions *champions,
					 int to_write,
					 int index);
int			is_direct(int octet_type, int num_param);
int			is_indirect(int octet_type, int num_param);
int			is_register(unsigned char octet_type, int num_param);
int			is_good_register(int nb);

#endif /* !MACHINE_H_ */
