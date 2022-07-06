/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/16 15:41:12 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/06 19:05:58 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "main_bonus.h"
#include "libft/get_next_line.h"
#include "libft/libft.h"

void	erase_tools(t_tools **tools)
{
	int	i;

	i = 0;
	if (*tools)
	{
		// if ((*tools)->instruction)
		// {
		// 	while (i <= RRR)
		// 	{
		// 		if ((*tools)->instruction[i])
		// 			free((*tools)->instruction[i++]);
		// 	}
		// 	free((*tools)->instruction);
		// }
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
	// int		sorted;
	char	*line;
	int		counter;

	if (argc < 2)
		exit(0);
	tools = initialize();
	process_input(argv, &argc, tools);
	// sorted =  is_sorted(tools->a);

	lst_print(tools->a, 'A');

	line = NULL;
	counter = 0;
	while (line || counter++ == 0)
	{
		if (line)
			free(line);
		line = get_next_line(0);
		if (line)
			process_line(line, tools);
	}
	free(line);
	
	// if (sorted == 1)	// if stack A is sorted
	// 	ft_printf("OK\n");
	// else
	// 	ft_printf("KO\n");
	return (0);
}
