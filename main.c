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

void	erase_tools(t_tools **tools)
{
	int	i;

	i = 0;
	if (*tools)
	{
		if ((*tools)->instruction)
		{
			while (i <= RRR)
			{
				if ((*tools)->instruction[i])
					free((*tools)->instruction[i++]);
			}
			free((*tools)->instruction);
		}
		lst_erase(&(*tools)->a);
		lst_erase(&(*tools)->b);
		free(*tools);
	}
}

int	check_instructions(char **instruction)
{
	int	i;

	i = 0;
	while (i <= RRR)
	{
		if (!instruction[i++])
			return (0);
	}
	return (1);
}

static void	fill_instructions(t_tools *tools)
{
	if (tools->instruction)
	{
		tools->instruction[PX] = ft_strdup("p");
		tools->instruction[SX] = ft_strdup("s");
		tools->instruction[SS] = ft_strdup("ss");
		tools->instruction[RX] = ft_strdup("r");
		tools->instruction[RR] = ft_strdup("r");
		tools->instruction[RRX] = ft_strdup("rr");
		tools->instruction[RRR] = ft_strdup("rr");
		tools->instruction[7] = NULL;
	}
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
	fill_instructions(tools);
	if (!tools->instruction || check_instructions(tools->instruction) == 0)
	{
		erase_tools(&tools);
		call_error();
	}
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

	// atexit(check_leaks);	// delete
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
	erase_tools(&tools);
	return (0);
}
