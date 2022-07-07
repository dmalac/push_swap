/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 14:26:52 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/07 17:44:50 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "prototypes_shared.h"
#include <stdlib.h>

int	find_top_a(t_list *lst)
{
	int	count;

	count = 0;
	while (lst->prev->x < lst->x)
	{
		lst = lst->nxt;
		count++;
	}
	return (count);
}

static void	merge_b_into_a(t_tools *tools)
{
	int	size_a;
	int	size_b;
	int	right_place;

	size_b = lst_size(tools->b);
	while (size_b > 0)
	{
		size_a = lst_size(tools->a);
		right_place = belongs_to(tools->a, tools->b->x, 'a');
		if (right_place <= size_a / 2)
			go_to(tools, right_place, RX, 'a');
		else
			go_to(tools, size_a - right_place, RRX, 'a');
		make_a_move(tools, PX, 'a');
		if ((tools->a)->x > (tools->a)->nxt->x && (tools->b == NULL || \
		(tools->a)->x < (tools->b)->x))
			make_a_move(tools, RX, 'a');
		size_b = lst_size(tools->b);
	}
	move_to_the_top(tools, 'a');
}

void	sort_small_stack(t_tools *tools)
{
	int	size_a;
	int	size_b;

	size_a = lst_size(tools->a);
	if (size_a == 2)
		sort_two(tools, 'a');
	if (size_a == 3)
		sort_three(tools, 'a');
	if (size_a > 3)
	{
		offload(tools, size_a - 3, 'b');
		if (is_sorted(tools->a) < 1)
			sort_three(tools, 'a');
		size_b = lst_size(tools->b);
		if (size_b == 3)
			rev_sort_three(tools, 'b');
		merge_b_into_a(tools);
	}
}
