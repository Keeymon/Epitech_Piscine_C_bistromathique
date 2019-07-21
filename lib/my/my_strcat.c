/*
** my_strcat.c for my_strcat in /home/picher_y/rendu/Piscine_C_J07/ex_02
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Tue Oct  6 18:16:50 2015 Yann Pichereau
** Last update Mon Oct 12 15:18:21 2015 Yann Pichereau
*/

#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	size_dest;
  int	size_src;

  size_dest = my_strlen(dest);
  size_src = 0;
  while (src[size_src] != '\0')
    {
      dest[size_dest + size_src] = src[size_src];
      size_src = size_src + 1;
    }
  dest[size_dest + size_src] = '\0';
  return (dest);
}
