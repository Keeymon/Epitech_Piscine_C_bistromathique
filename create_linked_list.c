/*
** create_linked_list.c for create_linked_list in /home/picher_y/rendu/Piscine_C_bistromathique
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Wed Oct 28 11:51:44 2015 Yann Pichereau
** Last update Sun Nov  1 23:40:13 2015 Yann Pichereau
*/

#include <stdlib.h>
#include "my.h"
#include "bistromathique.h"

int		init_number(t_number ***list, int is_num,
			    char *str, int sign)
{
  t_number	*elem;

  if ((elem= malloc(sizeof(*elem))) == NULL)
    return (0);
  elem->is_num = is_num;
  if ( elem->is_num == 1)
    {
      elem->sign = sign;
      elem->length = my_strlen(str);
      elem->index = elem->length;
    }
  elem->str = str;
  elem->next = **list;
  **list = elem;
  return (1);
}

int	is_op(char c, char *op)
{
  while (*op != '\0')
    {
      if (c == *op)
	return (1);
      op++;
    }
  return (0);
}

int	add_unaire(t_number **list, char *op)
{
  char	*multi;

  if ((multi = malloc(sizeof(char) * 2)) == NULL)
    return (0);
  multi[1] = '\0';
  multi[0] = op[4];
  init_number(&list, 0, multi, 0);
  return (0);
}

int	redirection_put(unsigned int i, char *expr, char *op, t_number **list)
{
  if (expr[i] == op[0] || expr[i] == op[1])
    i = put_parenth(list, expr, op, i);
  else if (is_op(expr[i], op) == 0)
    i = put_num(list, expr, op, i);
  else if ((i == 0 && (expr[i] == op[2] || expr[i] == op[3])) ||
	   (i > 0 && (expr[i - 1] == op[0] || expr[i - 1] == op[4] ||
		      expr[i - 1] == op[5] || expr[i - 1] == op[6])
	    && (expr[i] == op[2] || expr[i] == op[3])))
    i = put_unaire(list, expr, op, i);
  else if (i > 0 && is_op(expr[i], op) == 1 &&
	   expr[i - 1] != op[0] && expr[i + 1] != '\0')
    i = put_op(list, expr, op, i);
  else
    i = 0;
  if (i == 0)
    error_parse_free(expr, list);
  return (i);
}

t_number	*create_linked_list(char *expr, char *op, char *base)
{
  t_number	*list;
  unsigned int	i;

  i = 0;
  list = NULL;
  while (expr[i] != '\0')
    i = redirection_put(i, expr, op, &list);
  free(expr);
  my_rev_list(&list, base, op);
  return (list);
}
