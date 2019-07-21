/*
** my_strncmp.c for my_strncmp in /home/picher_y/rendu/PJ06/ex_07
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Mon Oct  5 19:06:29 2015 Yann Pichereau
** Last update Thu Oct 15 19:15:12 2015 Yann Pichereau
*/

#include "my.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	size;
  int	i;

  i = 0;
  size = my_strlen(s1);
  if (n < 0)
    n = size + 1;
  while (i <= size && i < n)
    {
      if (s1[i] < s2[i])
	return (-1);
      else if (s1[i] > s2[i])
	return (1);
      i = i + 1;
    }
  return (0);
}
