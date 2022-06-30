/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 18:11:01 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/06/30 16:22:28 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "list_manipulation.h"

void	swap(t_list **lst);
void	push(t_list **to, t_list **from);
void	rotate(t_list **lst);
void	rev_rotate(t_list **lst);
void	make_a_move(t_tools *tools, int action_code, char stack);
/* sorting_small */
void	get_to_the_place(t_tools *tools, int moves, char list);

#endif