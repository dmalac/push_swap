/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 17:12:12 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/07 17:34:05 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "list_structure.h"

# define PX 0
# define SX 1
# define SS 2
# define RX 3
# define RR 4
# define RRX 5
# define RRR 6

typedef struct s_tools
{
	void	(*action[7])(t_list **);
	char	**instruction;
	t_list	*a;
	t_list	*b;
	int		tranches;
}				t_tools;

typedef struct s_nxt_move
{
	int	a_steps;
	int	a_dir;
	int	a_value;
	int	b_steps;
	int	b_dir;
}				t_nxt_move;

/* main.c */
void		call_error(t_tools *tools);
/* initialisations.c */
t_tools		*initialize(void);
/* input_processing.c */
void		process_input(char **input, int *num_args, t_tools *tools);
/* tranche_limits.c */
int			*get_limits(t_list *lst, int tranches);
int			how_many_tranches(int num_args);
int			is_in_tranche(int x, int tr_min, int tr_max);
/* small_stack.c */
void		sort_small_stack(t_tools *tools);
int			find_top_a(t_list *lst);
/* sorting_small.c */
void		sort_two(t_tools *tools, char list);
void		sort_three(t_tools *tools, char list);
void		rev_sort_three(t_tools *tools, char list);
/* stack_operations.c */
void		move_to_the_top(t_tools *tools, char list);
int			belongs_to(t_list *lst, int x, char list);
void		make_a_move(t_tools *tools, int action_code, char stack);
void		go_to(t_tools *tools, int moves, int direction, char list);
void		offload(t_tools *tools, int n, char dest);
/* list_operations.c */
int			lst_max(t_list *lst);
int			lst_min(t_list *lst);
t_list		**get_list(t_list **a, t_list **b, char list);
/* large_stack.c */
void		sort_large_stack(t_tools *tools);
int			find_top_b(t_list *lst);
/* sorting_large.c */
void		find_nxt_elem(t_list *lst, int *tr_limits, int tr, \
t_nxt_move *nxt);
t_nxt_move	*most_efficient_move(t_tools *tools, t_nxt_move *nxt_r, \
t_nxt_move *nxt_rr);
void		perform(t_tools *tools, t_nxt_move *nxt);

#endif