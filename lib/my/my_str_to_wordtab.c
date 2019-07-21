/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/picher_y/rendu/PJ08/ex_04
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Thu Oct  8 15:16:46 2015 Yann Pichereau
** Last update Mon Oct 12 15:27:04 2015 Yann Pichereau
*/

#include <stdlib.h>
#include "my.h"

int	my_char_is_alphanum(char str)
{
  if ((str >= 48 && str <= 57) ||
      (str >= 65 && str <= 90) ||
      (str >= 97 && str <= 122))
    return (1);
  return (0);
}

int	count_word(char *str)
{
  int	count;
  int	alpha;
  int	pre_alpha;
  int	nb_word;

  count = 0;
  nb_word = 0;
  while (str[count] != '\0')
    {
      alpha = my_char_is_alphanum(str[count]);
      pre_alpha = my_char_is_alphanum(str[count - 1]);
      if (count == 0 && alpha == 1)
	nb_word = 1;
      else if (count == 0 && alpha == 0)
	nb_word = 0;
      else if (alpha == 1 && pre_alpha == 0)
	nb_word = nb_word + 1;
      else if (alpha == 0)
	str[count] = '\0';
      count = count + 1;
    }
  return (nb_word);
}

char	**incre_wordtab(char *str, char **my_array, int size)
{
  int	count;
  int	alpha;
  int	pre_alpha;
  int	nb_word;

  count = 0;
  nb_word = 0;
  while (count < size)
    {
      alpha = my_char_is_alphanum(str[count]);
      pre_alpha = my_char_is_alphanum(str[count - 1]);
      if (alpha == 1 && pre_alpha == 0)
	{
	  my_array[nb_word] = &str[count];
	  nb_word = nb_word + 1;
	}
      count = count + 1;
    }
  return (my_array);
}

char	**my_str_to_wordtab(char *str)
{
  char	**my_array;
  int	nb_word;
  int	size;

  size = my_strlen(str);
  nb_word = count_word(str);
  my_array = malloc((1 + nb_word) * sizeof(char *));
  incre_wordtab(str, my_array, size);
  return (my_array);
}
