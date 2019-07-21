/*
** my_mod.c for bistromathique in /home/semana_r/rendu/BISTROMATHIQUE/div_inf
** 
** Made by romain semanaz
** Login   <semana_r@epitech.net>
** 
** Started on  Sun Nov  1 22:42:12 2015 romain semanaz
** Last update Mon Nov  2 19:05:42 2015 Yann Pichereau
*/

#include <stdlib.h>
#include "bistromathique.h"
#include "my.h"

char	*my_mod(char *nb1, char *nb2)
{
  char	*result;
  char	*div_free;
  char	*mult_free;

  if (*nb1 == '0')
    return (my_strdup("0"));
  else if (my_strcmp_bistro(nb1, nb2) < 0)
    return (my_strdup(nb1));
  else if (*nb2 == '0')
    my_error_mal();
  else
    {
      div_free = my_div_check(nb1, nb2);
      mult_free = my_mult(div_free, nb2);
      free(div_free);
      result = my_sub(nb1, mult_free);
      free(mult_free);
    }
  return (result);
}
