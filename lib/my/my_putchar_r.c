/*
** my_putchar_r.c for my_putchar_r in /home/picher_y/rendu/PJ10/lib/my
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Tue Oct 13 13:58:23 2015 Yann Pichereau
** Last update Tue Oct 13 13:59:03 2015 Yann Pichereau
*/

#include <unistd.h>

void	my_putchar_r(char c)
{
  write(2, &c, 1);
}
