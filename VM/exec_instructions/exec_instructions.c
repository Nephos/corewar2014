/*
** exec_instructions.c for Corewar in /home/chapui_s/travaux/Corewar/VM
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Mar 25 15:13:41 2014 chapui_s
** Last update Thu Apr  3 01:08:35 2014 chapui_s
*/

#include "../../op/op.h"
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
  {12, my_fork},
};

static int	exec_function(t_corewar *core,
			      t_champions *champions,
			      t_instruction *instruction)
{
  if (instruction->code < 13 && instruction->code > 0)
  {
    /* printf("\nOK\n"); */
    if ((tab_func[instruction->code - 1].function(core,
						  champions,
						  instruction)) == -1)
      return (-1);
  }
  /* else */
  /*   printf("\nNO FOUND\n"); */
  return (0);
}

void		get_cycle_to_wait(t_corewar *core, t_champions *champions)
{
  int		index;

  index = champions->pc % MEM_SIZE;
  if (core->arena[index] >= 1 && core->arena[index] <= 16)
  {
    champions->cycle_to_wait = op_tab[core->arena[index] - 1].nbr_cycles;
  }
  else
    champions->cycle_to_wait = 0;
}

int		exec_instructions(t_corewar *core, t_champions *champions)
{
  t_instruction	instruction;
  t_champions	*tmp;

  tmp = champions;
  while (tmp)
  {
    if (tmp->cycle_to_wait <= 1)
    {
      get_instruction(core, tmp, &instruction);
      if ((exec_function(core, tmp, &instruction)) == -1)
	return (-1);
      get_cycle_to_wait(core, tmp);
    }
    else
      tmp->cycle_to_wait -= 1;
    tmp->last_live += 1;
    tmp = tmp->next;
  }
  return (0);
}

int		search_who_still_alive(t_corewar *core)
{
  t_champions	*tmp;
  /* char		*name_tmp; */
  int		id_champion;

  /* name_tmp = NULL; */
  tmp = core->champions;
  id_champion = 0;
  while (tmp)
  {
    if (id_champion != 0 && id_champion != tmp->color_gui)
      return (1);
    else
      id_champion = tmp->color_gui;
    /* if (name_tmp != NULL && my_strcmp(tmp->name, name_tmp)) */
    /* 	return (1); */
    /* else */
    /* 	name_tmp = tmp->name; */
    tmp = tmp->next;
  }
  return (0);
}

int		qget_size_list(t_corewar *core)
{
  t_champions	*champions;
  int		size;

  size = 0;
  champions = core->champions;
  while (champions)
  {
    size += 1;
    champions = champions->next;
  }
  return (size);
}

int		check_live_process(t_corewar *core,
				   t_champions *champions,
				   unsigned int cycle_to_die_cur)
{
  t_champions	*tmp;
  t_champions	*tmp_last;
  t_champions	*tmp_to_rm;
  int		nbr_prog_live;

  nbr_prog_live = 0;
  tmp = champions;
  tmp_last = NULL;
  while (tmp)
  {
    if (tmp->last_live >= cycle_to_die_cur)
    {
      core->nb_champions -= 1;
      if (tmp_last)
	tmp_last->next = tmp->next;
      else
	core->champions = tmp->next;
      if (tmp->next == NULL)
	core->last_champions = tmp_last;
      tmp_to_rm = tmp;
      tmp = tmp->next;
      tmp_to_rm->is_dead = 1;
      free(tmp_to_rm->reg);
      free(tmp_to_rm);
    }
    tmp_last = tmp;
    if (tmp)
      tmp = tmp->next;
  }
  tmp = champions;
  if ((search_who_still_alive(core)) == 0)
    return (1);
  return (0);
}

int		manage_instructions(t_corewar *core, t_champions *champions)
{
  static unsigned int		i;
  static unsigned int	cycle_to_die_cur;

  /* unsigned int	j; */
  /* j = 0; */

  /* printf("cycle_to_die_cur = %d nbr_live_cur = %d\n", */
  /* 	 cycle_to_die_cur, core->nbr_live_cur); */
  if (i == 0)
    i = 1;
  if (cycle_to_die_cur == 0)
    cycle_to_die_cur = CYCLE_TO_DIE;
  /* while (j < 100000) */
  /* { */
  /*   printf("j = %u\n", j); */
    if (i == cycle_to_die_cur)
    {
      if ((check_live_process(core, core->champions, cycle_to_die_cur)) == 1)
      {
	printf("someone won !\n");
    	return (1);
      }
      //check_live des process
    	i = 1;
    }
    if (core->nbr_live_cur >= NBR_LIVE)
    {
      cycle_to_die_cur -= CYCLE_DELTA;
      core->nbr_live_cur = 0;
      i = 1;
    }
    exec_instructions(core, core->champions);
    i += 1;
  /*   j += 1; */
  /* } */
  return (0);
}

/* int		exec_instructions(t_corewar *core, t_champions *champions) */
/* { */
/*   t_instruction	instruction; */
/*   t_champions	*tmp; */
/*   int		i; */

/*   i = 0; */
/*   /\* while (i < 208) *\/ */
/*   while (i < 94) */
/*   { */
/*     printf("PC = %d\n", champions->pc); */
/*     tmp = champions; */
/*     while (tmp) */
/*     { */
/*       get_instruction(core, champions, &instruction); */
/*       exec_function(core, champions, &instruction); */
/*       tmp = tmp->next; */
/*     } */

/*     (instruction.code == 1) ? (printf("LIVE\n")) : (0); */
/*     (instruction.code == 2) ? (printf("LD\n")) : (0); */
/*     (instruction.code == 3) ? (printf("ST\n")) : (0); */
/*     (instruction.code == 4) ? (printf("ADD\n")) : (0); */
/*     (instruction.code == 5) ? (printf("SUB\n")) : (0); */
/*     (instruction.code == 6) ? (printf("AND\n")) : (0); */
/*     (instruction.code == 7) ? (printf("OR\n")) : (0); */
/*     (instruction.code == 8) ? (printf("XOR\n")) : (0); */
/*     (instruction.code == 9) ? (printf("ZJMP\n")) : (0); */
/*     (instruction.code == 10) ? (printf("LDI\n")) : (0); */
/*     (instruction.code == 11) ? (printf("STI\n")) : (0); */
/*     (instruction.code == 12) ? (printf("FORK\n")) : (0); */
/*     (instruction.code == 13) ? (printf("LDD\n")) : (0); */
/*     (instruction.code == 14) ? (printf("LLDI\n")) : (0); */
/*     (instruction.code == 15) ? (printf("LFORK\n")) : (0); */
/*     (instruction.code == 16) ? (printf("AFF\n")) : (0); */
/*     printf("cycle_to_wait = %d\n", champions->cycle_to_wait); */
/*     printf("[1] = %d [2] = %d [3] = %d [4] = %d\n\n", */
/*     	   instruction.params[0], */
/*     	   instruction.params[1], */
/*     	   instruction.params[2], */
/*     	   instruction.params[3]); */

/*     i += 1; */
/*   } */
/*   /\* champions->pc = 395; *\/ */
/*   return (0); */
/* } */
