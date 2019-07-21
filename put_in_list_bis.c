/*
** put_in_list_bis.c for put_in_list_bis in /home/picher_y/rendu/Piscine_C_bistromathique
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Sun Nov  1 09:36:51 2015 Yann Pichereau
** Last update Sun Nov  1 19:37:36 2015 Yann Pichereau
*/

#include "bistromathique.h"

int	put_op_bis(unsigned int i, char *expr, char *op, char *ope)
{
  while (is_op(expr[i], op) == 1 && expr[i] != op[0] && expr[i] != '\0')
    {
      if (expr[i] != op[2] && expr[i] != op[3])
	return (0);
      else if (expr[i] == op[3])
	ope[0] = (ope[0] == op[3] ? op[2] : op[3]);
      i++;
    }
  return (i);
}
