/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   large_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/31 11:56:55 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/06/16 14:58:56 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list_operations.h"
#include "main.h"
#include "sorting.h"
#include "libft/ft_printf.h"	// delete
#include "actions.h"

static int	find_top_b(t_list *lst)
{
	int	count;

	count = 0;
	while (lst && lst->prev->x > lst->x)
	{
		lst = lst->nxt;
		count++;
	}
	return (count);
}

int	right_place(t_list *b, int x)
{
	t_list	*current;
	int		steps;
	int		max;
	int		min;

	if (!b)
		return (0);
	current = b;
	max = lst_max(b);
	min = lst_min(b);
	steps = 0;
	if (x > max || x < min)
		return (find_top_b(b));
	while (!(x > current->x && x < current->prev->x))
	{
		current = current->nxt;
		steps++;
	}
	return (steps);
}

void	move_tranche_to_b(t_tools *tools, int *tr_limits, int tr)
{
	t_nxt_step	nxt_r;
	t_nxt_step	nxt_rr;
	t_nxt_step	*winner;

	nxt_r.a_dir = RX;
	nxt_r.a_steps = 0;
	nxt_rr.a_dir = RRX;
	while (tools->a && (nxt_r.a_steps >= 0 || nxt_rr.a_steps >= 0))
	{		
		find_nxt_elem(tools->a, tr_limits, tr, &nxt_r);
		find_nxt_elem(tools->a, tr_limits, tr, &nxt_rr);
		if (nxt_r.a_steps >= 0)
		{
			winner = most_efficient_move(tools, &nxt_r, &nxt_rr);
			perform(tools, winner);
			if (lst_size(tools->b) == 2 && tools->b->x < tools->b->nxt->x)
				make_a_move(tools, SX, 'b');
		}
	}
}

void	sort_large_stack(t_tools *tools)
{
	int	*tr_limits;
	int	i;
	int	moves_to_top;
	int	size_b;

	i = 0;
	tr_limits = get_limits(tools->a);	// could be NULL
	if (!tr_limits)
		call_error();	// do I need to free malloc'ed stuff?
	while (i < TRANCHES && tools->a)
		move_tranche_to_b(tools, tr_limits, i++);
	moves_to_top = find_top_b(tools->b);
	size_b = lst_size(tools->b);
	if (moves_to_top > size_b)
		go_to(tools, moves_to_top, RX, 'b');
	else
		go_to(tools, size_b - moves_to_top, RRX, 'b');
	offload(tools, lst_size(tools->b), 'a');
	free(tr_limits);
}
