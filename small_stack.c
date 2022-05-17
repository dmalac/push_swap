/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 14:26:52 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/17 14:42:09 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list_operations.h"
#include "sorting.h"
#include "actions.h"
#include "libft/ft_printf.h"	// delete

static t_list	*offload(t_list **to, t_list **from, int n, char dest)
{
	while (n > 0)
	{
		ft_printf("p%c\n", dest);
		*from = push(to, from);
		n--;
	}
	return (*from);
}

static int	belongs_to(t_list *a, t_list*b)	// TO BE CODED
{
	int	position;

	position = 0;
	// compare with current and previous, then rotate until it fits between them
	return (position);
}

t_list	*get_to_the_place(t_list *(*f)(t_list*), t_list **a, int moves)
{
	t_list *current;

	current = *a;
	while (moves > 0)
	{
		ft_printf("rotation - specs to be added\n");
		current = f(current);
		moves--;
	}
	return (current);
}

t_list	*get_to_top(t_list **a)
{
	int		from_top;
	int		size_a;
	t_list	*current;

	from_top = 0;
	size_a = lst_size(*a);
	current = *a;
	while (current->x > current->prev->x && current->x < current->nxt->x)
	{
		from_top++;
		current = current->prev;
	}
	if (from_top > 0 && from_top <= size_a / 2)
		current = get_to_the_place(rev_rotate, a, from_top);
	else if (from_top > 0 && from_top > size_a / 2)
		current = get_to_the_place(rotate, a, size_a - from_top);
	return (current);
}

static void	merge_b_into_a(t_list **a, t_list **b)
{
	int	size_a;
	int	size_b;
	int	right_place;
	
	size_b = lst_size(*b);
	while (size_b > 0)
	{
		size_a = lst_size(*a);
		right_place = belongs_to(*a, *b);
		if (right_place > 0 && right_place <= size_a / 2)
			*a = get_to_the_place(rotate, a, right_place);
		if (right_place < size_a && right_place > size_a / 2)	// maybe not < size_a
			*a = get_to_the_place(rev_rotate, a, size_a - right_place);
		ft_printf("pa\n");
		*a = push(a, b);
		size_b -= 1;		// or use lstsize?
	}
	
		// get to the top of a again
}

void	sort_small_stack(t_list **a, t_list **b)
{
	int	size_a;
	int	size_b;

	size_a = lst_size(*a);
	if (size_a == 2)
		sort_two(a, 'a');
	if (size_a == 3)
		sort_three(a, 'a');
	
	if (size_a > 3)
	{
		*a = offload(b, a, size_a - 3, 'b');
		sort_three(a, 'a');
		size_b = lst_size(*b);
		if (size_b == 3)
			rev_sort_three(b, 'b');
		merge_b_into_a(a, b);
	}
	// size_a
	// offload if necessary
	// perform_functionc(a, array[size_a])
	// if b, perform_function(b, array[size_b])
}