/*
** arguments.c for Corewar in /home/chapui_s/travaux/Corewar/VM
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Thu Mar 20 16:29:06 2014 chapui_s
** Last update Thu Mar 20 20:39:57 2014 chapui_s
*/

#include "machine.h"

int		is_error_in_args(int argc, char **argv)
{
  int		i;

  i = 1;
  if (argc < 2)
    return (-1);
  while (i < argc)
  {
    if (is_options(argv[i]))
    {
      if ((is_numbers(argv[i + 1])) == -1)
	return (-1);
      i += 2;
    }
    else
    {
      if (is_file_dot_cor(argv[i]) == -1)
	return (-1);
      i += 1;
    }
  }
  if (is_one_file_cor(argc, argv) == -1)
    return (-1);
  return (0);
}

int			save_champion(int i, char **argv, t_args *arguments)
{
  int			cur;
  unsigned int		prog_number;
  unsigned int		load_address;

  cur = i;
  i -= 1;
  prog_number = 0;
  load_address = 0;
  while (i > 0 && is_file_dot_cor(argv[i]) == -1)
  {
    if (!(my_strcmp(argv[i], "-n")))
      prog_number = my_unsigned_atoi(argv[i + 1]);
    if (!(my_strcmp(argv[i], "-a")))
      load_address = my_unsigned_atoi(argv[i + 1]);
    i -= 1;
  }
  if ((push_champion(&(arguments->champions),
		     argv[cur],
		     prog_number,
		     load_address)) == -1)
    return (-1);
  return (0);
}

void		save_args(int argc, char **argv, t_args *arguments)
{
  int		i;
  unsigned int	nb_cor;

  i = 1;
  nb_cor = 0;
  while (i < argc)
  {
    if (is_file_dot_cor(argv[i]) == 1 && ++nb_cor)
      save_champion(i, argv, arguments);
    i += 1;
  }
  arguments->nb_champions = nb_cor;
}

int		get_args(int argc, char **argv, t_args *arguments)
{
  (void)arguments;
  if (is_error_in_args(argc, argv) == -1)
    return (usage());
  save_args(argc, argv, arguments);
  if ((attribute_prog_number(arguments->champions,
			     arguments->nb_champions)) == -1)
    return (-1);
  return (0);
}
