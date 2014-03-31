/*
** my_ldi.c for Corewar in /home/chapui_s/travaux/Corewar/VM/functions
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Fri Mar 28 17:52:46 2014 chapui_s
** Last update Tue Apr  1 00:03:25 2014 chapui_s
*/

#include "../../op/op.h"
#include "../machine.h"

static int	get_first_value(t_corewar *core,
				t_champions *champions,
				t_instruction *instruction)
{
  int		first_value;
  int		ptr;

  first_value = 0;
  if (is_register(instruction->type, 1) == 1)
  {
    if (is_good_register(instruction->params[0]) == 1)
    {
      first_value = read_arena(core, champions->pc - 6
			       + (champions->reg[instruction->params[0]]
				  % IDX_MOD), 2);
    }
  }
  else if (is_direct(instruction->type, 1) == 1)
  {
    ptr = champions->pc - 6 + (instruction->params[0] % IDX_MOD);
    /* if (instruction->params[0] < 0) */
    /*   instruction->params[0] = champions->pc + instruction->params[0] */
    /* 	+ MEM_SIZE; */
    printf("ptr = %d\n", ptr);
    first_value = read_arena(core, ptr, 2);
  }
  else if (is_indirect(instruction->type, 1) == 1)
    first_value = read_arena(core, champions->pc - 6
			     + (instruction->params[0]  % IDX_MOD), 2);
  return (first_value);
}

static int	get_second_value(t_corewar *core,
				 t_champions *champions,
				 t_instruction *instruction)
{
  int		second_value;

  (void)core;
  second_value = 0;
  if (is_register(instruction->type, 2) == 1)
  {
    if (is_good_register(instruction->params[1]) == 1)
      second_value = champions->reg[instruction->params[1]];
  }
  else if (is_direct(instruction->type, 2) == 1)
    second_value = instruction->params[1];
  return (second_value);
}

void		my_ldi(t_corewar *core,
		       t_champions *champions,
		       t_instruction *instruction)
{
  int		first_value;
  int		second_value;
  int		read_value;

  first_value = get_first_value(core, champions, instruction);
  /* printf("first_value = %d\n", first_value); */
  second_value = get_second_value(core, champions, instruction);
  /* printf("FIRST = %d, RES_FIRST = %d\n", first_value, champions->pc - 5 + (first_value % IDX_MOD)); */
  /* read_value = read_arena(core, champions->pc - 5 + (first_value % IDX_MOD), 2); */
  /* printf("FIRST READ = %d\n", read_value); */
  read_value = first_value +  second_value;
  /* printf("FIRST READ + SECOND = %d\n", read_value); */
  read_value = read_arena(core, champions->pc - 6 + (read_value % IDX_MOD), 4);
  /* printf("FINAL READ = %d\n", read_value); */
  /* printf("FIRST = %d SECOND = %d RES = %d PC = %d\n", first_value, second_value, */
  /* 	 champions->pc - 5 + ((first_value + second_value) % IDX_MOD), champions->pc); */
  /* read_value = read_arena(core, champions->pc - 5 */
  /* 			  + ((first_value + second_value) % IDX_MOD), 4); */
  if (is_register(instruction->type, 3) == 1)
  {
    if (is_good_register(instruction->params[2]) == 1)
    {
      champions->reg[instruction->params[2]] = read_value;
      printf("REG[%d] = %d\n", instruction->params[2], read_value);
      champions->carry = (read_value) ? (0) : (1);
    }
  }
}
