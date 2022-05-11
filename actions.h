/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 18:11:01 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/11 18:44:14 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "list_operations.h"

t_list	*swap(t_list **lst);
t_list	*push(t_list **to, t_list **from);
t_list	*rotate(t_list *lst);
t_list	*rev_rotate(t_list *lst);

#endif