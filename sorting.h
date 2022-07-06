/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 15:04:01 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/06 19:02:52 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include "list_manipulation.h"	// possibly restructure to avoid this ?

typedef struct s_nxt_move
{
	int	a_steps;
	int	a_dir;
	int	a_value;
	int	b_steps;
	int	b_dir;
}				t_nxt_move;

/* sorting.c */
void		sort_two(t_tools *tools, char list);
void		sort_three(t_tools *tools, char list);
void		rev_sort_three(t_tools *tools, char list);
t_list		**get_list(t_list **a, t_list **b, char list);
/* small_stack.c */
void		offload(t_tools *tools, int n, char dest);
int			find_top_a(t_list *lst);
/* large_stack.c */
int			is_in_tranche(int x, int tr_min, int tr_max);
int			right_place(t_list *b, int x);
int			find_top_b(t_list *lst);
/* sorting_large.c */
void		move_tranche_to_b(t_tools *tools, int *tr_limits, int tr);
/* stack_operations.c */
void		move_to_the_top(t_tools *tools, char list);
int			belongs_to(t_list *lst, int x, char list);
void		make_a_move(t_tools *tools, int action_code, char stack);
/* sorting_large.c */
void		find_nxt_elem(t_list *lst, int *tr_limits, int tr, t_nxt_move *nxt);
t_nxt_move	*most_efficient_move(t_tools *tools, t_nxt_move *nxt_r, \
t_nxt_move *nxt_rr);
void		perform(t_tools *tools, t_nxt_move *nxt);
void		go_to(t_tools *tools, int moves, int direction, char list);

#endif