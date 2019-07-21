/*
** my_putnbr_base.c for my_putnbr_base in /home/picher_y/rendu/PJ06/ex_16
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Tue Oct  6 13:07:19 2015 Yann Pichereau
** Last update Fri Oct 16 20:45:51 2015 Yann Pichereau
*/

#include "my.h"

int	my_putnbr_base(int nbr, char *base)
{
  int	n_base;
  int	div;
  int	result;

  div = 1;
  n_base = my_strlen(base);
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = nbr * -1;
    }
  while (nbr / div >= n_base)
    div = div * n_base;
  while (div > 0)
    {
      result = (nbr / div) % n_base;
      my_putchar(base[result]);
      div = div / n_base;
    }
  return (nbr);
}
