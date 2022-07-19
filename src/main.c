/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 16:41:39 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/19 11:40:05 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/main.h"
#include <unistd.h>
#include "../include/prototypes_shared.h"

static void	erase_tools(t_tools **tools)
{
	size_t	i;

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

void	call_error(t_tools *tools)
{
	erase_tools(&tools);
	write(2, "Error\n", 6);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_tools	*tools;
	int		sorted;

	if (argc < 2)
		exit(0);
	tools = initialize();
	process_input(argv, &argc, tools);
	tools->tranches = how_many_tranches(argc - 1);
	sorted = is_sorted(tools->a);
	if (sorted < 1 && argc <= 7)
		sort_small_stack(tools);
	else if (sorted < 1 && argc > 7)
		sort_large_stack(tools);
	erase_tools(&tools);
	return (0);
}
