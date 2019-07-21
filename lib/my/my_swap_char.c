/*
** my_swap_char.c for my_swap_char in /home/picher_y/rendu/PJ06/ex_04
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Mon Oct  5 13:35:30 2015 Yann Pichereau
** Last update Mon Oct 12 15:26:56 2015 Yann Pichereau
*/

char	*my_swap_char(char *a, char *b)
{
  char	tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
  return (0);
}
