/*
** check_operation.c for check_operation in /home/picher_y/rendu/Piscine_C_bistromathique
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Sun Nov  1 00:31:47 2015 Yann Pichereau
** Last update Mon Nov  2 19:16:02 2015 Yann Pichereau
*/

#include <stdlib.h>
#include "bistromathique.h"
#include "my.h"

char	*add_inf(t_number **n1, t_number **n2, int *sign, char *base)
{
  char	*result;

  if (*sign == 1)
    {
      result = my_add((*n1)->str, (*n2)->str);
      if ((*n1)->sign == -1)
	*sign = -1;
      else
	*sign = 1;
    }
  else
    {
      if ((my_strcmp_base((*n1)->str, (*n2)->str, base) == 1
	   && (*n2)->sign == -1) ||
	  (my_strcmp_base((*n1)->str, (*n2)->str, base) == -1
	   && (*n1)->sign == -1))
	*sign = 1;
      else
	*sign = -1;
      result = my_sub((*n1)->str, (*n2)->str);
    }
  return (result);
}

char	*sub_inf(t_number **n1, t_number **n2, int *sign, char *base)
{
  char	*result;

  if (*sign == 1)
    {
      if ((my_strcmp_base((*n1)->str, (*n2)->str, base) == 1
	   && (*n1)->sign == -1) ||
	  (my_strcmp_base((*n1)->str, (*n2)->str, base) == -1
	   && (*n1)->sign == 1))
	*sign = -1;
      else
	*sign = 1;
      result = my_sub((*n1)->str, (*n2)->str);
    }
  else
    {
      result = my_add((*n1)->str, (*n2)->str);
      if ((*n1)->sign == -1)
	*sign = -1;
      else
	*sign = 1;
    }
  return (result);
}

void		check_operation(t_number **npi, char *op, char *base)
{
  t_number 	*n1;
  t_number	*n2;
  int		sign;
  char		*result;

  n2 = (*npi)->next;
  n1 = (*npi)->next->next;
  sign = n1->sign * n2->sign;
  if ((*npi)->str[0] == op[2])
    result = add_inf(&n1, &n2, &sign, base);
  else if ((*npi)->str[0] == op[3])
    result = sub_inf(&n1, &n2, &sign, base);
  else if ((*npi)->str[0] == op[4])
    result = my_mult(n1->str, n2->str);
  else if ((*npi)->str[0] == op[5])
    result = my_div_check(n1->str, n2->str);
  else if ((*npi)->str[0] == op[6])
    result = my_mod(n1->str, n2->str);
  free_struct(npi);
  free_struct(&n2);
  *npi = n1->next;
  free_struct(&n1);
  init_number(&npi, 1, result, sign);
}
