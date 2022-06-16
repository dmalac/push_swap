/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tranche_operations.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 17:26:23 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/06/16 14:54:39 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "list_operations.h"
#include "main.h"
#include "sorting.h"
#include "libft/ft_printf.h"	// delete
#include "actions.h"

void	find_nxt_elem(t_list *lst, int *tr_limits, int tr, t_nxt_step *nxt)
{
	t_list	*current;
	int		steps;
	int		size;

	current = lst;
	size = lst_size(lst);
	steps = 0;
	while ((steps <= size) && is_in_tranche(current->x, tr_limits[tr], tr_limits[tr + 1]) == 0)
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

void	add_b_stack_moves(t_tools *tools, t_nxt_step *nxt, int size_b)
{
	int	b_steps;

	if (tools->b)
		b_steps = right_place(tools->b, nxt->a_value);
	else
		b_steps = 0;
	// ft_printf("b_stack optimization: The right place for %d is %d steps R\n", nxt->a_value, b_steps);
	if ((nxt->a_dir == RX && (b_steps > (size_b - b_steps + nxt->a_steps))) \
	|| (nxt->a_dir == RRX && (!(b_steps > (size_b - b_steps + nxt->a_steps)))))
	{
		nxt->b_dir = RRX;
		nxt->b_steps = size_b - b_steps;
	}
	else
	{
		nxt->b_dir = RX;
		nxt->b_steps = b_steps;
	}
	// ft_printf("Result of optimizing b_stack:\n\ta_value: %d\n\ta_steps: %d\n\ta_dir: %d\n\tb_dir: %d\n\tb_steps: %d\n\n", nxt->a_value, nxt->a_steps, nxt->a_dir, nxt->b_dir, nxt->b_steps);
}

int	larger_of_two(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

t_nxt_step	*most_efficient_move(t_tools *tools, t_nxt_step *nxt_r, t_nxt_step *nxt_rr)
{
	int	total_steps_a_r;
	int	total_steps_a_rr;
	int	size_b;

	size_b = lst_size(tools->b);
	// ft_printf("size_b = %d\n", size_b);
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
	if (total_steps_a_r < total_steps_a_rr)
		return (nxt_r);
	else
		return (nxt_rr);
}

void	go_to(t_tools *tools, int moves, int direction, char list)
{
	while (moves-- > 0)
		make_a_move(tools, direction, list);
}

void	perform(t_tools *tools, t_nxt_step *nxt)
{
	if (nxt->a_dir == nxt->b_dir)
	{
		if (nxt->a_steps > nxt->b_steps)
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
	// lst_print(tools->a, 'A');
	// lst_print(tools->b, 'B');
}
