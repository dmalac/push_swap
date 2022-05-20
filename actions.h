/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 18:11:01 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/20 16:42:46 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "list_operations.h"

void	swap(t_list **lst);
void	push(t_list **to, t_list **from);
void	rotate(t_list **lst);
void	rev_rotate(t_list **lst);
void	make_a_move(t_tools tools, int action_code, char stack);

#endif