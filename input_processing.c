/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_processing.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 17:37:05 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/05 18:18:20 by dmalacov      ########   odam.nl         */
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

int	no_doubles()
{
	return (1);
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

void	check_input(char **input, int num)
{
	int	i;

	i = 1;
	while (i < num)
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
	// if (no_doubles() == 0)		-> include AFTER creating linked list
	// 	call_error();
}

void	process_input(char **input, int num, t_list **a)
{
	int		i;
	t_list	*new;

	i = 1;
	while (i < num)
	{
		new = lst_new(input[i]);
		if (!new)
			lst_erase(a);
		lst_add_back(a, new);
		i++;
	}
}
