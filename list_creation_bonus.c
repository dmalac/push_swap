/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_creation_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/04 11:21:23 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/06 18:38:16 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "main_bonus.h"
#include <stdlib.h>

t_list	*lst_new(int num)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new)
	{
		new->x = num;
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

void	create_lnkd_lst(char **input, int n, t_tools *tools)
{
	int		i;
	int		num;
	int		unique;
	t_list	*new;

	i = 0;
	while (i < n)
	{
		num = ft_atoi(input[i]);
		unique = is_unique(tools->a, num);
		if (unique == 1)
			new = lst_new(num);
		if (unique == 0 || !new)
			call_error(tools);
		lst_add_back(&tools->a, new);
		i++;
	}
}
