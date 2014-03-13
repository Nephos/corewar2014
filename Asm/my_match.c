/*
** match.c for  in /home/poulet_a/rendu/Piscine-C-match-nmatch/match
** 
** Made by poulet_a
** Login   <poulet_a@epitech.net>
** 
** Started on  Fri Oct 25 09:19:32 2013 poulet_a
** Last update Sun Nov  3 18:53:29 2013 poulet_a
*/

int	my_match(char *s1, char *s2)
{
  if (*s1 == 0 && *s2 == 0)
    return (1);
  else if (*s2 == '*')
    {
      if (*s1 == 0)
	return (my_match((s1), (s2 + 1)));
      else
	return (my_match((s1 + 1), (s2)) || my_match((s1), (s2 + 1)));
    }
  else if (*s1 != *s2)
    return (0);
  else
    return (my_match(s1 + 1, s2 + 1));
}
