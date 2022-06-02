/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_large.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 19:43:54 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/06/02 20:40:44 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list_operations.h"
#include "actions.h"
#include "main.h"
#include "sorting.h"

void	move_tranche_to_b(t_tools *tools, int *tr_limits, int tr)
{
	int		count;
	int		n;
	t_list	*fwd;
	t_list	*rev;

	n = lst_size(tools->a);
	count = 0;
	fwd = tools->a;
	rev = tools->a;
	while (count < n)	// && is_sorted(tools->a < 1 (or != 0 and rev sort if -1))
	{
		if (is_in_tranche(fwd->x, tr_limits[tr], tr_limits[tr + 1]) == 1 || \
		is_in_tranche(rev->x, tr_limits[tr], tr_limits[tr + 1]) == 1)
		{
			if (is_in_tranche(fwd->x, tr_limits[tr], tr_limits[tr + 1]) == 1)
				get_to_the_place(tools, count, 'a');
			else
				get_to_the_place(tools, n - count, 'a');
			// prepare b for reception
			make_a_move(tools, PX, 'b');
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
