/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_processing.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 17:37:05 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/06 13:12:39 by dmalacov      ########   odam.nl         */
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
		while (val_2->prev->last != 1)
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
	size_t	n;

	n = ft_strlen(num);
	if (num[0] == '-')
		n--;
	if (n > 10)
		return (0);
	else if (ft_strncmp(INT_MAX_CHAR, num, n) < 0 && num[0] != '-')
		return (0);
	else if (ft_strncmp(INT_MIN_CHAR, num, n) < 0 && num[0] == '-')
		return (0);
	else
		return (1);
}

void	check_input(char **input, int n)
{
	int	i;

	i = 1;
	while (i < n)
	{
		if (only_digits(input[i]) == 0)
			call_error();
		if ((input[i][0] == '-' && ft_strlen(input[i]) >= 11) || \
		(input[i][0] != '-' && ft_strlen(input[i]) >= 10))
		{
			if (is_int(input[i]) == 0)
				call_error();
		}
		i++;
	}
}

void	create_lnkd_lst(char **input, int n, t_list **a)
{
	int		i;
	t_list	*new;

	i = 1;
	while (i < n)
	{
		new = lst_new(input[i]);
		if (!new)
			lst_erase(a);
		lst_add_back(a, new);
		i++;
	}
}
