/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 16:41:39 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/11 13:00:56 by dmalacov      ########   odam.nl         */
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

int	process_input(char **input, int num_args, t_list **lst)
{
	int	sorted;
	
	check_input(input, num_args);
	if (num_args == 2)
		exit(0);
	create_lnkd_lst(input, num_args, lst);
	if (doubles(*lst, num_args - 1) == 1)
		call_error();
	sorted = is_sorted(*lst);
	if (sorted == 1)
		exit(0);
	return (sorted);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int	sorted;

	if (argc < 2)
		exit(0);
	a = NULL;
	b = NULL;
	sorted = process_input(argv, argc, &a); // 0: not, -1: reverse sorted
	if (sorted < 0)
		ft_printf("the list is reverse sorted\n");
	// if (argc <= 7)
	// 	small_stack(a, b);
	// else
	// 	large_stack(a, b);

	lst_print(a);	// to be removed before submitting
	
	// delete and free the stacks
	return (0);
}
