/*
** my_show_list.c for my_show_list in /home/picher_y/rendu/Piscine_C_bistromathique
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Sun Nov  1 19:40:58 2015 Yann Pichereau
** Last update Mon Nov  2 17:15:59 2015 Yann Pichereau
*/

#include <stdlib.h>
#include "my.h"
#include "bistromathique.h"

void		my_show_list(t_number *list)
{
  t_number	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if (tmp->is_num == 1 && tmp->sign == -1 && tmp->str[0] != '0')
	my_putchar('-');
      my_putstr(tmp->str);
      tmp = tmp->next;
    }
}

int		parse_zero(t_number *elem, char *base)
{
  unsigned int	i;
  unsigned int	j;
  unsigned int	size;
  char		*str;

  i = 0;
  j = 0;
  size = 1;
  while (elem->str[i] == base[0] && elem->str[i + 1] != '\0')
    i++;
  size = size + i;
  if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
    return (1);
  str[size] = '\0';
  while (elem->str[i] != '\0')
    {
      str[j] = elem->str[i];
      j++;
      i++;
    }
  free(elem->str);
  elem->str = str;
  return (0);
}

void	prior(t_number *elem, char *op)
{
  if (elem->str[0] == op[0])
    elem->prior = 4;
  else if (elem->str[0] == op[4] ||
	   elem->str[0] == op[5] ||
	   elem->str[0] == op[6])
    elem->prior = 3;
  else if (elem->str[0] == op[2] || elem->str[0] == op[3])
    elem->prior = 2;
}

int	my_rev_list(t_number **begin, char *base, char *op)
{
  t_number *tmp;
  t_number *rev;
  t_number *stck;

  tmp = *begin;
  rev = NULL;
  while (tmp != NULL)
    {
      stck = tmp->next;
      tmp->next = rev;
      rev = tmp;
      if (rev->str[0] == base[0] && rev->length != 1)
	parse_zero(rev, base);
      if (rev->is_num == 0)
	prior(rev, op);
      tmp = stck;
    }
  *begin = rev;
  return (0);
}

void	my_error_mal()
{
  my_putstr_r(ERROR_MSG);
  exit(0);
}
