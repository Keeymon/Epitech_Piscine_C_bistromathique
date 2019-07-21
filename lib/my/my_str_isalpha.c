/*
** my_str_isalpha.c for my_str_isalpha in /home/picher_y/rendu/PJ06/ex_11
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Tue Oct  6 01:02:14 2015 Yann Pichereau
** Last update Fri Oct 16 15:29:56 2015 Yann Pichereau
*/

int	my_str_isalpha(char *str)
{
  while (*str != '\0')
    {
      if ((*str < 'A' || *str > 'Z') && (*str < 'a' || *str > 'z'))
	return (0);
      str = str + 1;
    }
  return (1);
}
