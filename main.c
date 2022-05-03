/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 16:41:39 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/03 18:10:03 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include "libft/libft.h"

void	call_error(void)
{
	ft_printf("Error\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	t_list	*a;

	if (argc < 2)
		exit(0);
	a = NULL;
	process_input(argv, &a);
	if (no_doubles(a) == 0)
		call_error();

	ft_printf("All good\n");
	return (0);
}