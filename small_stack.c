/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 14:26:52 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/06/16 14:52:17 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list_operations.h"
#include "sorting.h"
#include "actions.h"
#include "main.h"
#include "libft/ft_printf.h"	// delete

void	offload(t_tools *tools, int n, char dest)
{
	t_list	**from;

	if (dest == 'a')
	{
		from = &tools->b;
		while (n-- > 0)
			make_a_move(tools, PX, dest);
	}
	else
	{
		from = &tools->a;
		while (n-- > 0 && is_sorted(*from) != 1)
			make_a_move(tools, PX, dest);
	}
}

static int	find_top_a(t_list *lst)
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

static int	belongs_to(t_list *a, t_list *b)	//HANDLE EMPTY LIST & 1 ITEM
{
	int	right_place;
	int	max;
	int	min;

	right_place = 0;
	max = lst_max(a);
	min = lst_min(a);
	if (b->x > max || b->x < min)
		return (find_top_a(a));
	else
	{
		while (!(b->x < a->x && b->x > a->prev->x))
		{
			a = a->nxt;
			right_place++;
		}
		return (right_place);
	}
}

void	get_to_the_place(t_tools *tools, int moves, char list)	// REPLACE BY FC go_to
{
	t_list	**lst;
	int		size_lst;

	// to be simplified: while moves > 0, make_a_move(tools, dir, list)
	lst = get_list(tools, list);
	size_lst = lst_size(*lst);
	if (moves > 0 && moves <= size_lst / 2)
	{
		while (moves > 0)
		{
			make_a_move(tools, RX, list);
			moves--;
		}
	}
	else if (moves > 0)
	{
		while (size_lst - moves > 0)
		{
			make_a_move(tools, RRX, list);
			moves++;
		}
	}
}

void	merge_b_into_a(t_tools *tools)
{
	int	size_a;
	int	size_b;
	int	right_place;

	size_b = lst_size(tools->b);
	while (size_b > 0)
	{
		size_a = lst_size(tools->a);
		right_place = belongs_to(tools->a, tools->b);
		get_to_the_place(tools, right_place, 'a');
		make_a_move(tools, PX, 'a');
		if ((tools->a)->x > (tools->a)->nxt->x && (tools->b == NULL || \
		(tools->a)->x < (tools->b)->x))
			make_a_move(tools, RX, 'a');
		size_b = lst_size(tools->b);
	}
	size_a = lst_size(tools->a);
	right_place = find_top_a(tools->a);
	// if right_place > n / 2 --> get_to_the_place(tools, n - right_place, RR, 'a');
	get_to_the_place(tools, right_place, 'a'); // R
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
