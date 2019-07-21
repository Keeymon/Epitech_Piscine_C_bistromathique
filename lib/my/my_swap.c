/*
** my_swap.c for day04 in /home/picher_y/rendu/Piscine_C_J04
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Thu Oct  1 12:38:38 2015 Yann Pichereau
** Last update Thu Oct  1 18:41:33 2015 Yann Pichereau
*/

int	my_swap(int *a, int *b)
{
  int	tmp;

  tmp = *b;
  *b = *a;
  *a = tmp;
  return (0);
}
