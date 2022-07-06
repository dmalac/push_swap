/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_processing_bonus.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 17:37:05 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/06 18:38:29 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "main_bonus.h"
#include "libft/libft.h"

static void	check_input(char **input, int n, t_tools *tools)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (only_digits(input[i]) == 0)
			call_error(tools);
		if (ft_strlen(input[i]) >= 10 && is_int(input[i]) == 0)
			call_error(tools);
		i++;
	}
}

static int	count_input(char **array)
{
	int	count;

	count = 0;
	while (array[count])
		count++;
	return (count + 1);
}

void	process_input(char **input, int *num_args, t_tools *tools)
{
	int		allocated;
	int		i;

	allocated = 0;
	if (*num_args == 2)
	{
		input = ft_split(input[1], ' ');
		allocated = 1;
		*num_args = count_input(input);
	}
	else
		input = input + 1;
	check_input(input, *num_args - 1, tools);
	create_lnkd_lst(input, *num_args - 1, tools);
	if (allocated == 1)
	{
		i = 0;
		while (input[i])
			free(input[i++]);
		free(input);
	}
}
