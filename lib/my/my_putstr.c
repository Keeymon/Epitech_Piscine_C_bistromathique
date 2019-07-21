/*
** my_putstr.c for day04 in /home/picher_y/rendu/Piscine_C_J04
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Thu Oct  1 16:03:18 2015 Yann Pichereau
** Last update Mon Oct 12 14:58:38 2015 Yann Pichereau
*/

#include "my.h"

int	my_putstr(char *str)
{
  int	compt;

  compt = 0;
  while (str[compt] != '\0')
    {
      my_putchar(str[compt]);
      compt = compt + 1;
    }
  return (0);
}
