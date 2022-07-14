/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   line_processing_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 15:57:25 by dmalacov      #+#    #+#                 */
/*   Updated: 2022/07/14 16:38:32 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"
#include "prototypes_shared.h"
#include "libft/libft.h"
#include <stdlib.h>

static void	perform_action(t_checker_tools *tools, int action_code, char stack)
{
	if (action_code == PA)
		push(&tools->a, &tools->b);
	else if (action_code == PB)
		push(&tools->b, &tools->a);
	else
	{
		if (stack != 'b')
			tools->action[action_code](&tools->a);
		if (stack != 'a')
			tools->action[action_code](&tools->b);
	}
}

static void	process_line(char *line, t_checker_tools **tools)
{
	char	stack;
	size_t	len;
	int		action_code;

	len = ft_strlen(line);
	stack = line[len - 2];
	action_code = is_push(line);
	if (action_code < 0)
		action_code = is_swap(line);
	if (action_code < 0)
		action_code = is_rotate(line);
	if (action_code < 0)
		call_error(*tools);
	perform_action(*tools, action_code, stack);
}

void	read_follow_instructions(t_checker_tools **tools)
{
	size_t	counter;
	char	*line;

	line = NULL;
	counter = 0;
	while (line || counter++ == 0)
	{
		line = get_next_line(0);
		if (line)
		{
			process_line(line, tools);
			free(line);
		}
	}
}
