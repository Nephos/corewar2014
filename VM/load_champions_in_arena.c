/*
** load_champions_in_arena.c for Corewar in /home/chapui_s/travaux/Corewar/VM
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Fri Mar 21 16:06:34 2014 chapui_s
** Last update Fri Mar 21 22:44:52 2014 chapui_s
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "machine.h"
#include "../op/op.h"

static int		load_file_in_arena(unsigned char *arena,
					   t_champions *champions)
{
  int			fd;
  int			s_read;
  char			buf;
  unsigned int		i;

  while (champions)
  {
    i = champions->load_address;
    if ((fd = open(champions->filename, O_RDONLY)) == -1)
      return (my_putstr("error: could not open file\n", 2));
    if ((lseek(fd, sizeof(struct header_s), SEEK_SET)) == -1)
      return (my_putstr("error: lseek\n", 2));
    while ((s_read = read(fd, &buf, 1)) > 0)
    {
      arena[i] = buf;
      i += 1;
    }
    close(fd);
    champions = champions->next;
  }
  return (0);
}

static void		init_reg(int *reg, unsigned prog_number)
{
  unsigned int		i;

  i = 2;
  reg[1] = (int)prog_number;
  while (i < REG_NUMBER + 1)
  {
    reg[i] = 0;
    i += 1;
  }
}

static int		init_values_champions(t_champions *champions)
{
  while (champions)
  {
    if ((champions->reg = (int*)malloc(sizeof(int) * (REG_NUMBER + 1)))
	== NULL)
      return (my_putstr(ALLOC_FAILED, 2));
    init_reg(champions->reg, champions->prog_number);
    champions->is_dead = 0;
    champions->pc = champions->load_address;
    champions->carry = 0;
    champions->last_live = 0;
    champions->cycle_to_wait = 0;
    champions->next_instruction = 0;
    champions = champions->next;
  }
  return (0);
}

int			load_champions_in_arena(unsigned char *arena,
						t_corewar *arguments)
{
  if ((load_file_in_arena(arena, arguments->champions)) == -1)
    return (-1);
  init_values_champions(arguments->champions);
  return (0);
}
