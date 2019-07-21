/*
** my_subtract.c for bistromathique in /home/semana_r/rendu/Piscine_C_infinadd
** 
** Made by romain semanaz
** Login   <semana_r@epitech.net>
** 
** Started on  Wed Oct 28 18:04:32 2015 romain semanaz
** Last update Sun Nov  1 22:50:56 2015 Yann Pichereau
*/

#include <stdlib.h>
#include "my.h"
#include "bistromathique.h"

void		reorder_nb_sub(t_operation *sub)
{
  t_number	tmp;

  if ((sub->nb1.end - sub->nb1.str) < (sub->nb2.end - sub->nb2.str))
    {
      tmp = sub->nb1;
      sub->nb1 = sub->nb2;
      sub->nb2 = tmp;
    }
  else if (((sub->nb1.end - sub->nb1.str) == (sub->nb2.end - sub->nb2.str)) &&
	   my_strcmp(sub->nb1.str, sub->nb2.str) < 0)
    {
      tmp = sub->nb1;
      sub->nb1 = sub->nb2;
      sub->nb2 = tmp;
    }
}

int		init_result_sub(t_operation *sub)
{
  unsigned int	len_alloc;
  char		*ptr;

  len_alloc = ((sub->nb1.end) - (sub->nb1.str) + 1 + 1);
  sub->result.str = malloc(sizeof(char) * len_alloc);
  if (sub->result.str == NULL)
    my_error_mal();
  sub->result.end = sub->result.str + len_alloc - 2;
  ptr = sub->result.str;
  while (ptr <= (sub->result.end + 1))
    {
      *ptr = 0;
      ptr += 1;
    }
  return (0);
}

void		process_sub_nb1(t_operation *sub, int ret, char *ptr)
{
  int		sum;

  while (sub->nb1.end >= sub->nb1.str)
    {
      if (*(sub->nb1.end) < ret)
	{
	  sum = (*(sub->nb1.end) + 10 - ret);
	  *ptr = sum + '0';
	  ret = 1;
	}
      else
	{
	  sum = (*(sub->nb1.end) - ret);
	  *ptr = sum + '0';
	  ret = 0;
	}
      ptr++;
      sub->nb1.end--;
    }
}

void		process_sub_nb2(t_operation *sub)
{
  int		ret;
  int		sum;
  char		*ptr;

  ptr = sub->result.str;
  ret = 0;
  while (sub->nb2.end >= sub->nb2.str)
    {
      if (*(sub->nb1.end) < (*(sub->nb2.end) + ret))
	{
	  sum = ((*(sub->nb1.end) + 10) - (*(sub->nb2.end) + ret));
	  *ptr = sum + '0';
	  ret = 1;
	}
      else
	{
	  sum = (*(sub->nb1.end) - (*(sub->nb2.end) + ret));
	  *ptr = sum + '0';
	  ret = 0;
	}
      ptr++;
      sub->nb1.end--;
      sub->nb2.end--;
    }
  process_sub_nb1(sub, ret, ptr);
}

char		*my_sub(char *nb1, char *nb2)
{
  t_operation	sub;
  char		*end;

  init_nb(&sub.nb1, nb1);
  init_nb(&sub.nb2, nb2);
  reorder_nb_sub(&sub);
  init_result_sub(&sub);
  process_sub_nb2(&sub);
  end = sub.result.end;
  while ((end > sub.result.str) && (*end == '0'))
    {
      *end = '\0';
      end -= 1;
    }
  return (my_revstr(sub.result.str));
}
