/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 16:41:39 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/05/25 17:26:22 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include "libft/libft.h"
#include "list_operations.h"
#include "actions.h" 

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

t_tools	*initialize(void)
{
	t_tools	*tools;

	tools = malloc(sizeof(t_tools));
	if (!tools)
		call_error();
	tools->a = NULL;
	tools->b = NULL;
	tools->action[SX] = swap;
	tools->action[SS] = swap;
	tools->action[RX] = rotate;
	tools->action[RR] = rotate;
	tools->action[RRX] = rev_rotate;
	tools->action[RRR] = rev_rotate;
	tools->instruction = malloc(sizeof(char *) * 8);
	tools->instruction[PX] = malloc(sizeof(char) * 16);
	if (!tools->instruction)
		call_error();
	tools->instruction[PX] = "p\0s\0s\0r\0r\0rr\0rr\0";
	tools->instruction[SX] = tools->instruction[PX] + 2;
	tools->instruction[SS] = tools->instruction[SX] + 2;
	tools->instruction[RX] = tools->instruction[SS] + 2;
	tools->instruction[RR] = tools->instruction[RX] + 2;
	tools->instruction[RRX] = tools->instruction[RR] + 2;
	tools->instruction[RRR] = tools->instruction[RRX] + 3;
	tools->instruction[7] = NULL;
	return (tools);
}

int	main(int argc, char **argv)
{
	t_tools	*tools;
	int		sorted;
	
	// prnt_array(argv);
	tools = initialize();
	if (argc < 2)
		exit(0);
	sorted = process_input(argv, argc, &tools->a); // 0: not, -1: reverse sorted
	lst_print(tools->a, 'A');	// to be removed before submitting
	// if (sorted < 0)
	// 	POSSIBLY MAKE STH FOR REVERSING
	if (argc <= 7)
		sort_small_stack(tools);	// SEE IF THIS DOESN'T CAUSE PROBLEMS
	// else
	// 	sort_large_stack(a, b);
	lst_print(tools->a, 'A');	// to be removed before submitting
	lst_print(tools->b, 'B');	// to be removed before submitting
	lst_erase(&tools->a);
	lst_erase(&tools->b);
	free(tools->instruction[PX]);
	free(tools->instruction);
	free(tools);
	return (0);
}
