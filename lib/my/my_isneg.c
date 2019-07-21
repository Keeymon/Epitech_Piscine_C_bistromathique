/*
** my_isneg.c for my_isneg in /home/picher_y/rendu/Lib/Function
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Tue Oct  6 15:50:02 2015 Yann Pichereau
** Last update Mon Oct 12 14:44:37 2015 Yann Pichereau
*/

#include "my.h"

int	my_isneg(int i)
{
  if (i >= 0)
    my_putchar('P');
  else
    my_putchar('N');
  return (0);
}
