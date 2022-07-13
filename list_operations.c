/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_operations.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/04 11:21:23 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/13 17:32:16 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "list_structure.h"
#include <stdlib.h>
#include <limits.h>

void	lst_erase(t_list **lst)
{
	t_list	*current;

	current = *lst;
	if (current)
	{
		while (current->prev->is_last != 1)
			current = current->prev;
		while (current->is_last == 0)
		{
			current = current->nxt;
			free(current->prev);
		}
		free(current);
	}
}

/* for testing purposes; to be removed at some point */
void	lst_print(t_list *top, char list)
{
	t_list	*current;

	// ft_putchar_fd('\t', 2);
	ft_putstr_fd("Stack ", 2);
	ft_putchar_fd(list, 2);
	ft_putchar_fd(':', 2);
	// ft_putchar_fd(' ', 2);
	ft_putchar_fd('\n', 2);
	if (top)
	{
		current = top;
		while (current->is_last != 1)
		{
			ft_putnbr_fd(current->x, 2);
			ft_putchar_fd(' ', 2);
			ft_printf("\tnext value: %d\tprevious value: %d\taddress of next node: %p, \taddress of next->next node: %p\n", \
			current->nxt->x, current->prev->x, (void *)current->nxt, (void *)current->nxt->nxt);
			current = current->nxt;
		}
		ft_putnbr_fd(current->x, 2);
		ft_printf("\tnext value: %d\tprevious value: %d\taddress of next node: %p, \taddress of next->next node: %p\n", \
		current->nxt->x, current->prev->x, (void *)current->nxt, (void *)current->nxt->nxt);
	}
	else
		ft_putstr_fd("<empty>", 2);
	ft_putchar_fd('\n', 2);
}

int	lst_size(t_list *lst)
{
	int		size;
	t_list	*current;

	ft_printf("lst_size called\n");
	// lst_print(lst, 'X');
	size = 1;
	if (lst == NULL)
		return (0);
	current = lst;
	while (current->is_last == 0)
	{
		ft_printf("value: %d\tis_last: %d\tnxt value: %d\tprev value: %d\tnxt address: %p, \tnxt nxt address: %p\n", \
		current->x, current->is_last, current->nxt->x, current->prev->x, (void *)current->nxt, (void *)current->nxt->nxt);
		size++;
		current = current->nxt;
	}
	current = lst->prev;
	while (current->is_last == 0)
	{
		size++;
		current = current->prev;
	}
	// ft_printf("about to return size=%d\n", size);
	return (size);
}

int	lst_max(t_list *lst)
{
	int	max;

	max = INT_MIN;
	while (lst->is_last == 0)
	{
		if (lst->x > max)
			max = lst->x;
		lst = lst->nxt;
	}
	if (lst->x > max)
		max = lst->x;
	return (max);
}

int	lst_min(t_list *lst)
{
	int	min;

	min = INT_MAX;
	while (lst->is_last == 0)
	{
		if (lst->x < min)
			min = lst->x;
		lst = lst->nxt;
	}
	if (lst->x < min)
		min = lst->x;
	return (min);
}

t_list	**get_list(t_list **a, t_list **b, char list)
{
	t_list	**lst;

	if (list == 'a')
		lst = a;
	else
		lst = b;
	return (lst);
}

