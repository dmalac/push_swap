/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 15:14:39 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/25 17:56:51 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list_operations.h"
#include "actions.h"
#include "sorting.h"
#include "main.h"
#include <stdlib.h>
#include "libft/ft_printf.h"

void	swap(t_list **lst)
{
	t_list	*first;
	t_list	*second;
	int		size;

	size = lst_size(*lst);
	first = *lst;
	second = first->nxt;
	if (size > 1)
	{
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
	if (size > 0)
	{
		to_move = *from;
		new_top = (*from)->nxt;
		new_top->prev = (*from)->prev;
		new_top->prev->nxt = new_top;
		*to = lst_add_front(to, to_move);
		if (size == 1)
			*from = (NULL);
		else
			*from = new_top;
	}
}

void	rotate(t_list **lst)
{
	(*lst)->prev->is_last = 0;
	(*lst)->is_last = 1;
	*lst = (*lst)->nxt;
}

void	rev_rotate(t_list **lst)
{
	(*lst)->prev->is_last = 0;
	(*lst)->prev->prev->is_last = 1;
	*lst = (*lst)->prev;
}

void	make_a_move(t_tools *tools, int action_code, char stack)
{
	t_list	**lst;

	lst = get_list(tools, stack);
	if (action_code == PX)
	{
		ft_printf("%s%c\n", tools->instruction[action_code], stack);
		if (stack == 'a')
			push(&tools->a, &tools->b);
		else
			push(&tools->b, &tools->a);
	}
	else if (action_code > 0 && action_code % 2 > 0)
	{
		ft_printf("%s%c\n", tools->instruction[action_code], stack);
		tools->action[action_code](lst);
	}
	else if (action_code > 0 && action_code % 2 == 0)
	{
		ft_printf("%s%c\n", tools->instruction[action_code], stack);
		tools->action[action_code](&tools->a);
		tools->action[action_code](&tools->b);
	}
	lst_print(tools->a, 'A');
	lst_print(tools->b, 'B');
}