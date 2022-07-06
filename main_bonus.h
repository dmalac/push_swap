/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/28 15:36:57 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/06 19:02:52 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_BONUS_H
# define MAIN_BONUS_H

typedef struct s_list
{
	int				x;
	int				is_last;
	struct s_list	*prev;
	struct s_list	*nxt;
}				t_list;

typedef struct s_tools
{
	void	(*action[11])(t_list **);
	// char	**instruction;
	t_list	*a;
	t_list	*b;
}				t_tools;

# define PA 0
# define PB 1
# define SA 2
# define SB 3
# define SS 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

t_tools	*initialize(void);
void	process_input(char **input, int *num_args, t_tools *tools);
int		is_sorted(t_list *lst);
void	lst_erase(t_list **lst);
void	call_error(t_tools *tools);
void	process_line(char *line, t_tools *tools);
void	create_lnkd_lst(char **input, int n, t_tools *tools);
t_list	*lst_add_front(t_list **lst, t_list *new);
int		lst_size(t_list *lst);
int		is_unique(t_list *lst, int num);
// t_list	**get_list(t_list **a, t_list **b, char list);
/* line_checks_bonus.c */
int		is_push(char *line);
int		is_swap(char *line);
int		is_rotate(char *line);
/* actions.c */
void	swap(t_list **lst);
void	push(t_list **to, t_list **from);
void	rotate(t_list **lst);
void	rev_rotate(t_list **lst);
/* input_checks */
int		is_sorted(t_list *lst);
int		only_digits(char *str);
int		is_int(char *num);

void	lst_print(t_list *top, char list);	// delete

#endif