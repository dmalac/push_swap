/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/16 15:41:12 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/06/28 18:26:54 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "main_bonus.h"

int	main(int argc, char **argv)
{
	t_tools	*tools;
	int		sorted;

	tools = initialize();
	if (argc < 2)
		exit(0);
	sorted = process_input(argv, &argc, &tools->a);
	
	// GNL read input until NULL (what if nothing?)
	// process read line with actions (or Error & exit)
	
	if (sorted == 1)	// if stack A is sorted
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
