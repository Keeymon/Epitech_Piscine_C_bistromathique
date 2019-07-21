/*
** my_str_islower.c for my_str_islower in /home/picher_y/rendu/PJ06/ex_13
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Tue Oct  6 11:12:48 2015 Yann Pichereau
** Last update Fri Oct 16 15:38:11 2015 Yann Pichereau
*/

int	my_str_islower(char *str)
{
  while (*str != '\0')
    {
      if (*str < 'a' || *str > 'z')
	return (0);
      str = str + 1;
    }
  return (1);
}
