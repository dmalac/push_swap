/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 15:02:19 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/12 18:14:35 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list_operations.h"
#include "actions.h"
#include "main.h"
#include "libft/ft_printf.h"	// delete

/* these should all return a char* with instructions probably */

void	sort_two(t_list **lst)
{
	ft_printf("[sort_2]\n");
	if ((*lst)->x > (*lst)->nxt->x)
		*lst = swap(*lst);
}

void	sort_three(t_list **lst)
{
	int	max;
	int	min;
	int	sorted;

	max = lst_max(*lst);
	min = lst_min(*lst);
	sorted = is_sorted(*lst);	
	// ft_printf("[sort_3] max is %d, min is %d\n", max, min);
	if (sorted == -1)
	{
		// EITHER:
		ft_printf("swap\n");
		*lst = swap(*lst);
		ft_printf("rev rotate\n");
		*lst = rev_rotate(*lst);
		// lst_print(*lst);
		// OR:
		// *lst = rotate(*lst);
		// *lst = swap(*lst);
	}
	if (sorted == 0 && max == (*lst)->x)
	{
		ft_printf("rotate\n");
		*lst = rotate(*lst);
		// lst_print(*lst);
	}
	else if (sorted == 0 && (min == (*lst)->x || min == (*lst)->prev->x))
	{
		// ft_printf("lst->x %d, lst->prev->x %d\n", (*lst)->x, (*lst)->prev->x);
		ft_printf("rev rotate\n");
		*lst = rev_rotate(*lst);
		// lst_print(*lst);
	}
	if (sorted == 0 && min != (*lst)->x)
	{
		ft_printf("swap\n");
		*lst = swap(*lst);
		// lst_print(*lst);
	}
}

// void	rev_sort_three(t_list **lst)
// {
	
// }