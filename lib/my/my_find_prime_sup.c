/*
** my_find_prime_sup.c for my_find_prime_sup in /home/picher_y/rendu/PJ05
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Fri Oct 16 22:23:01 2015 Yann Pichereau
** Last update Fri Oct 16 22:46:49 2015 Yann Pichereau
*/

#include "my.h"

int	my_find_prime_sup(int nb)
{
  if (nb <= 1)
    return (2);
  if (nb == 2)
    return (2);
  if (nb % 2 == 0)
    nb = nb + 1;
  if (my_is_prime(nb))
    return (nb);
  nb = nb + 2;
  while (my_is_prime(nb) == 0)
    nb = nb + 2;
  return (nb);
}
