/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 15:02:19 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/19 21:18:51 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list_operations.h"
#include "actions.h"
#include "main.h"
#include "libft/ft_printf.h"	// delete

/* these should all return a char* with instructions probably */
/* or maybe not - as we'll only test with 5 but optimisation is only for 6 */

void	sort_two(t_list **lst, char list)
{
	ft_printf("[sort_2]\n");
	if ((*lst)->x > (*lst)->nxt->x)
	{
		ft_printf("s%c\n", list);
		*lst = swap(*lst);
	}
}

void	reverse_three(t_list **lst, char list)
{
	ft_printf("s%c\n", list, list);	// OR *lst = rotate(*lst)
	*lst = swap(*lst);
	ft_printf("rr%c\n", list, list);	// OR *lst = swap(*lst)
	*lst = rev_rotate(*lst);
}

void	sort_three(t_list **lst, char list)
{
	int	max;
	int	min;
	int	sorted;

	max = lst_max(*lst);
	min = lst_min(*lst);
	sorted = is_sorted(*lst);
	if (sorted == -1)
		reverse_three(lst, list);
	if (sorted == 0 && max == (*lst)->x)
	{
		ft_printf("r%c\n", list);
		*lst = rotate(*lst);
	}
	else if (sorted == 0 && (min == (*lst)->x || min == (*lst)->prev->x))
	{
		ft_printf("rr%c\n", list);
		*lst = rev_rotate(*lst);
	}
	if (sorted == 0 && min != (*lst)->x)
	{
		ft_printf("s%c\n", list);
		*lst = swap(*lst);
	}
}

void	rev_sort_three(t_list **lst, char list)
{
	int	max;
	int	min;
	int	sorted;

	max = lst_max(*lst);
	min = lst_min(*lst);
	sorted = is_sorted(*lst);
	if (sorted == 0 && min == (*lst)->x)
	{
		ft_printf("r%c\n", list);
		*lst = rotate(*lst);
	}
	else if (sorted == 0 && (max == (*lst)->x || max == (*lst)->prev->x))
	{
		ft_printf("rr%c\n", list);
		*lst = rev_rotate(*lst);
	}
	if (sorted == 0 && max != (*lst)->x)
	{
		ft_printf("s%c\n", list);
		*lst = swap(*lst);
	}
}
