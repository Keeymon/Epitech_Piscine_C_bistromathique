/*
** my_put_nbr.c for my_put_nbr in /home/picher_y/rendu/Lib/Function
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Tue Oct  6 15:52:32 2015 Yann Pichereau
** Last update Mon Oct 12 14:58:16 2015 Yann Pichereau
*/

#include "my.h"

int	put_nbr(int nb, int nega)
{
  int	nb_tmp;
  int	div;

  div = 1;
  nb_tmp = nb;
  while (nb_tmp > 9)
    {
      nb_tmp = nb_tmp / 10;
      div = div * 10;
    }
  while (div >= 1)
    {
      if (div == 1 && nega == 1)
	my_putchar(nb / div % 10 + '1');
      else
	my_putchar(nb / div % 10 + '0');
      div = div / 10;
    }
  return (0);
}

int	my_put_nbr(int nb)
{
  int	nega;

  nega = 0;
  if (nb < 0)
    {
      if (nb == -2147483648)
	{
	  nb = nb + 1;
	  nega = 1;
	}
      my_putchar('-');
      nb = nb * -1;
    }
  put_nbr(nb, nega);
  return (0);
}
