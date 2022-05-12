/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_operations.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/04 11:21:23 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/12 16:33:36 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list_operations.h"
#include "libft/libft.h"
#include "main.h"
#include <stdlib.h>

t_list	*lst_new(char *num)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new)
	{
		new->x = ft_atoi(num);
		new->prev = NULL;
		new->nxt = NULL;
		new->is_last = 0;
	}
	return (new);
}

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

void	lst_add_back(t_list **lst, t_list *new)
{
	t_list	*temp;
	t_list	*top;

	if (*lst == NULL)
	{
		*lst = new;
		new->nxt = new;
		new->prev = new;
		new->is_last = 1;
	}
	else
	{
		top = *lst;
		top->prev->is_last = 0;
		temp = top->prev;
		top->prev = new;
		new->nxt = top;
		temp->nxt = new;
		new->prev = temp;
		new->is_last = 1;
	}
}

t_list	*lst_add_front(t_list **lst, t_list *new)
{
	t_list	*top;

	if (*lst == NULL)
	{
		*lst = new;
		new->nxt = new;
		new->prev = new;
		new->is_last = 1;
	}
	else
	{
		top = *lst;
		new->prev = top->prev;
		top->prev = new;
		new->nxt = top;
		new->prev->nxt = new;
		if (new->is_last == 1)
			new->is_last = 0;
	}
	return (new);
}

void	create_lnkd_lst(char **input, int n, t_list **a)
{
	int		i;
	t_list	*new;

	i = 1;
	while (i < n)
	{
		new = lst_new(input[i]);
		if (!new)
			lst_erase(a);
		lst_add_back(a, new);
		i++;
	}
}

int		lst_size(t_list *lst)
{
	int		size;
	t_list	*current;

	size = 0;
	if (lst == NULL)
		return (0);
	current = lst;
	while (current->is_last == 0)
	{
		size++;
		current = current->nxt;
	}
	return (size + 1);
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
void	lst_print(t_list *top)
{
	t_list	*current;

	if (top)
	{
		current = top;
		while (current->is_last != 1)
		{
			ft_printf("%d, %d\n", current->x, current->is_last);
			current = current->nxt;
		}
		ft_printf("%d, %d\n", current->x, current->is_last);
	}
}
