/*
** is_good_register.c for Corewar in /home/chapui_s/travaux/Corewar/VM/exec_instructions
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Fri Mar 28 18:54:18 2014 chapui_s
** Last update Fri Mar 28 18:55:15 2014 chapui_s
*/

int		is_good_register(int nb)
{
  return ((nb < 17 && nb > 0) ? (1) : (0));
}
