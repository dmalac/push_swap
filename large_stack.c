/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   large_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/31 11:56:55 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/07 17:45:55 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "prototypes_shared.h"
#include <stdlib.h>

int	find_top_b(t_list *lst)
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

static void	move_tranche_to_b(t_tools *tools, int *tr_limits, int tr)
{
	t_nxt_move	nxt_r;
	t_nxt_move	nxt_rr;
	t_nxt_move	*winner;

	nxt_r.a_dir = RX;
	nxt_rr.a_dir = RRX;
	nxt_r.a_steps = 0;
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

	i = 0;
	tr_limits = get_limits(tools->a, tools->tranches);
	if (!tr_limits)
		call_error(tools);
	while (i < tools->tranches && tools->a)
		move_tranche_to_b(tools, tr_limits, i++);
	move_to_the_top(tools, 'b');
	offload(tools, lst_size(tools->b), 'a');
	free(tr_limits);
}
