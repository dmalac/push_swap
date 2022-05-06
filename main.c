/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 16:41:39 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/06 13:11:23 by dmalacov      ########   odam.nl         */
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

void	process_input(char **input, int num_args, t_list **lst)
{
	check_input(input, num_args);
	create_lnkd_lst(input, num_args, lst);
	if (doubles(*lst, num_args - 1) == 1)
		call_error();
}

int	main(int argc, char **argv)
{
	t_list	*a;

	if (argc < 2)
		exit(0);
	a = NULL;
	process_input(argv, argc, &a);
	lst_print(a);	// to be removed before submitting
	return (0);
}
