/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_operations.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 14:26:52 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/06/30 18:52:34 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list_manipulation.h"
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

void	go_to(t_tools *tools, int moves, int direction, char list)
{
	while (moves-- > 0)
		make_a_move(tools, direction, list);
}

void	move_to_the_top(t_tools *tools, char list)	// TO BE TESTED!!
{
	int		size_lst;
	int		moves_to_top;
	t_list	**lst;
	
	lst = get_list(tools, list);
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