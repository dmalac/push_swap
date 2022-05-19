/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 14:26:52 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/19 21:16:43 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list_operations.h"
#include "sorting.h"
#include "actions.h"
#include "main.h"
#include "libft/ft_printf.h"	// delete

static t_list	*offload(t_list **to, t_list **from, int n, char dest)
{
	while (n > 0 && is_sorted(*from) != 1)
	{
		ft_printf("p%c\n", dest);
		*from = push(to, from);
		n--;
	}
	lst_print(*from, 'A');
	lst_print(*to, 'B');
	return (*from);
}

int	find_top(t_list *lst)
{
	int	count;

	count = 0;
	while (lst->prev->x < lst->x)
	{
		lst = lst->nxt;
		count++;
	}
	return (count);
}

static int	belongs_to(t_list *a, t_list *b)
{
	int	right_place;
	int	max;
	int	min;

	right_place = 0;
	max = lst_max(a);
	min = lst_min(a);
	if (b->x > max || b->x < min)
		return (find_top(a));
	else
	{
		while (!(b->x < a->x && b->x > a->prev->x))
		{
			a = a->nxt;
			right_place++;
		}
		return (right_place);
	}
}

t_list	*get_to_the_place(t_list **lst, int moves, char list)
{
	int	size_lst;

	size_lst = lst_size(*lst);
	if (moves > 0 && moves <= size_lst / 2)
	{
		while (moves > 0)
		{
			ft_printf("r%c\n", list);
			*lst = rotate(*lst);
			moves--;
		}
	}
	else if (moves > 0)
	{
		while (size_lst - moves > 0)
		{
			ft_printf("rr%c\n", list);
			*lst = rev_rotate(*lst);
			moves++;
		}
	}
	return (*lst);
}

static t_list	*merge_b_into_a(t_list **a, t_list **b)
{
	int	size_a;
	int	size_b;
	int	right_place;

	size_b = lst_size(*b);
	while (size_b > 0)
	{
		size_a = lst_size(*a);
		right_place = belongs_to(*a, *b);
		*a = get_to_the_place(a, right_place, 'a');
		ft_printf("pa\n");
		*b = push(a, b);
		if ((*a)->x > (*a)->nxt->x && (*b == NULL || (*a)->x < (*b)->x))
		{
			ft_printf("ra\n");
			*a = rotate(*a);
		}
		// lst_print(*a, 'A');
		// lst_print(*b, 'B');
		size_b = lst_size(*b);
	}
	size_a = lst_size(*a);
	right_place = find_top(*a);
	*a = get_to_the_place(a, right_place, 'a');
	return (*a);
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
		// lst_print(*a, 'A');
		// lst_print(*b, 'B');
		if (is_sorted(*a) < 1)
			sort_three(a, 'a');
		size_b = lst_size(*b);
		if (size_b == 3)
			rev_sort_three(b, 'b');
		*a = merge_b_into_a(a, b);
	}
}
