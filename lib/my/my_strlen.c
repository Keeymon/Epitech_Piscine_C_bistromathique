/*
** my_strlen.c for day04 in /home/picher_y/rendu/Piscine_C_J04
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Thu Oct  1 16:55:01 2015 Yann Pichereau
** Last update Sun Nov  1 07:39:02 2015 Yann Pichereau
*/

unsigned int	my_strlen(char *str)
{
  unsigned int	compt;

  compt = 0;
  while (str[compt] != '\0')
    compt = compt + 1;
  return (compt);
}
