/*
** my_strcpy.c for my_strcpy in /home/picher_y/rendu/PJ06/ex_02
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Mon Oct  5 10:03:57 2015 Yann Pichereau
** Last update Sun Oct 25 11:08:39 2015 Yann Pichereau
*/

char	*my_strcpy(char *dest, char *src)
{
  int	compt;

  compt = 0;
  while (src[compt] != '\0')
    {
      dest[compt] = src[compt];
      compt = compt + 1;
    }
  dest[compt] = '\0';
  return (dest);
}
