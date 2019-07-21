##
## Makefile for  in /home/picher_y/rendu/PJ10/lib/my
## 
## Made by Yann Pichereau
## Login   <picher_y@epitech.net>
## 
## Started on  Mon Oct 12 10:10:26 2015 Yann Pichereau
## Last update Mon Oct 26 15:25:55 2015 Yann Pichereau
##

NAME = 		libmy.a

NAME_H = 	my.h

CC_LIB = 	ar rcs

RANLIB = 	ranlib

CP = 		cp

RM = 		rm -f

CFLAGS += 	-W -Werror -Wextra -Wall -ansi -pedantic

CFLAGS += 	-I.

SRCS =  	my_putchar.c \
		my_putchar_r.c \
		my_find_prime_sup.c \
		my_getnbr.c \
		my_isneg.c \
		my_is_prime.c \
		my_power_rec.c \
		my_put_nbr.c \
		my_putstr.c \
		my_putstr_r.c \
		my_revstr.c \
		my_show_address.c \
		my_showmem.c \
		my_showstr.c \
		my_show_wordtab.c \
		my_sort_int_tab.c \
		my_square_root.c \
		my_strcapitalize.c \
		my_strcat.c \
		my_strcmp.c \
		my_strcpy.c \
		my_strdup.c \
		my_str_isalpha.c \
		my_str_islower.c \
		my_str_isnum.c \
		my_str_isprintable.c \
		my_str_isupper.c \
		my_strlen.c \
		my_strlowcase.c \
		my_strncat.c \
		my_strncmp.c \
		my_strncpy.c \
		my_strstr.c \
		my_str_to_wordtab.c \
		my_strupcase.c \
		my_swap.c \
		my_swap_char.c \
		my_putnbr_base.c \
		my_char_isprintable.c \
		sum_params.c

OBJS = 		$(SRCS:.c=.o)

all: 		$(NAME)

$(NAME):	$(OBJS)
		$(CC_LIB) $(NAME) $(OBJS)
		$(RANLIB) $(NAME)
		$(CP) $(NAME) ../
		$(CP) $(NAME_H) ../../include

clean:
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
