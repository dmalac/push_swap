/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 15:14:39 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/11 17:56:11 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list_structure.h"
#include "prototypes_shared.h"
#include <stdlib.h>
#include "libft/ft_printf.h"	// delete

void	swap(t_list **lst)
{
	t_list	*first;
	t_list	*second;
	int		size;

	size = lst_size(*lst);
	if (size > 1)
	{
		first = *lst;
		second = first->nxt;
		if (second->is_last == 1)
		{
			second->is_last = 0;
			first->is_last = 1;
		}
		if (size > 2)
		{
			first->nxt = second->nxt;
			second->nxt = first;
			second->prev = first->prev;
			first->prev = second;
			second->prev->nxt = second;
			first->nxt->prev = first;
		}
		*lst = second;
	}
}

void	push(t_list **to, t_list **from)
{
	int		size;
	t_list	*to_move;
	t_list	*new_top;

	size = lst_size(*from);
	ft_printf("size is %d\n", size);
	if (size > 0)
	{
		to_move = *from;
		new_top = (*from)->nxt;
		new_top->prev = (*from)->prev;
		new_top->prev->nxt = new_top;
		ft_printf("about to call lst_add_front\n");
		*to = lst_add_front(to, to_move);
		if (size == 1)
			*from = (NULL);
		else
		{	
			*from = new_top;
			if (size == 2)
				(*from)->is_last = 1;
		}
	}
}

void	rotate(t_list **lst)
{
	if (*lst)
	{	
		(*lst)->prev->is_last = 0;
		(*lst)->is_last = 1;
		*lst = (*lst)->nxt;
	}
}

void	rev_rotate(t_list **lst)
{
	if (*lst)
	{
		(*lst)->prev->is_last = 0;
		(*lst)->prev->prev->is_last = 1;
		*lst = (*lst)->prev;
	}
}
