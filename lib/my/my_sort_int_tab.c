/*
** my_sort_int_tab.c for my_sort_int_tab in /home/picher_y/rendu/PJ04
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Sat Oct 17 16:09:50 2015 Yann Pichereau
** Last update Sun Oct 18 12:38:51 2015 Yann Pichereau
*/

#include "my.h"

void	my_sort_int_tab(int *tab, int size)
{
  int	i;
  int	j;

  j = 0;
  while (j == 0)
    {
      j = 1;
      i = 0;
      while (i < size - 1)
	{
	  if (tab[i] > tab[i + 1])
	    {
	      my_swap(&tab[i], &tab[i + 1]);
	      j = 0;
	    }
	  i = i + 1;
	}
    }
}
