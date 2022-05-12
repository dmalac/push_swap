/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 16:41:39 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/12 18:31:17 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include "libft/libft.h"
#include "list_operations.h"	// to be deleted after testing
#include "actions.h" // to be deleted after testing

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
	lst_print(a);	// to be removed before submitting
	
	//sort(&a, &b, is_sorted) --> will create array of functions
	
	// if (sorted < 0)
	// 	ft_printf("the list is reverse sorted\n");
	if (argc <= 7)
		sort_small_stack(&a, &b);
	// else
	// 	sort_large_stack(a, b);
	// /* TO BE DELETED */
	// ft_printf("Before swapping: (%d items)\n", lst_size(a));
	// lst_print(a);	// to be removed before submitting
	// a = swap(a);
	// ft_printf("After swapping: (%d items)\n", lst_size(a));
	// a = push(&b, &a);
	// a = push(&b, &a);
	// a = push(&b, &a);
	// ft_printf("After pushing:\nA (%d items)\n", lst_size(a));
	lst_print(a);	// to be removed before submitting
	// ft_printf("B (%d items)\n", lst_size(b));
	// lst_print(b);	// to be removed before submitting
	// b = rev_rotate(b);
	// ft_printf("B after rev-rotating (%d items)\n", lst_size(b));
	// lst_print(b);	// to be removed before submitting
	lst_erase(&a);
	lst_erase(&b);
	return (0);
}
