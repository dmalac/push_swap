/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_processing.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 17:37:05 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/11 14:05:06 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "main.h"
#include "prototypes_shared.h"
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
	int	allocated;
	int	i;
	int	result;

	allocated = 0;
	i = 0;
	if (*num_args == 2 && only_digits(input[1]) == 0)
	{
		input = ft_split(input[1], ' ');
		if (!input || !input[i])
			call_error(tools);
		allocated = 1;
		*num_args = count_input(input);
	}
	else
		input = input + 1;
	check_input(input, *num_args - 1, tools);
	result = create_lnkd_lst(input, *num_args - 1, &tools->a);
	if (result < 0)
		call_error(tools);
	if (allocated == 1)
	{
		while (input[i])
			free(input[i++]);
		free(input);
	}
}
