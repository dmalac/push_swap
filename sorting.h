/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 15:04:01 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/20 16:42:46 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include "list_operations.h"

/* sorting.c */
// void	sort_two(t_list **lst, char list);
// void	sort_three(t_list **lst, char list);
// void	rev_sort_three(t_list **lst, char list);
void	sort_two(t_tools tools, char list);
void	sort_three(t_tools tools, char list);
void	rev_sort_three(t_tools tools, char list);
t_list	*get_list(t_tools tools, char list);

#endif