/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_processing.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 17:37:05 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/04 18:41:57 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "main.h"
#include "libft/libft.h"

int	only_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	no_doubles(int *input) // will get an array as input
{
	int	i;

	i = 0;
	if (input == NULL)		// this is nonsense
		return (1);
	return (1);
}

int	*check_input(char **arg, int num)
{	// 1. isdigit, 2. ints, 3. make array&atoi, 4. doubles
	int	*input;	// ARRAY IS NOT WORKING
	int	i;

	i = 0;
	while (i < num)
	{
		if (only_digits(arg[i + 1]) == 0)
			call_error();
		// here also check whether min/max int - with strcmp perhaps
		i++;
	}
	input = malloc(sizeof(int) * num);
	if (!input)
		call_error();
	ft_bzero(input, num);
	i = 1;
	while (i < num)
	{
		*(input + i) = ft_atoi(arg[i]);
		i++;
	}
	if (no_doubles(input) == 0)
		call_error();
	return (input);
}

void	process_input(int *input, int num, t_list **a)
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
