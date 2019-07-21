/*
** base_op_in_str.c for base_op_in_str in /home/picher_y/rendu/Piscine_C_bistromathique
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Fri Oct 23 16:45:56 2015 Yann Pichereau
** Last update Sun Nov  1 19:53:58 2015 Yann Pichereau
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "bistromathique.h"

/*
** Cette fonction vérifie que tout les caractére de la chaine de calcul
** ne sont pas inconnu. Si un opérateur est trouvé on le remplace par
** une valeur plus compréhensible
*/
int		baop_in_expr(char c, char *baop)
{
  unsigned int	i;

  i = 0;
  while (baop[i] !='\0')
    {
      if (c == baop[i])
	return (1);
      i++;
    }
  return (0);
}

/*
** Cette fonction concatene les opérateurs et la base pour
** vérifier qu'il n'existe pas de caractère inconnu.
*/
char		*concat_base_op(char *base, char *op)
{
  unsigned int	size;
  char		*baop;

  size = my_strlen(base) + my_strlen(op);
  if ((baop = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  baop[0] = '\0';
  baop = my_strcat(my_strcat(baop, op), base);
  return (baop);
}

/*
** Cette fonction permet de déterminer les éventuelles erreurs de
** syntax au niveau des parentheses.
*/
char		*check_expr(char *expr, char *base, char *op)
{
  unsigned int	i;
  unsigned int	open;
  unsigned int	end;
  char		*baop;

  baop = concat_base_op(base, op);
  i = 0;
  open = 0;
  end = 0;
  while (expr[i] != '\0')
    {
      if (baop == NULL || baop_in_expr(expr[i], baop) == 0)
	error_parse(expr);
      if (expr[i] == op[0])
	open++;
      if (expr[i] == op[1])
	end++;
      if (open < end)
	error_parse(expr);
      i++;
    }
  if (open != end)
    error_parse(expr);
  free(baop);
  return (expr);
}
