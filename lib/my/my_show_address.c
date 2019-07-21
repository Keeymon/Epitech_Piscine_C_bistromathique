/*
** my_show_address.c for my_show_address in /home/picher_y/rendu/PJ06/ex_19
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Sun Oct 18 16:43:12 2015 Yann Pichereau
** Last update Sun Oct 18 19:12:13 2015 Yann Pichereau
*/

#include <unistd.h>

void	to_hexa(long nbr, int size, int div, char *hex)
{
  char	*base;
  int	result;

  base = "0123456789abcdef";
  while (div > 0)
    {
      result = (nbr / div) % 16;
      hex[8 - size - 1] = base[result];
      div = div / 16;
      size = size - 1;
    }
  write(1, hex, 8);
}

void	my_show_address(void *add)
{
  long	nbr;
  int	div;
  int	size;
  char	hex[8];

  div = 1;
  size = 0;
  nbr = (long)(add);
  while (size < 8)
    {
      hex[size] = '0';
      size = size + 1;
    }
  size = 0;
  while (nbr / div >= 16)
    {
      div = div * 16;
      size = size + 1;
    }
  to_hexa(nbr, size, div, hex);
}
