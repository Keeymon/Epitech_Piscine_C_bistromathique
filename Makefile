##
## Makefile for  in /home/picher_y/rendu/Piscine_C_bistromathique
## 
## Made by Yann Pichereau
## Login   <picher_y@epitech.net>
## 
## Started on  Mon Oct 26 14:31:56 2015 Yann Pichereau
## Last update Sun Nov  1 23:00:30 2015 Yann Pichereau
##

NAME = 		calc

CC = 		cc

RM = 		rm -f

LIB = 		-lmy

LIBDIR = 	-L./lib/

INCLUDE = 	-I./include/

LIBMAKE = 	lib/my/

CFLAGS += 	$(LIB) $(LIBDIR) $(INCLUDE)

CFLAGS += 	-W -Wall -Werror -Wextra -ansi -pedantic

SRCS = 		main.c \
		put_error.c \
		parse_arg.c \
		base_op_in_str.c \
		create_linked_list.c \
		put_in_list.c \
		put_in_list_bis.c \
		npi_expr.c \
		check_operation.c \
		my_infin_add.c \
		my_mult.c \
		my_subtract.c \
		my_div.c \
		my_div_bis.c \
		my_mod.c \
		free.c \
		my_strcmp_base.c \
		my_show_list.c

OBJS = 		$(SRCS:.c=.o)

all : 		lib $(NAME)

lib :
		make -C $(LIBMAKE)

$(NAME) :	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LIB) $(LIBDIR) $(INCLUDE) $(CFLAGS)

clean :
		make clean -C $(LIBMAKE)
		$(RM) $(OBJS)

fclean : 	clean
		$(RM) $(NAME)
		make fclean -C $(LIBMAKE)

re : 		fclean all

.PHONY : 	all lib fclean clean re
