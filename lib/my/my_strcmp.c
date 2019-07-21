/*
** my_strcmp.c for my_strcmp in /home/picher_y/rendu/PJ06/ex_06
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Mon Oct  5 17:25:32 2015 Yann Pichereau
** Last update Thu Oct 15 18:15:23 2015 Yann Pichereau
*/

#include "my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	size;
  int	i;

  i = 0;
  size = my_strlen(s1);
  while (i <= size)
    {
      if (s1[i] < s2[i])
	return (-1);
      if (s1[i] > s2[i])
	return (1);
      i = i + 1;
    }
  return (0);
}
