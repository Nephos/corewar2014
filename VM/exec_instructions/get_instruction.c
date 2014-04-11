/*
** get_instruction.c for Corewar in /Corewar/VM/exec_instructions
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Mar 25 15:28:46 2014 chapui_s
** Last update Thu Apr 10 16:52:14 2014 chapui_s
*/

#include "../machine.h"
#include "../../op/op.h"

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
  while ((tmp_type & 0b11000000))
  {
    if (tmp_type >> 6 == 1)
    {
      instruction->params[i] = read_arena(core, decal, 1);
      decal += T_REG;
    }
    else if (tmp_type >> 6 == 0b10)
    {
      if (instruction->code != LDI && instruction->code != STI
	  && instruction->code != LLDI)
      {
	instruction->params[i] = read_arena(core, decal, 4);
	decal += T_IND;
      }
      else
      {
	if ((instruction->code == STI && (decal - champion->pc == 3 || decal - champion->pc == 5))
	    || (instruction->code == LDI && (decal - champion->pc == 2 || decal - champion->pc == 4)))
	{
	  instruction->params[i] = read_arena(core, decal, 2);
	  decal += T_DIR;
	}
	else
	{
	  instruction->params[i] = read_arena(core, decal, 4);
	  decal += T_IND;
	}
      }
    }
    else
    {
      instruction->params[i] = read_arena(core, decal, 2);
      decal += T_DIR;
    }
    tmp_type = tmp_type << 2;
    i += 1;
  }
  champion->pc += decal - champion->pc;
  champion->pc = champion->pc % MEM_SIZE;
}

static void	get_type_and_param(t_corewar *core,
				   t_champions *champions,
				   t_instruction *instruction)
{
  if (instruction->code != LIVE && instruction->code != ZJMP
      && instruction->code != FORK && instruction->code != LFORK)
    {
      instruction->type = core->arena[(champions->pc + 1) % MEM_SIZE];
      fulfil_params(core, champions, instruction);
    }
  else
    {
      instruction->type = 0;
      if (instruction->code == LIVE)
      {
	instruction->params[0] = read_arena(core, champions->pc + 1, 4);
	champions->pc += 5;
      }
      else
      {
	instruction->params[0] = read_arena(core, champions->pc + 1, 2);
	champions->pc += 3;
      }
    }
}

void		get_instruction(t_corewar *core,
				t_champions *champions,
				t_instruction *instruction)
{
  while (champions->pc < 0)
    champions->pc += MEM_SIZE;
  champions->pc = champions->pc % MEM_SIZE;
  instruction->code = core->arena[champions->pc];
  if (instruction->code >= 1 && instruction->code <= 16)
  {
    instruction->params[0] = 0;
    instruction->params[1] = 0;
    instruction->params[2] = 0;
    instruction->params[3] = 0;
    get_type_and_param(core, champions, instruction);
  }
  else
  {
    champions->carry = 0;
    champions->pc = (champions->pc + 1) % MEM_SIZE;
  }
}
