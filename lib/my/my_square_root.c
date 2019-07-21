/*
** my_square_root.c for my_square_root in /home/picher_y/rendu/PJ05/square
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Fri Oct 16 20:26:43 2015 Yann Pichereau
** Last update Fri Oct 16 20:55:26 2015 Yann Pichereau
*/

int	my_square_root(int nb)
{
  int	i;
  int	result;

  i = 0;
  while (i <= 46340)
    {
      result = i * i;
      if (result > nb)
	return (0);
      else if (result == nb)
	return (i);
      else
	i = i + 1;
    }
  return (0);
}
