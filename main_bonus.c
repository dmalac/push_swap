/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/16 15:41:12 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/13 17:31:08 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"
#include <unistd.h>
#include "prototypes_shared.h"
#include "libft/ft_printf.h"
#include "libft/get_next_line.h"
#include "libft/libft.h"

void	erase_tools(t_checker_tools **tools)
{
	int	i;

	i = 0;
	if (*tools)
	{
		lst_erase(&(*tools)->a);
		lst_erase(&(*tools)->b);
		free(*tools);
	}
}

void	call_error(t_checker_tools *tools)
{
	erase_tools(&tools);
	write(2, "Error\n", 6);
	exit(0);
}

t_checker_tools	*initialize(void)
{
	t_checker_tools	*tools;

	tools = malloc(sizeof(t_checker_tools));
	if (!tools)
		call_error(tools);
	tools->a = NULL;
	tools->b = NULL;
	tools->action[SA] = swap;
	tools->action[SB] = swap;
	tools->action[SS] = swap;
	tools->action[RA] = rotate;
	tools->action[RB] = rotate;
	tools->action[RR] = rotate;
	tools->action[RRA] = rev_rotate;
	tools->action[RRB] = rev_rotate;
	tools->action[RRR] = rev_rotate;
	return (tools);
}

void	check_leaks()		// DELETE
{
	system("leaks checker");
}

int	main(int argc, char **argv)
{
	t_checker_tools	*tools;
	int				sorted;
	int				counter;

	// atexit(check_leaks);	// delete
	if (argc < 2)
		exit(0);
	tools = initialize();
	process_input(argv, &argc, tools);
	// ft_printf("size of tools* is %d, tools is %d, t_list is %d\n", sizeof(tools), sizeof(*tools), sizeof(*tools->a));
	// lst_print(tools->a, 'A');
	// lst_print(tools->b, 'B');
	counter = read_follow_instructions(&tools);
	sorted =  is_sorted(tools->a);
	if (sorted == 1 && !tools->b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_printf("There were %d moves.\n", counter);
	erase_tools(&tools);
	return (0);
}
