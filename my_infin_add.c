/*
** my_add.c for myadd in /home/semana_r/rendu/Piscine_C_infinadd
** 
** Made by romain semanaz
** Login   <semana_r@epitech.net>
** 
** Started on  Mon Oct 19 16:08:00 2015 romain semanaz
** Last update Sun Nov  1 22:51:15 2015 Yann Pichereau
*/

#include <stdlib.h>
#include "my.h"
#include "bistromathique.h"

void	init_nb(t_number *nb, char *str)
{
  nb->str = str;
  nb->end = str + (my_strlen(str) - 1);
  while (str <= nb->end)
    {
      *str = *str - '0';
      str++;
    }
}

void		reorder_nb(t_operation *add)
{
  t_number	tmp;

  if ((add->nb1.end - add->nb1.str) < (add->nb2.end - add->nb2.str))
    {
      tmp = add->nb1;
      add->nb1 = add->nb2;;
      add->nb2 = tmp;
    }
}

int		init_result_add(t_operation *add)
{
  unsigned int	len_alloc;
  char		*ptr;

  len_alloc = ((add->nb1.end) - (add->nb1.str) + 3);
  add->result.str = malloc(sizeof(char) * len_alloc);
  add->result.end = add->result.str + len_alloc - 2;
  if (add->result.str == NULL)
    my_error_mal();
  ptr = add->result.str;
  while (ptr <= (add->result.end + 1))
    {
      *ptr = 0;
      ptr += 1;
    }
  return (0);
}

void		process_add(t_operation *add)
{
  unsigned int	retenue;
  unsigned int	somme;
  char		*ptr;

  ptr = add->result.str;
  retenue = 0;
  while (add->nb2.end >= add->nb2.str)
    {
      somme = *(add->nb1.end) + *(add->nb2.end);
      *ptr = ((somme + retenue) % 10) + '0';
      retenue = (somme + retenue) / 10;
      ptr = ptr + 1;
      add->nb1.end = add->nb1.end - 1;
      add->nb2.end = add->nb2.end - 1;
    }
  while (add->nb1.end >= add->nb1.str)
    {
      somme = *(add->nb1.end);
      *ptr = ((somme + retenue) % 10) + '0';
      retenue = (somme + retenue) / 10;
      ptr = ptr + 1;
      add->nb1.end = add->nb1.end - 1;
    }
  *ptr = retenue + '0';
}

char		*my_add(char *nb1, char *nb2)
{
  t_operation	add;
  char		*end;

  init_nb(&add.nb1, nb1);
  init_nb(&add.nb2, nb2);
  reorder_nb(&add);
  init_result_add(&add);
  process_add(&add);
  end = add.result.end;
  while ((end > add.result.str) && (*end == '0'))
    {
      *end = '\0';
      end -= 1;
    }
  return (my_revstr(add.result.str));
}
