/*
** my_putchar.c for my_putchar in /home/picher_y/rendu/Lib/Function
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Tue Oct  6 15:47:05 2015 Yann Pichereau
** Last update Mon Oct 12 14:50:28 2015 Yann Pichereau
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
