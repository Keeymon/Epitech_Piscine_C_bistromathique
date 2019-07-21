/*
** my_strcmp_base.c for my_strcmp_base in /home/picher_y/rendu/Piscine_C_bistromathique
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Sun Nov  1 05:21:36 2015 Yann Pichereau
** Last update Sun Nov  1 20:28:36 2015 Yann Pichereau
*/

#include "bistromathique.h"
#include "my.h"

int		index_base(char c, char *base)
{
  unsigned int	i;

  i = 0;
  while (c != base[i])
    i++;
  return (i);
}

int		my_strcmp_base(char *s1, char *s2, char *base)
{
  unsigned int	size;
  unsigned int	i;

  i = 0;
  size = my_strlen(s1);
  if (size > my_strlen(s2))
    return (1);
  else if (size < my_strlen(s2))
    return (-1);
  while (i < size)
    {
      if (index_base(s1[i], base) < index_base(s2[i], base))
	return (-1);
      else if (index_base(s1[i], base) > index_base(s2[i], base))
	return (1);
      i++;
    }
  return (0);
}
