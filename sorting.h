/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 15:04:01 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/06/16 14:55:17 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include "list_operations.h"	// possibly restructure to avoid this ?

typedef struct s_nxt_step
{
	int	a_steps;
	int	a_dir;
	int	a_value;
	int	b_steps;
	int	b_dir;
}				t_nxt_step;

/* sorting.c */
void		sort_two(t_tools *tools, char list);
void		sort_three(t_tools *tools, char list);
void		rev_sort_three(t_tools *tools, char list);
t_list		**get_list(t_tools *tools, char list);
/* small_stack.c */
void		get_to_the_place(t_tools *tools, int moves, char list);
void		offload(t_tools *tools, int n, char dest);
/* large_stack.c */
int			is_in_tranche(int x, int tr_min, int tr_max);
int			right_place(t_list *b, int x);
/* sorting_large.c */
void		move_tranche_to_b(t_tools *tools, int *tr_limits, int tr);
/* tranche_operations.c */
void		find_nxt_elem(t_list *lst, int *tr_limits, int tr, t_nxt_step *nxt);
t_nxt_step	*most_efficient_move(t_tools *tools, t_nxt_step *nxt_r, \
t_nxt_step *nxt_rr);
void		perform(t_tools *tools, t_nxt_step *nxt_step);
void		go_to(t_tools *tools, int moves, int direction, char list);
#endif