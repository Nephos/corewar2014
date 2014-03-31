/*
** exec_instructions.c for Corewar in /home/chapui_s/travaux/Corewar/VM
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Mar 25 15:13:41 2014 chapui_s
** Last update Tue Apr  1 00:01:23 2014 chapui_s
*/

#include "../machine.h"

t_functions	tab_func[] =
{
  {1, my_live},
  {2, my_ld},
  {3, my_st},
  {4, my_add},
  {5, my_sub},
  {6, my_and},
  {7, my_or},
  {8, my_xor},
  {9, my_zjmp},
  {10, my_ldi},
  {11, my_sti},
};

static void	exec_function(t_corewar *core,
			      t_champions *champions,
			      t_instruction *instruction)
{
  if (instruction->code < 12 && instruction->code > 0)
  {
    tab_func[instruction->code - 1].function(core, champions, instruction);
  }
  return ;
}

int		exec_instructions(t_corewar *core, t_champions *champions)
{
  t_instruction	instruction;
  t_champions	*tmp;
  int		i;

  i = 0;
  /* while (i < 208) */
  while (i < 94)
  {
    printf("PC = %d\n", champions->pc);
    tmp = champions;
    while (tmp)
    {
      get_instruction(core, champions, &instruction);
      exec_function(core, champions, &instruction);
      tmp = tmp->next;
    }

    (instruction.code == 1) ? (printf("LIVE\n")) : (0);
    (instruction.code == 2) ? (printf("LD\n")) : (0);
    (instruction.code == 3) ? (printf("ST\n")) : (0);
    (instruction.code == 4) ? (printf("ADD\n")) : (0);
    (instruction.code == 5) ? (printf("SUB\n")) : (0);
    (instruction.code == 6) ? (printf("AND\n")) : (0);
    (instruction.code == 7) ? (printf("OR\n")) : (0);
    (instruction.code == 8) ? (printf("XOR\n")) : (0);
    (instruction.code == 9) ? (printf("ZJMP\n")) : (0);
    (instruction.code == 10) ? (printf("LDI\n")) : (0);
    (instruction.code == 11) ? (printf("STI\n")) : (0);
    (instruction.code == 12) ? (printf("FORK\n")) : (0);
    (instruction.code == 13) ? (printf("LDD\n")) : (0);
    (instruction.code == 14) ? (printf("LLDI\n")) : (0);
    (instruction.code == 15) ? (printf("LFORK\n")) : (0);
    (instruction.code == 16) ? (printf("AFF\n")) : (0);
    printf("[1] = %d [2] = %d [3] = %d [4] = %d\n\n",
    	   instruction.params[0],
    	   instruction.params[1],
    	   instruction.params[2],
    	   instruction.params[3]);

    i += 1;
  }
  champions->pc = 395;
  return (0);
}
