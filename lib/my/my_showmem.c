/*
** my_showmem.c for my_showmem in /home/picher_y/rendu/PJ06/ex_19
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Sat Oct 17 17:41:26 2015 Yann Pichereau
** Last update Sun Oct 18 19:14:28 2015 Yann Pichereau
*/

#include "my.h"

int	hexa(char *str, int size, int j)
{
  int	i;

  i = 0;
  while (i < 16 && j < size)
    {
      if (str[j] <= 15)
	my_putchar('0');
      my_putnbr_base(str[j], "0123456789abcdef");
      if (i % 2 != 0 && i != 0)
	my_putchar(' ');
      i = i + 1;
      j = j + 1;
    }
  while (i < 16)
    {
      if (i % 2 != 0)
	my_putchar(' ');
      my_putstr("  ");
      i = i + 1;
    }
  return (j);
}

int	txt(char *str, int size, int k)
{
  int	i;

  i = 0;
  while (i < 16 && k < size)
    {
      if (i == 0)
	my_putchar(' ');
      if (my_char_isprintable(str[k]))
	my_putchar(str[k]);
      else
	my_putchar('.');
      i = i + 1;
      k = k + 1;
    }
  return (0);
}

int	my_showmem(char *str, int size)
{
  int	j;
  int	k;

  j = 0;
  while (j < size)
    {
      k = j;
      my_show_address(&(str[j]));
      my_putstr(": ");
      j = hexa(str, size, j);
      txt(str, size, k);
      my_putchar('\n');
    }
  return (0);
}
