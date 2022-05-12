/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_processing.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 17:37:05 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/12 11:31:45 by dmalacov      ########   odam.nl         */
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

int	doubles(t_list *lst, int n)
{
	int		i;
	int		counter;
	t_list	*val_1;
	t_list	*val_2;

	i = 0;
	while (i < n)
	{
	counter = 0;
	val_1 = lst;
		while (counter < i)
		{
			val_1 = val_1->nxt;
			counter++;
		}
		val_2 = val_1->nxt;
		while (val_2->prev->is_last != 1)
		{
			if (val_1->x == val_2->x)
				return (1);
			val_2 = val_2->nxt;
		}
	i++;
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

void	check_input(char **input, int n)
{
	int	i;

	i = 1;
	while (i < n)
	{
		if (only_digits(input[i]) == 0)
			call_error();
		if (ft_strlen(input[i]) >= 10)
		{
			if (is_int(input[i]) == 0)
				call_error();
		}
		i++;
	}
}
