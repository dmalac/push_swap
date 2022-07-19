/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tranche_limits.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/08 13:21:51 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/19 11:40:30 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"
#include "../include/prototypes_shared.h"
#include <stdlib.h>

int	how_many_tranches(int num_args)
{
	if (num_args < 60)
		return (3);
	else if (num_args >= 60 && num_args < 250)
		return (7);
	else
		return (13);
}

int	is_in_tranche(int x, int tr_min, int tr_max)
{
	if (x >= tr_min && x <= tr_max)
		return (1);
	else
		return (0);
}

static void	sort_list(int *list, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (list[j] < list[i])
			{
				list[j] += list[i];
				list[i] = list[j] - list[i];
				list[j] -= list[i];
			}
			j++;
		}
		i++;
	}
}

static int	*clone_list(t_list *lst)
{
	int		*list;
	int		n;
	t_list	*current;
	int		i;

	current = lst;
	i = 0;
	n = lst_size(lst);
	list = malloc (sizeof(int) * n);
	if (!list)
		return (NULL);
	while (current->is_last != 1)
	{
		list[i++] = current->x;
		current = current->nxt;
	}
	list[i] = current->x;
	sort_list(list, n);
	return (list);
}

int	*get_limits(t_list *lst, size_t tranches)
{
	int		*tr_limits;
	int		*list;
	size_t	i;
	size_t	n;
	size_t	tr_size;

	n = lst_size(lst);
	i = 0;
	list = clone_list(lst);
	tr_limits = malloc(sizeof(int) * (tranches + 1));
	if (!tr_limits || !list)
		return (NULL);
	tr_size = n / tranches;
	i = 0;
	while (i < tranches)
	{
		tr_limits[i] = list[i * tr_size];
		i++;
	}
	tr_limits[i] = list[n - 1];
	free(list);
	return (tr_limits);
}
