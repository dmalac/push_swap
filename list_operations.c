/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_operations.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/04 11:21:23 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/06/30 16:22:28 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list_manipulation.h"
#include "libft/libft.h"
#include "main.h"
#include <stdlib.h>

void	lst_erase(t_list **lst)
{
	t_list	*current;

	current = *lst;
	if (current)
	{
		while (current->is_last == 0)
		{
			current = current->nxt;
			free(current->prev);
		}
		free(current);
	}
	exit (0);
}

int	lst_size(t_list *lst)
{
	int		size;
	t_list	*current;

	size = 1;
	if (lst == NULL)
		return (0);
	current = lst;
	while (current->is_last == 0)
	{
		size++;
		current = current->nxt;
	}
	current = lst->prev;
	while (current->is_last == 0)
	{
		size++;
		current = current->prev;
	}
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

/* for testing purposes; to be removed at some point */
void	lst_print(t_list *top, char list)
{
	t_list	*current;

	ft_putchar_fd('\t', 2);
	ft_putchar_fd(list, 2);
	ft_putchar_fd(':', 2);
	ft_putchar_fd(' ', 2);
	if (top)
	{
		current = top;
		while (current->is_last != 1)
		{
			ft_putnbr_fd(current->x, 2);
			ft_putchar_fd(' ', 2);
			current = current->nxt;
		}
		ft_putnbr_fd(current->x, 2);
	}
	else
		ft_putstr_fd("<empty>", 2);
	ft_putchar_fd('\n', 2);
}
