/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_processing.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 17:37:05 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/03 18:50:39 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "main.h"

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

int	no_doubles(t_list *a)
{
	if (a == NULL)		// this is nonsense
		return (1);
	return (1);
}

void	process_input(char **arg, t_list **a)
{
	int		i;

	i = 1;
	while (arg[i] != NULL)
	{
		if (only_digits(arg[i]) == 0)
			call_error();
		/* 
		2. is_int
		3. atoi arg[i]
		4. create new node
		 */
		i++;
	}
	if (a != NULL)
		i = 0;
}