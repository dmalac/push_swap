/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 14:26:52 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/12 18:28:51 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list_operations.h"
#include "sorting.h"
#include "libft/ft_printf.h"	// delete

t_list	*offload(t_list **to, t_list **from, int n)
{
	while (n > 0)
	{
		*from = push(to, from);
		n--;
	}
	return (*from);
}

void	sort_small_stack(t_list **a, t_list **b)
{
	int	size_a;
	int	size_b;

	size_a = lst_size(*a);
	if (size_a == 2)
		sort_two(a);
	if (size_a == 3)
		sort_three(a);
	
	if (size_a > 3)
	{
		*a = offload(b, a, size_a - 3);
		size_b = lst_size(*b);
	}
	// size_a
	// offload if necessary
	// perform_fc(a, array[size_a])
	// if b, perform_fc(b, array[size_b])
}