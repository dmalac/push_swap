/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 15:14:39 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/12 11:59:17 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list_operations.h"
#include "actions.h"
#include <stdlib.h>

t_list	*swap(t_list *lst)
{
	t_list	*first;
	t_list	*second;
	int		size;

	size = lst_size(lst);
	if (size <= 1)
		return (lst);
	first = lst;
	second = first->nxt;
	if (second->is_last == 1)
	{
		second->is_last = 0;
		first->is_last = 1;
	}
	if (size == 2)
		return (second);
	first->nxt = second->nxt;
	second->nxt = first;
	second->prev = first->prev;
	first->prev = second;
	second->prev->nxt = second;
	first->nxt->prev = first;
	return (second);
}

t_list	*push(t_list **to, t_list **from)
{
	t_list	*to_move;
	t_list	*new_top;
	int		size;

	size = lst_size(*from);
	if (size == 0)
		return (*from);
	to_move = *from;
	new_top = to_move->nxt;
	new_top->prev = to_move->prev;
	new_top->prev->nxt = new_top;
	*to = lst_add_front(to, to_move);
	if (size == 1)
		return (NULL);
	else
		return (new_top);
}

t_list	*rotate(t_list *lst)
{
	lst->prev->is_last = 0;
	lst->is_last = 1;
	return (lst->nxt);
}

t_list	*rev_rotate(t_list *lst)
{
	lst->prev->is_last = 0;
	lst->prev->prev->is_last = 1;
	return (lst->prev);
}
