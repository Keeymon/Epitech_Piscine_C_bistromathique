/*
** my_str_isprintable.c for my_str_isprintable in /home/picher_y/rendu/PJ06/ex_15
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Tue Oct  6 11:40:33 2015 Yann Pichereau
** Last update Fri Oct 16 15:40:27 2015 Yann Pichereau
*/

int	my_str_isprintable(char *str)
{
  while (*str != '\0')
    {
      if (*str < 32 || *str > 126)
	return (0);
      str = str + 1;
    }
  return (1);
}
