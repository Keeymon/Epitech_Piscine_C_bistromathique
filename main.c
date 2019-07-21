/*
** main.c for main in /home/picher_y/rendu/Piscine_C_bistromathique
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Fri Oct 23 13:44:22 2015 Yann Pichereau
** Last update Sun Nov  1 23:33:30 2015 Yann Pichereau
*/

#include <unistd.h>
#include <stdlib.h>
#include "bistromathique.h"
#include "my.h"

char	*get_expr(unsigned int size)
{
  char	*expr;

  if (size <= 0)
    {
      my_putstr_r(SYNTAX_ERROR_MSG);
      exit(0);
    }
  expr = malloc(sizeof(char) * (size + 1));
  if (expr == 0)
    {
      my_putstr_r(ERROR_MSG);
      exit(0);
    }
  if (read(0, expr, size) != size)
    {
      my_putstr_r(ERROR_MSG);
      exit(0);
    }
  expr[size] = 0;
  return (expr);
}

int		main(int ac, char **av)
{
  t_number	*list;
  t_number	*npi;
  unsigned int	size;
  char		*expr;

  if (ac == 4)
    {
      size = my_getnbr(av[3]);
      expr = get_expr(size);
      parse_arg(av, expr);
      expr = check_expr(expr, av[1], av[2]);
      list = create_linked_list(expr, av[2], av[1]);
      npi = NULL;
      eval_expr(&list, av[2], av[1], &npi);
      my_show_list(npi);
      free_struct(&npi);
    }
  else
    {
      my_putstr_r("Usage : ");
      my_putstr_r(av[0]);
      my_putstr_r(" base ops\"()+-*/%\" exp_len\n");
      return (1);
    }
  return (0);
}
