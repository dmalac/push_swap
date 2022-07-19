/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_operations.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/04 11:21:23 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/19 10:36:32 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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

size_t	lst_size(t_list *lst)
{
	size_t	size;
	t_list	*current;

	if (lst == NULL)
		return (0);
	size = 1;
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

t_list	**get_list(t_list **a, t_list **b, char list)
{
	t_list	**lst;

	if (list == 'a')
		lst = a;
	else
		lst = b;
	return (lst);
}
