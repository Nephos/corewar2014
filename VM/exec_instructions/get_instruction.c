/*
** get_instruction.c for Corewar in /Corewar/VM/exec_instructions
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Mar 25 15:28:46 2014 chapui_s
** Last update Tue Mar 25 22:06:33 2014 
*/

#include "../machine.h"
#include "../../op/op.h"

static int	read_n_bytes(t_corewar *core, int index, int nb)
{
  int		ret;
  int		i;

  ret = 0;
  i = 0;
  while (i < nb)
    {
      ret = ret << 8;
      ret += core->arena[index + i];
      ++i;
    }
  return ((nb == 1 && ret > 16) ? (16) : (ret));
}

static void	fulfil_params(t_corewar *core,
			      t_champions *champion,
			      t_instruction *instruction)
{
  unsigned char	tmp_type;
  int		i;
  int		decal;

  tmp_type = instruction->type;
  decal = champion->pc + 2;
  i = 0;
  while (tmp_type & 0b11000000)
    {
      if (tmp_type >> 6 == 1)
	instruction->params[i] = champion->reg[read_n_bytes(core, decal++, 1)];
      else if (tmp_type >> 6 == 0b10)
	{
	  /*	  instruction->params[i] = read_n_bytes(core, decal,*/
	}
      else
	{
	  instruction->params[i] = read_n_bytes(core, decal, 2);
	  decal += 2;
	}
      tmp_type = tmp_type << 2;
      ++i;
    }
}

static void	get_type_and_param(t_corewar *core,
				   t_champions *champions,
				   t_instruction *instruction)
{
  if (instruction->code != LIVE && instruction->code != ZJMP
      && instruction->code != FORK && instruction->code != LFORK)
    {
      instruction->type = core->arena[champions->pc + 1];
      fulfil_params(core, champions, instruction);
    }
  else
    {
      instruction->type = 0;
      if (instruction->code == LIVE)
	instruction->params[0] = read_n_bytes(core, champions->pc + 1, 4);
      else
	instruction->params[0] = read_n_bytes(core, champions->pc + 1, 2);
    }
}

void		get_instruction(t_corewar *core,
				t_champions *champions,
				t_instruction *instruction)
{
  champions->pc = 15;
  instruction->code = core->arena[champions->pc];
  get_type_and_param(core, champions, instruction);
  if (instruction->code <= 16 && instruction->code >= 1)
    ; /*appel de la bonne fonction */
}
