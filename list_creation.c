/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_creation.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/04 11:21:23 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/07 17:43:50 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "list_structure.h"
#include "prototypes_shared.h"
#include <stdlib.h>

static t_list	*lst_new(int num)
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

static void	lst_add_back(t_list **lst, t_list *new)
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

int	create_lnkd_lst(char **input, int n, t_list **list)
{
	int		i;
	int		num;
	int		unique;
	t_list	*new;

	i = 0;
	while (i < n)
	{
		num = ft_atoi(input[i]);
		unique = is_unique(*list, num);
		if (unique == 1)
			new = lst_new(num);
		if (unique == 0 || !new)
			return (-1);
		lst_add_back(list, new);
		i++;
	}
	return (1);
}
