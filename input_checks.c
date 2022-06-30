/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_checks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 17:37:05 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/06/30 16:03:57 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "main.h"
#include "libft/libft.h"

int	only_digits(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	are_there_doubles(t_list *lst)
{
	t_list	*val_1;
	t_list	*val_2;

	val_1 = lst;
	while (val_1->is_last != 1)
	{
		val_2 = val_1->nxt;
		while (val_2->prev->is_last != 1)
		{
			if (val_1->x == val_2->x)
				return (1);
			val_2 = val_2->nxt;
		}
		val_1 = val_1->nxt;
	}
	return (0);
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
