/*
** my_strupcase.c for my_strupcase in /home/picher_y/rendu/PJ06/ex_08
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Mon Oct  5 19:22:52 2015 Yann Pichereau
** Last update Tue Oct  6 15:03:28 2015 Yann Pichereau
*/

char	*my_strupcase(char *str)
{
  int	size;

  size = 0;
  while (str[size] != '\0')
    {
      if (str[size] >= 97 && str[size] <= 122)
	str[size] = str[size] - 32;
      size = size + 1;
    }
  return (str);
}
