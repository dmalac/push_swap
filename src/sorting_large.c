/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_large.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/05 16:57:40 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/19 11:40:16 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"
#include "../include/prototypes_shared.h"
#include <stdlib.h>

void	find_nxt_elem(t_list *lst, int *tr_limits, int tr, t_nxt_move *nxt)
{
	t_list	*current;
	int		steps;
	int		size;

	current = lst;
	size = lst_size(lst);
	steps = 0;
	while ((steps <= size) && is_in_tranche(current->x, tr_limits[tr], \
	tr_limits[tr + 1]) == 0)
	{
		steps++;
		if (nxt->a_dir == RX)
			current = current->nxt;
		else
			current = current->prev;
	}
	if (steps > size)
		nxt->a_steps = -1;
	else
	{
		nxt->a_steps = steps;
		nxt->a_value = current->x;
	}
}

static int	larger_of_two(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

static void	add_b_stack_moves(t_tools *tools, t_nxt_move *nxt, int size_b)
{
	int	b_steps_r;
	int	b_steps_rr;

	b_steps_r = belongs_to(tools->b, nxt->a_value, 'b');
	if (b_steps_r == 0)
		b_steps_rr = 0;
	else
		b_steps_rr = size_b - b_steps_r;
	if (nxt->a_dir == RX && (larger_of_two(nxt->a_steps, b_steps_r) > \
	(nxt->a_steps + b_steps_rr)))
		nxt->b_dir = RRX;
	else if (nxt->a_dir == RRX && (larger_of_two(nxt->a_steps, b_steps_rr) > \
	(nxt->a_steps + b_steps_r)))
		nxt->b_dir = RX;
	else
		nxt->b_dir = nxt->a_dir;
	if (nxt->b_dir == RX)
		nxt->b_steps = b_steps_r;
	else
		nxt->b_steps = b_steps_rr;
}

t_nxt_move	*most_efficient_move(t_tools *tools, t_nxt_move *nxt_r, \
t_nxt_move *nxt_rr)
{
	int	total_steps_a_r;
	int	total_steps_a_rr;
	int	size_b;

	size_b = lst_size(tools->b);
	add_b_stack_moves(tools, nxt_r, size_b);
	add_b_stack_moves(tools, nxt_rr, size_b);
	if (nxt_r->a_dir == nxt_r->b_dir)
		total_steps_a_r = larger_of_two(nxt_r->a_steps, nxt_r->b_steps);
	else
		total_steps_a_r = nxt_r->a_steps + nxt_r->b_steps;
	if (nxt_rr->a_dir == nxt_rr->b_dir)
		total_steps_a_rr = larger_of_two(nxt_rr->a_steps, nxt_rr->b_steps);
	else
		total_steps_a_rr = nxt_rr->a_steps + nxt_rr->b_steps;
	if (total_steps_a_r <= total_steps_a_rr)
		return (nxt_r);
	else
		return (nxt_rr);
}

void	perform(t_tools *tools, t_nxt_move *nxt)
{
	if (nxt->a_dir == nxt->b_dir)
	{
		if (nxt->a_steps >= nxt->b_steps)
		{
			go_to(tools, nxt->b_steps, nxt->a_dir + 1, 'r');
			go_to(tools, nxt->a_steps - nxt->b_steps, nxt->a_dir, 'a');
		}
		else
		{
			go_to(tools, nxt->a_steps, nxt->b_dir + 1, 'r');
			go_to(tools, nxt->b_steps - nxt->a_steps, nxt->b_dir, 'b');
		}
	}
	else
	{
		go_to(tools, nxt->a_steps, nxt->a_dir, 'a');
		go_to(tools, nxt->b_steps, nxt->b_dir, 'b');
	}
	make_a_move(tools, PX, 'b');
}
