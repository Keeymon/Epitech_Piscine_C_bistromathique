/*
** my_str_isupper.c for my_str_isupper in /home/picher_y/rendu/PJ06/ex_14
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Tue Oct  6 11:25:10 2015 Yann Pichereau
** Last update Fri Oct 16 15:39:16 2015 Yann Pichereau
*/

int	my_str_isupper(char *str)
{
  while (*str != '\0')
    {
      if (*str < 'A' || *str > 'Z')
	return (0);
      str = str + 1;
    }
  return (1);
}
