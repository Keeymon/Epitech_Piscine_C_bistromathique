/*
** my_show_wordtab.c for my_show_wordtab in /home/picher_y/rendu/PJ08/ex_03
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Thu Oct  8 14:18:36 2015 Yann Pichereau
** Last update Mon Oct 12 15:15:31 2015 Yann Pichereau
*/

#include "my.h"

int	my_show_wordtab(char **tab)
{
  int	size;

  size = 0;
  while (tab[size] != '\0')
    {
      my_putstr(tab[size]);
      my_putchar('\n');
      size = size + 1;
    }
  return (0);
}
