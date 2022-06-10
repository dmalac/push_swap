/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   large_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/31 11:56:55 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/06/08 13:48:53 by dmalacov      ########   odam.nl         */
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
	while (lst->prev->x > lst->x)
	{
		lst = lst->nxt;
		count++;
	}
	return (count);
}

static int	belongs_to(t_list *b, t_list *a) //HANDLE 1 ITEM
{
	int	right_place;
	int	max;
	int	min;

	right_place = 0;
	max = lst_max(b);
	min = lst_min(b);
	if (a->x > max || a->x < min)
		return (find_top_b(b));
	else
	{
		while (!(a->x > b->x && a->x < b->prev->x))
		{
			b = b->nxt;
			right_place++;
		}
		return (right_place);
	}
}

void	move_tranche_to_b(t_tools *tools, int *tr_limits, int tr)
{
	int		count;
	int		n;
	t_list	*fwd;
	t_list	*rev;
	int		right_place;

	n = lst_size(tools->a);
	count = 0;
	fwd = tools->a;
	rev = tools->a;
	while (count < n)	// && is_sorted(tools->a < 1 (or != 0 and rev sort if -1))
	{
		if (is_in_tranche(fwd->x, tr_limits[tr], tr_limits[tr + 1]) == 1 || \
		is_in_tranche(rev->x, tr_limits[tr], tr_limits[tr + 1]) == 1)
		{
			/* maybe first adjust count (no get_to_place)
			   then check where it fits in b 
			   first do x RR / RRR
			   and send the [number - x] to get_to_the_place */
			if (is_in_tranche(fwd->x, tr_limits[tr], tr_limits[tr + 1]) == 1)
				get_to_the_place(tools, count, 'a');
			else
				get_to_the_place(tools, n - count, 'a');
			// prepare b for reception
			if (tools->b)
			{
				right_place = belongs_to(tools->b, tools->a);
				get_to_the_place(tools, right_place, 'b');
			}
			make_a_move(tools, PX, 'b');
			// HERE INCLUDE check if b is sorted
			if (lst_size(tools->b) == 2 && tools->b->x < tools->b->nxt->x)
				make_a_move(tools, SX, 'b');
			rev = tools->a;
			fwd = tools->a;
			count = 0;
			n--;		// or n = lst_size(tools->a) ??
		}
		else
		{
			fwd = fwd->nxt;
			rev = rev->prev;
			count++;
		}
	}
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
	get_to_the_place(tools, find_top_b(tools->b), 'b');
	offload(tools, lst_size(tools->b), 'a');
	free(tr_limits);
}
