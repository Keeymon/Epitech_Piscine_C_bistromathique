/*
** my_strlowcase.c for my_strlowcase in /home/picher_y/rendu/PJ06/ex_09
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Mon Oct  5 19:59:12 2015 Yann Pichereau
** Last update Tue Oct  6 23:05:22 2015 Yann Pichereau
*/

char	*my_strlowcase(char *str)
{
  int	size;

  size = 0;
  while (str[size] != '\0')
    {
      if (str[size] >= 65 && str[size] <= 90)
	str[size] = str[size] + 32;
      size = size + 1;
    }
  return (str);
}
