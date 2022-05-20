/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 15:02:19 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/20 16:42:46 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list_operations.h"
#include "actions.h"
#include "main.h"
#include "libft/ft_printf.h"	// delete

/* these should all return a char* with instructions probably */
/* or maybe not - as we'll only test with 5 but optimisation is only for 6 */

t_list	*get_list(t_tools tools, char list)
{
	t_list	*lst;
	
	if (list == 'a')
		lst = *tools.a;
	else
		lst = *tools.b;
	return (lst);
}

void	sort_two(t_tools tools, char list)
{
	t_list	*lst;

	lst = get_list(tools, list);
	if (lst->x > lst->nxt->x)
	{
		make_a_move(tools, SX, list);
		// ft_printf("s%c\n", list);
		// *lst = swap(*lst);
	}
}

static void	reverse_three(t_tools tools, char list)
{
	t_list	*lst;

	lst = get_list(tools, list);
	make_a_move(tools, SX, list);
	// ft_printf("s%c\n", list, list);	// OR *lst = rotate(*lst)
	// *lst = swap(*lst);
	make_a_move(tools, RRX, list);
	// ft_printf("rr%c\n", list, list);	// OR *lst = swap(*lst)
	// *lst = rev_rotate(*lst);
}

void	sort_three(t_tools tools, char list)
{
	int		max;
	int		min;
	int		sorted;
	t_list	*lst;

	lst = get_list(tools, list);
	max = lst_max(lst);
	min = lst_min(lst);
	sorted = is_sorted(lst);
	if (sorted == -1)
		reverse_three(tools, list);
	if (sorted == 0 && max == lst->x)
	{
		make_a_move(tools, RX, list);
		// ft_printf("r%c\n", list);
		// *lst = rotate(*lst);
	}
	else if (sorted == 0 && (min == lst->x || min == lst->prev->x))
	{
		make_a_move(tools, RRX, list);
		// ft_printf("rr%c\n", list);
		// *lst = rev_rotate(*lst);
	}
	if (sorted == 0 && min != lst->x)
	{
		make_a_move(tools, SX, list);
		// ft_printf("s%c\n", list);
		// *lst = swap(*lst);
	}
}

void	rev_sort_three(t_tools tools, char list)
{
	int		max;
	int		min;
	int		sorted;
	t_list	*lst;

	lst = get_list(tools, list);
	max = lst_max(lst);
	min = lst_min(lst);
	sorted = is_sorted(lst);
	if (sorted == 0 && min == lst->x)
	{
		// ft_printf("r%c\n", list);
		// *lst = rotate(*lst);
	}
	else if (sorted == 0 && (max == lst->x || max == lst->prev->x))
	{
		// ft_printf("rr%c\n", list);
		// *lst = rev_rotate(*lst);
	}
	if (sorted == 0 && max != lst->x)
	{
		// ft_printf("s%c\n", list);
		// *lst = swap(*lst);
	}
}
