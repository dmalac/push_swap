/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_creation.c                                    :+:    :+:            */
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

void	lst_add_back(t_list **lst, t_list *new)
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
		top->prev->is_last = 0;
		new->prev = top->prev;
		top->prev = new;
		new->nxt = top;
		new->prev->nxt = new;
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

	i = 0;
	while (i < n)
	{
		new = lst_new(input[i]);
		if (!new)
		{
			lst_erase(a);
			exit(0);
		}
		lst_add_back(a, new);
		i++;
	}
}
