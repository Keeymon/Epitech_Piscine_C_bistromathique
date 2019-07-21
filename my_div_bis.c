/*
** my_div_bis.c for  in /home/picher_y/rendu/Piscine_C_bistromathique
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Sun Nov  1 22:35:52 2015 Yann Pichereau
** Last update Sun Nov  1 23:02:12 2015 Yann Pichereau
*/

#include <stdlib.h>
#include "bistromathique.h"
#include "my.h"

void	init_nb_div(t_number *nb, char *str)
{
  nb->str = str;
  nb->end = str + (my_strlen(str) - 1);
}

int	my_strcmp_bistro(char *s1, char *s2)
{
  int	i;

  if (my_strlen(s1) > my_strlen(s2))
    return (1);
  else if (my_strlen(s1) < my_strlen(s2))
    return (-1);
  else
    {
      i = 0;
      while (*(s1 + i) != '\0' && *(s2 + i) != '\0')
        {
          if (*(s1 + i) < *(s2 + i))
            return (-s2[i] + s1[i]);
          else if (*(s1 + i) > *(s2 + i))
            return (s1[i] - s2[i]);
          i = i + 1;
        }
      if (*(s1 + i) != '\0')
        return (s1[i]);
      else if (*(s2 + i) != '\0')
        return (-s2[i]);
      else
        return (0);
    }
}

int		init_result_div(t_operation *op)
{
  int		len_result;
  char		*ptr;

  len_result = op->nb1.end - op->nb1.str + 2;
  op->result.str = malloc(sizeof(char) * len_result);
  if (op->result.str == NULL)
    my_error_mal();
  op->result.end = op->result.str + len_result - 2;
  ptr = op->result.str;
  while (ptr < (op->result.end))
    {
      *ptr = '0';
      ptr += 1;
    }
  *ptr = '1';
  *(ptr + 1) = '\0';
  return (0);
}

void	set_result(t_operation *op)
{
  int	len;
  char	*ptr;
  int	idx;

  len = ((op->nb1.end - op->nb1.str + 1) - (op->nb2.end - op->nb2.str + 1));
  idx = 0;
  while ((op->nb2.str)[idx] != '\0' && (op->nb2.str[idx] <= op->nb1.str[idx]))
    idx += 1;
  if (op->nb2.str[idx] != '\0')
    len = len - 1;
  ptr = op->result.str;
  *ptr = '1';
  ptr += 1;
  while ((ptr - op->result.str) <= len)
    {
      *ptr = '0';
      ptr += 1;
    }
  *ptr = '\0';
}
