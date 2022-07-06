/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialisations.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/05 15:54:11 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/06 17:49:51 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list_manipulation.h"
#include "main.h"
// #include "actions.h"
#include "libft/libft.h"
#include <stdlib.h>

static int	check_instructions(char **instruction)
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
		call_error(tools);
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
		call_error(tools);
	return (tools);
}
