/*
** my_strncat.c for my_strncat in /home/picher_y/rendu/PJ07/ex_03
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Wed Oct  7 10:29:07 2015 Yann Pichereau
** Last update Sat Oct 17 17:31:53 2015 Yann Pichereau
*/

#include "my.h"

char	*my_strncat(char *dest, char *src, int nb)
{
  int	size_dest;
  int	size_src;

  size_dest = my_strlen(dest);
  size_src = 0;
  if (nb < 0)
    nb = my_strlen(src);
  while (src[size_src] != '\0' && size_src < nb)
    {
      dest[size_dest + size_src] = src[size_src];
      size_src = size_src + 1;
    }
  dest[size_dest + size_src] = '\0';
  return (dest);
}
