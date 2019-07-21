/*
** put_error.c for put_error in /home/picher_y/rendu/Piscine_C_bistromathique
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Sat Oct 31 23:04:13 2015 Yann Pichereau
** Last update Sun Nov  1 22:21:41 2015 Yann Pichereau
*/

#include <stdlib.h>
#include "bistromathique.h"
#include "my.h"

void		error_calc(t_number **npi)
{
  t_number	*tmp;

  while (*npi != NULL)
    {
      tmp = (*npi)->next;
      free_struct(npi);
      *npi = tmp;
    }
  my_putstr_r(ERROR_MSG);
  exit(0);
}

void		create_error(char *expr, t_number **list)
{
  t_number	*tmp;

  free(expr);
  while (*list != NULL)
    {
      tmp = (*list)->next;
      free_struct(list);
      *list = tmp;
    }
  my_putstr_r(ERROR_MSG);
  exit(0);
}

void	error(char *expr)
{
  free(expr);
  my_putstr_r(ERROR_MSG);
  exit(0);
}

void		error_parse_free(char *expr, t_number **list)
{
  t_number	*tmp;

  free(expr);
  while (*list != NULL)
    {
      tmp = (*list)->next;
      free_struct(list);
      *list = tmp;
    }
  my_putstr_r(SYNTAX_ERROR_MSG);
  exit(0);
}

void	error_parse(char *expr)
{
  free(expr);
  my_putstr_r(SYNTAX_ERROR_MSG);
  exit(0);
}
