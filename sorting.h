/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 15:04:01 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/12 16:32:35 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include "list_operations.h"

/* sorting.c */
void	sort_two(t_list **lst);
void	sort_three(t_list **lst);
void	rev_sort_three(t_list **lst);

#endif