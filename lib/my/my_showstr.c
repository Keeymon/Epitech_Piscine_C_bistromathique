/*
** my_showstr.c for my_showstr in /home/picher_y/rendu/PJ06/ex_18
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Fri Oct 16 15:44:20 2015 Yann Pichereau
** Last update Fri Oct 16 19:45:53 2015 Yann Pichereau
*/

#include "my.h"

int	my_showstr(char *str)
{
  while (*str != '\0')
    {
      if (my_char_isprintable(*str))
	my_putchar(*str);
      else
	{
	  my_putchar('\\');
	  if (*str <= 15)
	    my_putchar('0');
	  my_putnbr_base(*str, "0123456789abcdef");
	}
      str = str + 1;
    }
  return (0);
}
