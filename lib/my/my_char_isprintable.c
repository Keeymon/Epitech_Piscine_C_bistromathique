/*
** my_char_isprintable.c for my_char_isprintable in /home/picher_y/rendu/PJ06/ex_15
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Tue Oct  6 11:40:33 2015 Yann Pichereau
** Last update Fri Oct 16 19:39:18 2015 Yann Pichereau
*/

int	my_char_isprintable(char c)
{
  if (c < 32 || c > 126)
    return (0);
  return (1);
}
