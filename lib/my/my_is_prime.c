/*
** my_is_prime.c for my_is_prime in /home/picher_y/rendu/PJ05/prime
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Fri Oct 16 21:35:07 2015 Yann Pichereau
** Last update Fri Oct 16 22:09:52 2015 Yann Pichereau
*/

int	my_is_prime(int nb)
{
  int	i;
  int	div;

  i = 3;
  if (nb <= 1)
    return (0);
  else if (nb == 2)
    return (1);
  else if (nb % 2 == 0)
    return (0);
  div = nb / 2;
  while (i <= div)
    {
      if (nb % i == 0)
	return (0);
      i = i + 2;
    }
  return (1);
}
