/*
** get_instruction.c for Corewar in /Corewar/VM/exec_instructions
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Mar 25 15:28:46 2014 chapui_s
** Last update Thu Mar 27 22:17:56 2014 chapui_s
*/

#include "../machine.h"
#include "../../op/op.h"

static int	to_negativ(int nb, int nb_octet)
{
  int		i;
  int		tmp;
  int		res;

  res = 0;
  i = 0b1000000000000000;
  if (nb_octet == 2 && (nb & 0b100000000000000) != 0)
  {
    while (i)
    {
      tmp = nb & i;
      if (tmp == 0)
	res += i;
      i = i >> 1;
    }
    res += 1;
    res = -res;
    nb = res;
  }
  return (nb);
}

static int	read_n_bytes(t_corewar *core, int index, int nb)
{
  int		ret;
  int		i;

  ret = 0;
  i = 0;
  while (i < nb)
  {
    ret = ret << 8;
    ret += core->arena[(index + i) % MEM_SIZE];
    ++i;
  }
  if (nb == 2)
    ret = to_negativ(ret, 2);
  return ((nb == 1 && (ret > 16 || ret < 1)) ? (16) : (ret));
}

void		putbin(unsigned int nb)
{
  if (nb >= 2)
    putbin(nb / 2);
  my_putchar((nb % 2) + '0');
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
  /* putbin(champion->pc); */
  my_putchar('\n');
  while ((tmp_type & 0b11000000))
  {
    printf("decal = %d\n", decal - champion->pc);
    if (tmp_type >> 6 == 1)
    {
      instruction->params[i] = read_n_bytes(core, decal, 1);
      decal += 1;
    }
    else if (tmp_type >> 6 == 0b10)
    {
      if (instruction->code != LDI && instruction->code != STI
	  && instruction->code != LLDI)
      {
	instruction->params[i] = read_n_bytes(core, decal, 4);
	decal += 4;
      }
      else
      {
	if (decal - champion->pc == 3 || decal - champion->pc == 5)
	{
	  instruction->params[i] = read_n_bytes(core, decal, 2);
	  //instruction->params[i] = to_negativ(instruction->params[i], 2);
	  decal += 2;
	}
	else
	{
	  instruction->params[i] = read_n_bytes(core, decal, 4);
	  decal += 4;
	}
      }
    }
    else
    {
      instruction->params[i] = read_n_bytes(core, decal, 2);
      decal += 2;
    }
    tmp_type = tmp_type << 2;
    ++i;
  }
    printf("decal = %d\n", decal - champion->pc);
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
      {
	instruction->params[0] = read_n_bytes(core, champions->pc + 1, 2);
	//instruction->params[0] = to_negativ(instruction->params[0], 2);
      }
    }
}

void		get_instruction(t_corewar *core,
				t_champions *champions,
				t_instruction *instruction)
{
  champions->pc += 159;
  instruction->code = core->arena[champions->pc];
  printf("code = %x\n", core->arena[champions->pc]);
  instruction->params[0] = 0;
  instruction->params[1] = 0;
  instruction->params[2] = 0;
  instruction->params[3] = 0;
  get_type_and_param(core, champions, instruction);
  printf("params[0] = %d\n", instruction->params[0]);
  printf("params[1] = %d\n", instruction->params[1]);
  printf("params[2] = %d\n", instruction->params[2]);
  printf("params[3] = %d\n", instruction->params[3]);
  /* if (instruction->code <= 16 && instruction->code >= 1) */
  /*   ; /\*appel de la bonne fonction *\/ */
}
