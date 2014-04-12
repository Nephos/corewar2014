/*
** main.c for Corewar in /home/chapui_s/travaux/Corewar/VM
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Thu Mar 20 14:45:46 2014 chapui_s
** Last update Sat Apr 12 18:24:47 2014 chapui_s
*/

#include <stdio.h>
#include <stdlib.h>
#include "machine.h"

void		print_instruction(t_corewar *core,
				  t_champions *champions,
				  t_instruction *instruction)
{
  int		tmp_type;
  int		i;

  i = 0;
  tmp_type = (instruction->type >> 2) << 2;
  while (op_tab[i].code && op_tab[i].code != instruction->code)
    i += 1;
  if (op_tab[i].code != 0)
  {
    my_putstr(op_tab[i].mnemonique, 1);
    my_putchar('\t');
    i = 0;
    if (instruction->code == LIVE || instruction->code == ZJMP
	|| instruction->code == FORK || instruction->code == LFORK)
      my_putnbr(instruction->params[0]);
    while (tmp_type & 0b11000000)
    {
      if ((tmp_type & 0b11000000) >> 6 == 1)
	my_putstr("r", 1);
      else if ((tmp_type & 0b11000000) >> 6 == 0b10)
	my_putchar(DIRECT_CHAR);
      my_putnbr(instruction->params[i]);
      tmp_type = tmp_type << 2;
      if (tmp_type & 0b11000000)
	my_putchar(SEPARATOR_CHAR);
      i += 1;
    }
  }
}

int		my_desassembler(t_corewar *core,
				t_champions *champions,
				unsigned char *arena)
{
  int		pc_base;
  t_instruction	instruction;

  pc_base = champions->pc;
  if (champions->name)
  {
    my_putstr(".name\t\t", 1);
    my_putstr(champions->name, 1);
    my_putstr("\n", 1);
  }
  if (champions->comment)
  {
    my_putstr(".comment\t", 1);
    my_putstr(champions->comment, 1);
    my_putstr("\n", 1);
  }
  while (champions->pc < (pc_base + champions->size))
  {
    get_instruction(core, champions, &instruction);
    print_instruction(core, champions, &instruction);
    my_putchar('\n');
  }
}

int		desassemble_it(t_corewar *core)
{
  t_champions	*tmp;
  int		is_filename;

  tmp = core->champions;
  is_filename = 0;
  while (tmp)
  {
    if (my_desassembler(core, tmp, core->arena) == -1)
      return (-1);
    tmp = tmp->next;
  }
  return (0);
}

int		main(int argc, char **argv)
{
  t_corewar	core;

  core.champions = NULL;
  if ((get_args(argc, argv, &core)) == -1)
    return (-1);
  if ((load_arena(&core)) == -1)
    return (-1);
  if (core.is_desassembler == 1)
    return (desassemble_it(&core));
  if ((my_gui(&core)) == -1)
    return (-1);
  return (0);
}
