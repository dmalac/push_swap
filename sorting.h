/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 15:04:01 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/06/02 20:39:59 by dmalacov      ########   odam.nl         */
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
/* large_stack.c */
int		is_in_tranche(int x, int tr_min, int tr_max);
/* sorting_large.c */
void	move_tranche_to_b(t_tools *tools, int *tr_limits, int tr);

#endif