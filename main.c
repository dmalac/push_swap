/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 16:41:39 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/07 17:38:10 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "main.h"
#include "prototypes_shared.h"
#include "libft/ft_printf.h"

void	check_leaks();	// delete

static void	erase_tools(t_tools **tools)
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

void	call_error(t_tools *tools)
{
	erase_tools(&tools);
	ft_printf("Error\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	t_tools	*tools;
	int		sorted;

	// atexit(check_leaks);	// delete
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
