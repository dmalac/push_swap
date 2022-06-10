/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 15:04:01 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/06/08 13:29:36 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include "list_operations.h"

/* sorting.c */
void	sort_two(t_tools *tools, char list);
void	sort_three(t_tools *tools, char list);
void	rev_sort_three(t_tools *tools, char list);
t_list	**get_list(t_tools *tools, char list);
/* small_stack.c */
void	get_to_the_place(t_tools *tools, int moves, char list);
void	offload(t_tools *tools, int n, char dest);
/* large_stack.c */
int		is_in_tranche(int x, int tr_min, int tr_max);
/* sorting_large.c */
void	move_tranche_to_b(t_tools *tools, int *tr_limits, int tr);

#endif