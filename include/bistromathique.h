/*
** bistromathique.h for bistromathique in /home/picher_y/rendu/Piscine_C_bistromathique/include
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Fri Oct 23 15:21:58 2015 Yann Pichereau
** Last update Mon Nov  2 19:20:27 2015 Yann Pichereau
*/

#ifndef BISTROMATHIQUE_H_
# define BISTROMATHIQUE_H_

# define SYNTAX_ERROR_MSG "syntax error"
# define ERROR_MSG "Error"

typedef struct		s_number
{
  int			is_num;
  int			sign;
  char			*str;
  char			*end;
  unsigned int		length;
  unsigned int		index;
  int			prior;
  struct s_number	*next;
}			t_number;

typedef struct	s_operation
{
  t_number	nb1;
  t_number	nb2;
  t_number	result;
}		t_operation;

void		my_error_mal();
void		error_calc(t_number **npi);
void		error(char *expr);
void		error_parse(char *expr);
void		error_parse_free(char *expr, t_number **list);
void		create_error(char *expr, t_number **list);

char		*get_expr(unsigned int size);
int		check_char(char *str);
int		diff_char(char *base, char *op);
int		check_base_op(char *base, char *op);
int		parse_arg(char **av, char *expr);
int		baop_in_expr(char c, char *baop);
char		*concat_base_op(char *base, char *op);
char		*check_expr(char *expr, char *base, char *op);
t_number	*create_linked_list(char *expr, char *op, char *base);
int		redirection_put(unsigned int i, char *expr,
				char *op, t_number **list);
int		is_op(char c, char *op);
int		init_number(t_number ***list, int is_num, char *str, int sign);
int		put_parenth(t_number **list, char *expr,
			    char *op, unsigned int i);
int		put_num(t_number **list, char *expr, char *op, unsigned int i);
int		put_unaire(t_number **list, char *expr,
			   char *op, unsigned int i);
int		check_put_unaire(t_number **list, char *expr,
				 char *op, unsigned int i);
int		put_op(t_number **list, char *expr, char *op, unsigned int i);
int		put_op_bis(unsigned int i, char *expr, char *op, char *ope);
int		add_unaire(t_number **list, char *op);
void		free_struct(t_number **elem);
int		my_strcmp_base(char *s1, char *s2, char *base);
int		index_base(char c, char *base);

void		put_in_stack(t_number **stack, t_number **list);
void		put_off_stack(t_number **stack, char *op,
			      t_number **npi, char *base);
void		pop_off_stack(t_number **stack, t_number **list,
			      char *op, t_number **npi);
void		init_npi(t_number **list, t_number **elem);
void		eval_expr(t_number **list, char *op,
			  char *base, t_number **npi);

void		init_nb(t_number *nb, char *str);
void		reorder_nb(t_operation *add);
int		init_result_add(t_operation *add);
void		process_add(t_operation *add);
char		*my_add(char *nb1, char *nb2);

int		init_result_mult(t_operation *op);
void		mul_nb(t_operation *op);
char		*my_mult(char *nb1, char *nb2);

void		reorder_nb_sub(t_operation *sub);
int		init_result_sub(t_operation *sub);
void		process_sub_nb1(t_operation *sub, int ret, char *ptr);
void		process_sub_nb2(t_operation *sub);
char		*my_sub(char *nb1, char *nb2);

void		re_init_nb(t_number *nb);
char		*process_div(t_operation *op);
char		*my_div(char *nb1, char *nb2);
char		*my_div_check(char *nb1, char *nb2);
void		init_nb_div(t_number *nb, char *str);
int		my_strcmp_bistro(char *s1, char *s2);
int             init_result_div(t_operation *op);
void		set_result(t_operation *op);

char		*my_mod(char *nb1, char *nb2);

void		check_operation(t_number **npi, char *op, char *base);
char		*add_inf(t_number **n1, t_number **n2, int *sign, char *base);
char		*sub_inf(t_number **n1, t_number **n2, int *sign, char *base);

void		prior(t_number *elem, char *op);
int		parse_zero(t_number *elem, char *base);
int		my_rev_list(t_number **begin, char *base, char *op);
void		my_show_list(t_number *list);

#endif /* !BISTROMATHIQUE_H_ */
