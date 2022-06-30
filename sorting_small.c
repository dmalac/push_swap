/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_small.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 15:02:19 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/06/30 16:22:28 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list_manipulation.h"
#include "actions.h"
#include "main.h"
#include "libft/ft_printf.h"	// delete

t_list	**get_list(t_tools *tools, char list)
{
	t_list	**lst;

	if (list == 'a')
		lst = &tools->a;
	else
		lst = &tools->b;
	return (lst);
}

void	sort_two(t_tools *tools, char list)
{
	t_list	**lst;

	lst = get_list(tools, list);
	if ((*lst)->x > (*lst)->nxt->x)
		make_a_move(tools, SX, list);
}

static void	reverse_three(t_tools *tools, char list)
{
	t_list	**lst;

	lst = get_list(tools, list);
	make_a_move(tools, SX, list);
	make_a_move(tools, RRX, list);
}

void	sort_three(t_tools *tools, char list)
{
	int		max;
	int		min;
	int		sorted;
	t_list	**lst;

	lst = get_list(tools, list);
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

	lst = get_list(tools, list);
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
