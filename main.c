/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 16:41:39 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/19 20:13:17 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include "libft/libft.h"
// #include "list_operations.h"	// to be deleted after testing
// #include "actions.h" // to be deleted after testing

void	call_error(void)
{
	ft_printf("Error\n");
	exit(0);
}

void	prnt_array(char **array)	// TO BE DELETED
{
	int	i;

	i = 0;
	ft_printf(">> array: ");
	while (array[i])
		ft_printf("%s, ", array[i++]);
	ft_printf("\n");
}

int	count_input(char **array)
{
	int	count;

	count = 0;
	while (array[count])
		count++;
	return (count + 1);
}

int	process_input(char **input, int num_args, t_list **lst)
{
	int		sorted;
	int		allocated;

	allocated = 0;
	if (num_args == 2)
	{
		input = ft_split(input[1], ' ');
		allocated = 1;
		num_args = count_input(input);
	}
	else
		input = input + 1;
	// prnt_array(input);
	check_input(input, num_args - 1);
	create_lnkd_lst(input, num_args - 1, lst);
	// lst_print(*lst, 'A');
	if (allocated == 1)
		free(input);
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
	int		sorted;

	// prnt_array(argv);
	if (argc < 2)
		exit(0);
	a = NULL;
	b = NULL;
	sorted = process_input(argv, argc, &a); // 0: not, -1: reverse sorted
	lst_print(a, 'A');	// to be removed before submitting
	// if (sorted < 0)
	// 	POSSIBLY MAKE STH FOR REVERSING
	if (argc <= 7)
		sort_small_stack(&a, &b);
	// else
	// 	sort_large_stack(a, b);
	lst_print(a, 'A');	// to be removed before submitting
	lst_print(b, 'B');	// to be removed before submitting
	lst_erase(&a);
	lst_erase(&b);
	return (0);
}
