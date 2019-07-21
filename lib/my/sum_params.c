/*
** sum_params.c for sum_params in /home/picher_y/rendu/PJ08/ex_02
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Thu Oct  8 11:30:07 2015 Yann Pichereau
** Last update Thu Oct  8 23:40:19 2015 Yann Pichereau
*/

#include <stdlib.h>
#include "my.h"

char	*sum_params(int argc, char **argv)
{
  int	count;
  int	lenght;
  char	*str;

  lenght = 0;
  count = 0;
  while (count < argc)
    {
      lenght = lenght + my_strlen(argv[count]) + 1;
      count = count + 1;
    }
  str = malloc(lenght);
  count = 0;
  while (count < argc)
    {
      my_strcat(str, argv[count]);
      if (count < argc - 1)
	my_strcat(str, "\n");
      else
	my_strcat(str, "\0");
      count = count + 1;
    }
  return (str);
}
