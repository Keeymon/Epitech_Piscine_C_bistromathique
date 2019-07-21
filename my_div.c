/*
** my_div.c for bistromathique in /home/semana_r/rendu/BISTROMATHIQUE/div_inf
** 
** Made by romain semanaz
** Login   <semana_r@epitech.net>
** 
** Started on  Sun Nov  1 05:25:40 2015 romain semanaz
** Last update Tue Nov  3 16:39:44 2015 Yann Pichereau
*/

#include <stdlib.h>
#include "bistromathique.h"
#include "my.h"

void	re_init_nb(t_number *nb)
{
  char	*ptr;

  ptr = nb->str;
  while (ptr <= nb->end)
    {
      *ptr += '0';
      ptr += 1;
    }
}

char		*process_div(t_operation *op)
{
  t_number	res;
  char		*result;
  char		*mult;
  int		idx;

  init_nb_div(&res, op->result.str);
  result = res.str;
  idx = 0;
  while (result[idx] != '\0')
    {
      mult = my_mult(res.str, op->nb2.str);
      re_init_nb(&(op->nb2));
      re_init_nb(&res);
      while (my_strcmp_bistro(mult, op->nb1.str) <= 0 && (result[idx] != '9'))
	{
	  result[idx] += 1;
	  mult = my_mult(res.str, op->nb2.str);
	  re_init_nb(&(op->nb2));
	  re_init_nb(&res);
	}
      if (my_strcmp_bistro(mult, op->nb1.str) > 0)
	result[idx] -= 1;
      idx += 1;
    }
  return (result);
}

char		*my_div(char *nb1, char *nb2)
{
  t_operation	op;
  char		*result;

  init_nb_div(&op.nb1, nb1);
  init_nb_div(&op.nb2, nb2);
  init_result_div(&op);
  set_result(&op);
  result =  process_div(&op);
  return (result);
}

char	*my_div_check(char *nb1, char *nb2)
{
  char	*result;

  if (*nb2 == '0')
    my_error_mal();
  else if (my_strlen(nb2) == 1 && *nb2 == '1')
    return (nb1);
  else if (my_strcmp_bistro(nb1, nb2) < 0)
    {
      result = my_strdup("0");
      return (result);
    }
  else if ((my_strlen(nb1) == my_strlen(nb2)) && my_strcmp(nb1, nb2) == 0)
    {
      result = my_strdup("1");
      return (result);
    }
  else
    result = my_div(nb1, nb2);
  return (result);
}
