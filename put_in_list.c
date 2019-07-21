/*
** put_in_list.c for put_in_list in /home/picher_y/rendu/Piscine_C_bistromathique
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Wed Oct 28 19:06:39 2015 Yann Pichereau
** Last update Sun Nov  1 20:23:05 2015 Yann Pichereau
*/

#include <stdlib.h>
#include "my.h"
#include "bistromathique.h"

int	put_op(t_number **list, char *expr,
		       char *op, unsigned int i)
{
  char	*ope;

  if ((ope = malloc(sizeof(char) * 2)) == NULL)
    create_error(expr, list);
  ope[1] = '\0';
  if (expr[i] == op[2] || expr[i] == op[3])
    {
      ope[0] = op[2];
      i = put_op_bis(i, expr, op, ope);
    }
  else if (is_op(expr[i + 1], op) == 0 || expr[i + 1] == op[0] ||
	   expr[i + 1] == op[2] || expr[i + 1] == op[3])
    {
      ope[0] = expr[i];
      i++;
    }
  else
    return (0);
  init_number(&list, 0, ope, 0);
  return (i);
}

int	put_parenth(t_number **list, char *expr,
			    char *op, unsigned int i)
{
  char	*par;

  if ((par = malloc(sizeof(char) * 2)) == NULL)
    create_error(expr, list);
  par[1] = '\0';
  if (expr[i] == op[0])
    par[0] = op[0];
  else
    par[0] = op[1];
  init_number(&list, 0, par, 0);
  i++;
  return (i);
}

int		put_num(t_number **list, char *expr,
			char *op, unsigned int i)
{
  unsigned int	j;
  unsigned int	s_num;
  char		*num;

  j = i;
  s_num = 0;
  while (is_op(expr[i], op) == 0 && expr[i] != '\0')
    i++;
  if ((num = malloc(sizeof(char) * (i - j + 1))) == NULL)
    create_error(expr, list);
  num[i - j] = '\0';
  while (j < i)
    {
      num[s_num] = expr[j];
      j++;
      s_num++;
    }
  init_number(&list, 1, num, 1);
  return (i);
}

int	check_put_unaire(t_number **list, char *expr,
			   char *op, unsigned int i)
{
  if (expr[i] == op[0])
    i = put_parenth(list, expr, op, i);
  else
    i = put_num(list, expr, op, i);
  return (i);
}

int	put_unaire(t_number **list, char *expr,
		       char *op, unsigned int i)
{
  char	*num;
  int	sign;

  sign = 1;
  while (is_op(expr[i], op) == 1 && expr[i] != op[0] && expr[i] != '\0')
    {
      if (expr[i] != op[2] && expr[i] != op[3])
	return (0);
      else if (expr[i] == op[3])
	sign = sign * -1;
      i++;
    }
  if ((num = malloc(sizeof(char) * 2)) == NULL)
    create_error(expr, list);
  num[1] = '\0';
  if (expr[i] != op[0])
    i = check_put_unaire(list, expr, op, i);
  if (is_op(expr[i - 1], op) == 0)
    add_unaire(list, op);
  init_number(&list, 1, my_strdup("1"), sign);
  if (is_op(expr[i - 1], op) == 1)
    add_unaire(list, op);
  if (expr[i] == op[0])
    i = check_put_unaire(list, expr, op, i);
  return (i);
}
