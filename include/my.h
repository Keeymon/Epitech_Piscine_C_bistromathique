/*
** my.h for  in /home/picher_y/rendu/PJ08/include
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Thu Oct  8 22:53:17 2015 Yann Pichereau
** Last update Sun Nov  1 07:40:25 2015 Yann Pichereau
*/

#ifndef MY_H_
# define MY_H_

void		my_putchar(char c);
void		my_putchar_r(char c);
int		my_isneg(int nb);
int		my_put_nbr(int nb);
int		my_swap(int *a, int *b);
char		*my_swap_char(char *a, char *b);
int		my_putstr(char *str);
int		my_putstr_r(char *str);
unsigned int	my_strlen(char *str);
int		my_getnbr(char *str);
void		my_sort_int_tab(int *tab, int size);
int		my_power_rec(int nb, int power);
int		my_square_root(int nb);
int		my_is_prime(int nombre);
int		my_find_prime_sup(int nb);
char		*my_strcpy(char *dest, char *src);
char		*my_strncpy(char *dest, char *src, int nb);
char		*my_revstr(char *str);
char		*my_strstr(char *str, char *to_find);
int		my_strcmp(char *s1, char *s2);
int		my_strncmp(char *s1, char *s2, int nb);
char		*my_strupcase(char *str);
char		*my_strlowcase(char *str);
char		*my_strcapitalize(char *str);
int		my_str_isalpha(char *str);
int		my_str_isnum(char *str);
int		my_str_islower(char *str);
int		my_str_isupper(char *str);
int		my_str_isprintable(char *str);
int		my_showstr(char *str);
void		my_show_address(void *add);
int		my_showmem(char *str, int size);
char		*my_strcat(char *dest, char *src);
char		*my_strncat(char *dest, char *src, int nb);
char		*my_strdup(char *src);
char		*sum_params(int argc, char **argv);
int		my_show_wordtab(char **tab);
char		**my_str_to_wordtab(char *str);
int		my_putnbr_base(int nbr, char *base);
int		my_char_isprintable(char c);

#endif /* !MY_H_ */
