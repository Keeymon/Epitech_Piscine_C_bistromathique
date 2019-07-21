/*
** my_putstr_r.c for my_putstr_r in /home/picher_y/rendu/PJ10/lib/my
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Tue Oct 13 13:59:36 2015 Yann Pichereau
** Last update Thu Oct 15 16:56:37 2015 Yann Pichereau
*/

#include "my.h"

int	my_putstr_r(char *str)
{
  while (*str != '\0')
    {
      my_putchar(*str);
      str = str + 1;
    }
  return (0);
}
