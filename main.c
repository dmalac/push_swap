/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 16:41:39 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/06/30 16:24:33 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "main.h"
#include "libft/libft.h"
#include "list_manipulation.h"
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

static void	fill_instructions(t_tools *tools)
{
	tools->instruction[PX] = "p\0s\0s\0r\0r\0rr\0rr\0";
	tools->instruction[SX] = tools->instruction[PX] + 2;
	tools->instruction[SS] = tools->instruction[SX] + 2;
	tools->instruction[RX] = tools->instruction[SS] + 2;
	tools->instruction[RR] = tools->instruction[RX] + 2;
	tools->instruction[RRX] = tools->instruction[RR] + 2;
	tools->instruction[RRR] = tools->instruction[RRX] + 3;
	tools->instruction[7] = NULL;
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
	fill_instructions(tools);
	return (tools);
}

int	how_many_tranches(int num_args)
{
	if (num_args < 60)
		return (3);
	else if (num_args >= 60 && num_args < 250)
		return (7);
	else
		return (13);
}

void	check_leaks()		// DELETE
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	t_tools	*tools;
	int		sorted;

	atexit(check_leaks);	// delete
	tools = initialize();
	if (argc < 2)
		exit(0);
	process_input(argv, &argc, &tools->a);
	// lst_print(tools->a, 'A');	// to be removed before submitting
	tools->tranches = how_many_tranches(argc - 1);
	sorted = is_sorted(tools->a);
	if (sorted < 1 && argc <= 7)
		sort_small_stack(tools);
	else if (sorted < 1 && argc > 7)
		sort_large_stack(tools);
	// lst_print(tools->a, 'A');	// to be removed before submitting
	// lst_print(tools->b, 'B');	// to be removed before submitting
	lst_erase(&tools->a);
	lst_erase(&tools->b);
	free(tools->instruction[PX]);
	free(tools->instruction);
	free(tools);
	return (0);
}
