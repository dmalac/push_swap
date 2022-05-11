/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 14:26:52 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/11 16:53:23 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list_operations.h"
#include "sorting.h"
#include "libft/ft_printf.h"	// delete

void	sort_small_stack(t_list *a, t_list *b)
{
	int	size_a;
	int	size_b;

	size_a = lst_size(a);	// doesn't work (1 instead of 3)
	// if (size_a <= 3)
	// 	sort_two_three(a);
	size_b = lst_size(b);
	ft_printf("List a has %d items and list b has %d items.\n", size_a, size_b);
}