/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_operations.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 14:26:52 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/07 17:46:22 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "main.h"
#include "prototypes_shared.h"


void	make_a_move(t_tools *tools, int action_code, char stack)
{
	t_list	**lst;

	lst = get_list(&tools->a, &tools->b, stack);
	if (action_code == PX)
	{
		ft_printf("%s%c\n", tools->instruction[action_code], stack);
		if (stack == 'a')
			push(&tools->a, &tools->b);
		else
			push(&tools->b, &tools->a);
	}
	else if (action_code > 0 && action_code % 2 > 0)
	{
		ft_printf("%s%c\n", tools->instruction[action_code], stack);
		tools->action[action_code](lst);
	}
	else if (action_code > 0 && action_code % 2 == 0)
	{
		ft_printf("%s%c\n", tools->instruction[action_code], stack);
		tools->action[action_code](&tools->a);
		tools->action[action_code](&tools->b);
	}
}

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

void	go_to(t_tools *tools, int moves, int direction, char list)
{
	while (moves-- > 0)
		make_a_move(tools, direction, list);
}

void	move_to_the_top(t_tools *tools, char list)
{
	int		size_lst;
	int		moves_to_top;
	t_list	**lst;

	lst = get_list(&tools->a, &tools->b, list);
	size_lst = lst_size(*lst);
	if (list == 'a')
		moves_to_top = find_top_a(*lst);
	else
		moves_to_top = find_top_b(*lst);
	if (moves_to_top <= size_lst / 2)
		go_to(tools, moves_to_top, RX, list);
	else
		go_to(tools, size_lst - moves_to_top, RRX, list);
}

int	belongs_to(t_list *lst, int x, char list)
{
	int		steps;
	int		max;
	int		min;

	if (!lst)
		return (0);
	steps = 0;
	max = lst_max(lst);
	min = lst_min(lst);
	if (list == 'a')
	{
		if (x > max || x < min)
			return (find_top_a(lst));
		while (!(x < lst->x && x > lst->prev->x) && (steps++ >= 0))
			lst = lst->nxt;
	}
	else
	{
		if (x > max || x < min)
			return (find_top_b(lst));
		while (!(x > lst->x && x < lst->prev->x) && (steps++ >= 0))
			lst = lst->nxt;
	}
	return (steps);
}
