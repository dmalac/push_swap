/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   line_processing_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:57:25 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/06 18:58:23 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"
#include "libft/ft_printf.h"	// delete

static void	perform_action(t_tools *tools, int action_code, char stack)
{
	if (action_code == PA)
	{
		ft_printf("I push from B to A\n");
		push(&tools->a, &tools->b);
	}
	else if (action_code == PB)
	{
		ft_printf("I push from A to B\n");
		push(&tools->b, &tools->a);
	}
	else 
	{
		ft_printf("stack is %c\n", stack);
		if (stack != 'b')
		{
			ft_printf("I swap or rotate A\n");
			tools->action[action_code](&tools->a);
		}
		if (stack != 'a')
		{
			ft_printf("I swap or rotate B\n");
			tools->action[action_code](&tools->b);
		}
	}
}

void	process_line(char *line, t_tools *tools)
{
	char	stack;
	int		len;
	int		action_code;
	
	len = ft_strlen(line);
	stack = line[len - 2];
	action_code = is_push(line);
	if (action_code < 0)
		action_code = is_swap(line);
	if (action_code < 0)
		action_code = is_rotate(line);
	if (action_code < 0)
		call_error(tools);
	else
		perform_action(tools, action_code, stack);
}
