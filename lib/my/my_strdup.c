/*
** my_strdup.c for my_strdup in /home/picher_y/rendu/PJ08/ex_01
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Wed Oct  7 23:19:14 2015 Yann Pichereau
** Last update Thu Oct  8 23:40:55 2015 Yann Pichereau
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  int	size;
  char	*str;

  size = my_strlen(src) + 1;
  str = malloc(size);
  str[size - 1] = '\0';
  my_strcpy(str, src);
  return (str);
}
