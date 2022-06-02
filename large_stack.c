/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   large_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/31 11:56:55 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/06/02 20:38:47 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list_operations.h"
#include "main.h"
#include "sorting.h"
#include "libft/ft_printf.h"	// delete

int	is_in_tranche(int x, int tr_min, int tr_max)
{
	if (x >= tr_min && x <= tr_max)
		return (1);
	else
		return (0);
}

void	sort_list(int *list, int size)
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

int	*clone_list(t_list *lst)
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

int	*get_limits(t_list *lst)
{
	int	*tr_limits;
	int	*list;
	int	i;
	int	n;
	int	tr_size;

	n = lst_size(lst);
	list = clone_list(lst);	// protected below
	i = 0;
	ft_printf("List array: ");
	while (i < n)
		ft_printf("%d, ", list[i++]);
	ft_printf("\n");
	tr_limits = malloc(sizeof(int) * (TRANCHES + 1));
	if (!tr_limits || !list)
		return (NULL);
	tr_size = n / TRANCHES;
	i = -1;
	while (++i < TRANCHES)
		tr_limits[i] = list[i * tr_size];
	tr_limits[i] = list[n - 1];
	ft_printf("Tranche limits are: ");
	while (i >= 0)
		ft_printf("%d | ", tr_limits[TRANCHES - i--]);
	ft_printf("\n");
	free(list);
	return (tr_limits);
}

void	sort_large_stack(t_tools *tools)
{
	int	*tr_limits;
	int	i;

	i = 0;
	tr_limits = get_limits(tools->a);	// could be NULL
	if (!tr_limits)
		call_error();	// do I need to free malloc'ed stuff?
	while (i < TRANCHES)
		move_tranche_to_b(tools, tr_limits, i++);
	free(tr_limits);
}
