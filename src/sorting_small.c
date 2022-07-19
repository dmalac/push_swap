/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_small.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 15:02:19 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/19 11:40:20 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"
#include "../include/prototypes_shared.h"

void	sort_two(t_tools *tools, char list)
{
	t_list	**lst;

	lst = get_list(&tools->a, &tools->b, list);
	if ((*lst)->x > (*lst)->nxt->x)
		make_a_move(tools, SX, list);
}

static void	reverse_three(t_tools *tools, char list)
{
	make_a_move(tools, SX, list);
	make_a_move(tools, RRX, list);
}

void	sort_three(t_tools *tools, char list)
{
	int		max;
	int		min;
	int		sorted;
	t_list	**lst;

	lst = get_list(&tools->a, &tools->b, list);
	max = lst_max(*lst);
	min = lst_min(*lst);
	sorted = is_sorted(*lst);
	if (sorted == -1)
		reverse_three(tools, list);
	if (sorted == 0 && max == (*lst)->x)
		make_a_move(tools, RX, list);
	else if (sorted == 0 && (min == (*lst)->x || min == (*lst)->prev->x))
		make_a_move(tools, RRX, list);
	if (sorted == 0 && min != (*lst)->x)
		make_a_move(tools, SX, list);
}

void	rev_sort_three(t_tools *tools, char list)
{
	int		max;
	int		min;
	int		sorted;
	t_list	**lst;

	lst = get_list(&tools->a, &tools->b, list);
	max = lst_max(*lst);
	min = lst_min(*lst);
	sorted = is_sorted(*lst);
	if (sorted == 0 && min == (*lst)->x)
		make_a_move(tools, RX, list);
	else if (sorted == 0 && (max == (*lst)->x || max == (*lst)->prev->x))
		make_a_move(tools, RRX, list);
	if (sorted == 0 && max != (*lst)->x)
		make_a_move(tools, SX, list);
}
