/*
** get_instruction.c for Corewar in /Corewar/VM/exec_instructions
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Mar 25 15:28:46 2014 chapui_s
** Last update Tue Mar 25 18:07:54 2014 chapui_s
*/

#include "../machine.h"

static void	get_type_and_param(t_corewar *core,
			 t_champions *champions,
			 t_instruction *instruction)
{
  if (instruction->code != LIVE && instruction->code != ZJMP
      && instruction->code != FORK && instruction->code != LFORK)
    instruction->type = core->arena[champions->pc + 1];
  else
    instruction->type = 0;
}

void		get_instruction(t_corewar *core,
				t_champions *champions,
				t_instruction *instruction)
{
  instruction->code = core->arena[champions->pc];
  get_type_and_param(core, champions, instruction);
}
