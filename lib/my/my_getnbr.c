/*
** my_getnbr.c for my_getnbr in /home/picher_y/rendu/Lib/Function
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Tue Oct  6 16:47:25 2015 Yann Pichereau
** Last update Fri Oct 16 20:13:21 2015 Yann Pichereau
*/

#include "my.h"

int	border(char *str, int op, int i)
{
  char	*maxint;

  if (i > 9)
    return (0);
  maxint = (op > 0 ? "2147483647" : "2147483648");
  if (my_strcmp(str, maxint) > 0)
    return (0);
  else
    return (1);
}

int	my_getnbr(char *str)
{
  int	i;
  int	op;
  int	nb;

  op = 1;
  nb = 0;
  i = 0;
  while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
    {
      if (str[i] == '-')
	op = op * -1;
      i = i + 1;
    }
  str = str + i;
  i = 0;
  while (str[i] >= '0' && str[i] <= '9')
    {
      nb = nb + (str[i] - 48);
      if (str[i + 1] >= '0' && str[i + 1] <= '9')
	nb = nb * 10;
      if (i >= 9 && border(str, op, i) == 0)
	return (0);
      i = i + 1;
    }
  return (nb * op);
}
