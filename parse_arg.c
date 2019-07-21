/*
** parse_arg.c for parse_arg in /home/picher_y/rendu/Piscine_C_bistromathique
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Fri Oct 23 14:15:01 2015 Yann Pichereau
** Last update Sun Nov  1 19:35:52 2015 Yann Pichereau
*/

#include "bistromathique.h"
#include "my.h"

/*
** Cette fonction vérifie qu'un charactère n'est pas
** utilisé plusieurs fois dans une même base ou opérateur
*/
int		check_char(char *str)
{
  unsigned int	i;
  unsigned int	j;

  i = 0;
  while (str[i] != '\0')
    {
      j = 0;
      while (str[j] != '\0')
	{
	  if (i != j && str[i] == str[j])
	    return (0);
	  j++;
	}
      i++;
    }
  return (1);
}

/*
** Cette fonction vérifie que des caractéres ne sont pas
** utilisé à la fois dans une base et pour un opérateur
*/
int		diff_char(char *base, char *op)
{
  unsigned int	i;
  unsigned int	j;

  i = 0;
  while (base[i] != '\0')
    {
      j = 0;
      while (op[j] != '\0')
	{
	  if (base[i] == op[j])
	    return (0);
	  j++;
	}
      i++;
    }
  return (1);
}

int	check_base_op(char *base, char *op)
{
  if (check_char(base) == 0)
    return (0);
  if (check_char(op) == 0)
    return (0);
  if (diff_char(base, op) == 0)
    return (0);
  return (1);
}

int	parse_arg(char **av, char *expr)
{
  if (my_str_isnum(av[3]) == 0)
    error_parse(expr);
  if (my_strlen(av[2]) != 7)
    error_parse(expr);
  if (check_base_op(av[1], av[2]) == 0)
    error_parse(expr);
  return (0);
}
