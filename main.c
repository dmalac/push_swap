/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 16:41:39 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/04 18:14:52 by dmalacov      ########   odam.nl         */
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
	int		*input;

	if (argc < 2)
		exit(0);
	a = NULL;
	input = check_input(argv, argc - 1);
	process_input(input, argc - 1, &a);
	lst_print(a);
	ft_printf("All good\n");
	return (0);
}
