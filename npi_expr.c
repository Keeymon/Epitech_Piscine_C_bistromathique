/*
** eval_expr.c for bistromathique in /home/semana_r/rendu/Piscine_C_bistromathique/evalexpr
** 
** Made by romain semanaz
** Login   <semana_r@epitech.net>
** 
** Started on  Wed Oct 28 10:09:47 2015 romain semanaz
** Last update Mon Nov  2 19:21:18 2015 Yann Pichereau
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "bistromathique.h"

/*
** Ajoute 1 élément dans la pile
*/
void	put_in_stack(t_number **stack, t_number **list)
{
  (*list)->next = *stack;
  *stack = *list;
}

/*
** Enleve 1 élément de la pile
*/
void		put_off_stack(t_number **stack, char *op, t_number **npi, char *base)
{
  if ((*stack)->str[0] != op[0])
    init_npi(npi, stack);
  if (*npi != NULL && (*npi)->is_num == 0)
    check_operation(npi, op, base);
}

void	pop_off_stack(t_number **stack, t_number **list, char *op, t_number **npi)
{
  t_number	*tmp;
  char		*base;

  base = "0123456789";
  if ((*list)->str[0] == op[1])
    {
      while ((*stack)->str[0] != op[0])
	{
	  tmp = (*stack)->next;
	  put_off_stack(stack, op, npi, base);
	  *stack = tmp;
	}
      tmp = (*stack)->next;
      free_struct(stack);
      *stack = tmp;
    }
  else
    {
      while (*stack != NULL && ((*stack)->prior >= (*list)->prior) &&
	     (*stack)->str[0] != op[0])
	{
	  tmp = (*stack)->next;
	  put_off_stack(stack, op, npi, base);
	  *stack = tmp;
	}
      put_in_stack(stack, list);
    }
}

void	init_npi(t_number **npi, t_number **elem)
{
  (*elem)->next = *npi;
  *npi = *elem;
}

void		eval_expr(t_number **list, char *op, char *base, t_number **npi)
{
  t_number	*stack;
  t_number	*tmp;

  stack = NULL;
  while (*list != NULL)
    {
      tmp = (*list)->next;
      if ((*list)->is_num == 0)
	pop_off_stack(&stack, list, op, npi);
      else
	init_npi(npi, list);
      if ((*list)->str[0] == op[1])
	free_struct(list);
      *list = tmp;
    }
  while (stack != NULL)
    {
      tmp = stack->next;
      put_off_stack(&stack, op, npi, base);
      stack = tmp;
    }
}
