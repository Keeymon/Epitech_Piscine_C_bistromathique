/*
** my_strstr.c for my_strstr in /home/picher_y/rendu/PJ06/ex_05
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Mon Oct  5 14:12:51 2015 Yann Pichereau
** Last update Tue Oct  6 23:05:02 2015 Yann Pichereau
*/

char	*my_strstr(char *str, char *to_find)
{
  int	size;
  int	find;

  size = 0;
  if (to_find[size] == '\0')
    return (&str[size]);
  while (str[size] != '\0')
    {
      find = 0;
      while (to_find[find] != '\0' && to_find[find] == str[size + find])
	{
	  if (to_find[find + 1] == '\0')
	    return (&str[size]);
	  find = find + 1;
	}
      size = size + 1;
    }
  return (0);
}
