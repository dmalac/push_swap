/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_checks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 17:37:05 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/19 11:41:03 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "../include/list_structure.h"
#include "../libft/libft.h"

int	only_digits(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_unique(t_list *lst, int num)
{
	while (lst && lst->is_last == 0)
	{
		if (lst->x == num)
			return (0);
		lst = lst->nxt;
	}
	if (lst && lst->x == num)
		return (0);
	return (1);
}

int	is_int(char *num)
{
	long long	number;

	number = ft_atol(num);
	if (number <= INT_MAX && number >= INT_MIN)
		return (1);
	else
		return (0);
}

int	is_sorted(t_list *lst)
{
	int		sorted;
	t_list	*current;

	current = lst;
	if (current->x > current->nxt->x)
		sorted = -1;
	else
		sorted = 1;
	while (current->is_last != 1)
	{
		if ((current->x > current->nxt->x && sorted == 1) || \
		(current->x < current->nxt->x && sorted == -1))
			return (0);
		current = current->nxt;
	}
	return (sorted);
}
