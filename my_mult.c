/*
** my_mul.c for bistromathique in /home/semana_r/rendu/Piscine_C_bistromathique/sub_inf
** 
** Made by romain semanaz
** Login   <semana_r@epitech.net>
** 
** Started on  Thu Oct 29 03:14:35 2015 romain semanaz
** Last update Sun Nov  1 22:51:34 2015 Yann Pichereau
*/

#include <stdlib.h>
#include "bistromathique.h"
#include "my.h"

int		init_result_mult(t_operation *op)
{
  int		l_alloc;
  char		*ptr;

  l_alloc = (op->nb1.end - op->nb1.str + 1);
  l_alloc = l_alloc + (op->nb2.end - op->nb2.str + 1) + 1;
  op->result.str = malloc(sizeof(char) * l_alloc);
  if (op->result.str == NULL)
    my_error_mal();
  ptr = op->result.str;
  op->result.end = ptr + l_alloc - 2;
  while (ptr <= (op->result.end + 1))
    {
      *ptr = '\0';
      ptr += 1;
    }
  return (0);
}

void		mul_nb(t_operation *op)
{
  int		remain;
  int		tmp;
  char		dig;
  char		*ptr;
  char		*res;

  while (op->nb2.end >= op->nb2.str)
    {
      dig = *(op->nb2.end);
      ptr = op->nb1.end;
      res = op->result.str;
      remain = 0;
      while (ptr >= op->nb1.str)
	{
	  tmp = *res + (dig * (*ptr)) + remain;
	  *res = tmp % 10;
	  remain = tmp / 10;
	  res++;
	  ptr--;
	}
      if (remain != 0)
	*res = ((*res + remain) % 10);
      op->result.str++;
      op->nb2.end--;
    }
}

char 		*my_mult(char *nb1, char *nb2)
{
  t_operation	op;
  char		*ptr;
  char		*end;

  init_nb(&op.nb1, nb1);
  init_nb(&op.nb2, nb2);
  reorder_nb(&op);
  init_result_mult(&op);
  ptr = op.result.str;
  end = op.result.end;
  mul_nb(&op);
  while (end >= ptr)
    {
      *end += '0';
      end--;
    }
  while ((op.result.end >= ptr) && *(op.result.end) == '0')
    {
      *(op.result.end) = '\0';
      op.result.end--;
    }
  return (my_revstr(ptr));
}
