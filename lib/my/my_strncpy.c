/*
** my_strncpy.c for my_strncpy in /home/picher_y/rendu/PJ06/ex_03
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Mon Oct  5 11:59:20 2015 Yann Pichereau
** Last update Tue Oct 27 11:06:42 2015 Yann Pichereau
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	compt;
  int	overflow;

  compt = 0;
  overflow = 0;
  while (compt < n)
    {
      if (src[compt] == '\0' || overflow == 1)
	{
	  dest[compt] = '\0';
	  overflow = 1;
	}
      dest[compt] = src[compt];
      compt = compt + 1;
    }
  return (dest);
}
