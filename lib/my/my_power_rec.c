/*
** my_power_rec.c for my_power_rec in /home/picher_y/rendu/PJ05
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Sun Oct  4 21:07:11 2015 Yann Pichereau
** Last update Tue Oct  6 14:29:13 2015 Yann Pichereau
*/

int	my_power_rec(int nb, int power)
{
  if (power < 0)
    return (0);
  else if (power == 0)
    return (1);
  else if (power == 1)
    return (nb);
  return (nb * my_power_rec(nb, power - 1));
}
