/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   large_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/31 11:56:55 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/31 18:16:00 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list_operations.h"
#include "main.h"
#include "libft/ft_printf.h"	// delete

// TO BE REWORKED SO THAT COUNTING THE MOVES WORKS

int	is_in_tranche(int x, int tr_min, int tr_max)
{
	if (x >= tr_min && x <= tr_max)
		return (1);
	else
		return (0);
}

int	get_tr_min(t_list lst, int i)
{
	int	tr_min;
	int	max;
	int	min;

	max = lst_max(&lst);
	min = lst_min(&lst);
	tr_min = min + i * (max - min) / 3;	// what if floats?
	return (tr_min);
}

int	get_tr_max(t_list lst, int i)
{
	int	tr_max;
	int	max;
	int	min;

	max = lst_max(&lst);
	min = lst_min(&lst);
	tr_max = min + (i + 1) * (max - min) / 3 - 1;
	if (i == TRANCHES)
		tr_max++;
	return (tr_max);
}

int	moves_to_next(t_list *lst, int tr_min, int tr_max, int beyond_tranche)
{
	t_list	*current_r;
	t_list	*current_rr;
	int		next;
	int		i;
	int		n;

	n = lst_size(lst);	// doesn't work
	i = -1;
	current_r = lst;
	while (++i < n && is_in_tranche(current_r->x, tr_min, tr_max) == 0)
		current_r = current_r->nxt;
	if (i == n)
		return (-1);
	next = i;
	i = -1;
	current_rr = lst;
	while (++i < n && is_in_tranche(current_rr->x, tr_min, tr_max) == 0)
		current_rr = current_rr->prev;
	if (i < next)
	{
		next = i;
		lst = current_rr;
	}
	else
		lst = current_r;
	lst->x = beyond_tranche;
	return (next);
}

int	count_moves(t_list lst, int tr_min, int tr_max)
{
	int	moves;
	int	next;
	int beyond_tranche;

	next = 0;
	moves = 0;
	if (tr_min > INT_MIN)
		beyond_tranche = tr_min - 1;
	else
		beyond_tranche = tr_max + 1;
	while (next >= 0)
	{
		moves += next;
		next = moves_to_next(&lst, tr_min, tr_max, beyond_tranche);
	}
	return (moves);
}

void	sort_large_stack(t_tools *tools)
{
	int	moves_per_tranche[10];
	int	i;
	int	tr_min;
	int tr_max;

	i = 0;
	while (i < TRANCHES)
	{
		tr_min = get_tr_min(*tools->a, i);
		tr_max = get_tr_max(*tools->a, i);
		moves_per_tranche[i] = count_moves(*tools->a, tr_min, tr_max);
		i++;
	}
	i = 0;
	while (i < TRANCHES)
	{
		ft_printf("tranche %d: %d moves\n", i + 1, moves_per_tranche[i]);
		i++;
	}
}