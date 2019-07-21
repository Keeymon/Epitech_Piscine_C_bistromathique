/*
** free.c for free in /home/picher_y/rendu/Piscine_C_bistromathique
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Sat Oct 31 21:29:27 2015 Yann Pichereau
** Last update Sat Oct 31 21:33:50 2015 Yann Pichereau
*/

#include <stdlib.h>
#include "bistromathique.h"

void		free_struct(t_number **elem)
{
  free((*elem)->str);
  free(*elem);
}
