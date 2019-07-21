/*
** my_strcapitalize.c for my_strcapitalize in /home/picher_y/rendu/PJ06/ex_10
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Mon Oct  5 20:27:02 2015 Yann Pichereau
** Last update Fri Oct 16 14:28:23 2015 Yann Pichereau
*/

int	is_alphanum(char c)
{
  if ((c >= 'a' && c <= 'z') ||
      (c >= 'A' && c <= 'Z') ||
      (c >= '0' && c <= '9'))
    return (1);
  return (0);
}

char	*my_strcapitalize(char *str)
{
  int	i;
  int	del;

  i = 0;
  while (str[i] != '\0')
    {
      if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
	str[i] = str[i] - 32;
      else
	{
	  del = is_alphanum(str[i - 1]);
	  if (str[i] >= 'a' && str[i] <= 'z' && del == 0)
	    str[i] = str[i] - 32;
	  else if (str[i] >= 'A' && str[i] <= 'Z' && del == 1)
	    str[i] = str[i] + 32;
	}
      i = i + 1;
    }
  return (str);
}
